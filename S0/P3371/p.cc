#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>> &g, int n, int start){
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    //first为距离，second为点，数对的含义为某点到起点的距离
    pq.push({0, start});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] < d) continue;

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
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> g(n + 1); //g[u].second是u到g[u].first的距离
    

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w; //u->v,长度为w
        g[u].push_back({v, w});
    }

    vector<int> dist = dijkstra(g, n, s);
    for(int i = 1; i < n + 1; i++) cout << dist[i] << " ";

    return 0;
}
