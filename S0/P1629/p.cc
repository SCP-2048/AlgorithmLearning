#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<pair<int, int>>> graph;

vector<int> dijstra(const graph &g, int n){
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq; //{distance, point}
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w] : g[u]){
            if(w + d < dist[v]){
                dist[v] = w + d;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    graph g1(n + 1), g2(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g1[u].push_back({v, w});
        g2[v].push_back({u, w});
    }
    vector<int> dist1 = dijstra(g1, n);
    vector<int> dist2 = dijstra(g2, n);

    long long res = 0;
    for(int i = 1; i <= n; i++){
        res += (dist1[i] + dist2[i]);
    }
    cout << res << '\n';

    return 0;
}
