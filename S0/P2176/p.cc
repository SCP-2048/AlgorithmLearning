#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<unordered_map<int, int>> graph; //第一个为起点，第二个为终点

pair<int, vector<int>> dijkstra(const graph& g, int n){
    vector<int> dist(n + 1, INT_MAX), pre(n + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq; //{distance, point}
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w] : g[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                pq.push({dist[v], v});
                pre[v] = u;
            }
        }
    }
    return {dist[n], pre};
}

int main(){
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    graph g(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, l;
        cin >> a >> b >> l;
        g[a][b] = l;
        g[b][a] = l;
    }
    auto [dist_orginal, pre] = dijkstra(g, n);
    int needle = n, res = 0;
    while(needle != 1){
        int carry = g[pre[needle]][needle];
        g[pre[needle]][needle] *= 2;
        g[needle][pre[needle]] *= 2;
        int dist = dijkstra(g, n).first;
        res = max(res, dist - dist_orginal);
        g[pre[needle]][needle] = carry;
        needle = pre[needle];
    }
    cout << res;

    return 0;
}
