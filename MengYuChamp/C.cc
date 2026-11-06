#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> graph;

void djs(const graph &g, int u, vector<bool> &black){
    black[u] = true;
    for(auto v : g[u]){
        if(black[v])
            continue;
        djs(g, v, black);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    graph g(n + 1);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        g[y].push_back(x);
    }
    // vector<vector<bool>> reach(n + 1, vector<bool>(n+1, false));
    // for(int i = 1; i <= n; i++){
    //     djs(g, i, i, reach);
    // }
    // for(int u = 1; u <= n; u++){
    //     for(int v = 1; v <= n; v++)
    //         cout << reach[u][v] << ' ';
    //     cout << '\n';
    // }
    int q; cin >> q;
    vector<bool> black(n + 1, false);
    for(int i = 0; i < q; i++){
        int op, v; cin >> op >> v;
        if(op == 1){
            djs(g, v, black);
        }
        if(op == 2){
            cout << (black[v] ? "Yes" : "No") <<'\n';
        }
    }

    return 0;
}
