#include<bits/stdc++.h>
using namespace std;

void djs(const vector<vector<int>> &g, int u, vector<int> &res, int s){
    if(res[u]==-1)
        res[u] = s;
    // cout << u<<' '<<s<<'\n';
    for(int v : g[u]){
        if(res[v] != -1)
            continue;
        djs(g, v, res, s);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        g[y].push_back(x);
    }
    // for(int i = 1; i <= n; i++){
    //     cout << i <<": ";
    //     for(int v:g[i])
    //         cout << v<<' ';
    //     cout << '\n';
    // }

    vector<int> res(n + 1, -1);
    for(int i = n; i > 0; i--){
        djs(g, i, res, i);
    }
    for(int i = 1; i <= n; i++){
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}
