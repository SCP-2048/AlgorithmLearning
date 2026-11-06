#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(const graph &g, int n, int s){
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>,  //{距离,点}
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for(auto [v, w] : g[u]){
            if(d + w < dist[v]){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    freopen("in.txt", "r", stdin);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int>>> g(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w}); 
        g[v].push_back({u, w});
    }
    vector<int> dist = dijkstra(g, n, s);
    cout << dist[t] << endl;

    return 0;
}
