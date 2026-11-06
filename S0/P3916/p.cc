#include<bits/stdc++.h>
using namespace std;

int find(const vector<vector<int>>& g, const int& u, const int& n){
    if(g[u].empty() || u == n){
        return u;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    return 0;
}
