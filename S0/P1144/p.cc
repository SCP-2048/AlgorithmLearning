#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> graph;

vector<int> countWay(const graph &g, int n){
    vector<int> count(n + 1, 0);
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    count[1] = 1;
    pq.push({0, 1}); //{distance, point}
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] < d) continue;
        for(auto v : g[u]){
            if(d + 1 < dist[v]){
                dist[v] = d + 1;
                pq.push({dist[v], v});
                count[v] = count[u];
            }
            else if(d + 1 == dist[v]){
                count[v] = (count[v] + count[u]) % 100003;
            }
        }
    }
    return count;
}

int main(){
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    graph g(n + 1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> count = countWay(g, n);

    for(int i = 1; i <= n; i++){
        cout << count[i] << '\n';
    }

    return 0;
}
