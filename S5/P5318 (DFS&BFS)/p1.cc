#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> graph;

void dfs(const graph &g, int u, vector<bool> &visited){
    visited[u] = true;
    cout << u << ' ';
    for(int v : g[u]){
        if(visited[v])
            continue;
        dfs(g, v, visited);
    } 
    return;
}

void bfs(graph &g, int s, vector<bool> &visited){
    visited[s] = true;
    deque<int> nodes;
    nodes.push_back(s);
    while(!nodes.empty()){
        int u = nodes.front();
        nodes.pop_front();
        cout << u << ' ';
        for(int v : g[u]){
            if(visited[v])
                continue;
            visited[v] = true;
            nodes.push_back(v);
        } 
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    graph g(n + 1);
    for(int i = 0; i < m; i ++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }
    for(auto &u : g){
        sort(u.begin(), u.end());
    }

    vector<bool> visited(n + 1, false);

    dfs(g, 1, visited);
    cout << '\n';

    for(auto x : visited) x = false;

    bfs(g, 1, visited);

    return 0;
}
