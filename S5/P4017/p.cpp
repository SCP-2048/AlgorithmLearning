#include<bits/stdc++.h>
using namespace std;
const int mo = 80112002;

void solve(const vector<vector<int>> &g, vector<int> &indegree, int n, deque<int> &q, vector<int> &cnt){
    int res = 0;
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        if(g[u].empty()){
            res = (res + cnt[u]) % mo;
        }
        for(auto v : g[u]){
            cnt[v] = (cnt[v] + cnt[u]) % mo;
            if(--indegree[v] == 0){
                q.push_back(v);
            }
        }
        
    }
    cout << res<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    unordered_set<int> start;
    for(int i = 1; i < n; i++) start.insert(i);
    vector<vector<int>> g(n + 1);
    vector<int> indegree(n + 1, 0);
    deque<int> q;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        indegree[v]++;
        start.erase(v);
    }

    vector<int> cnt(n + 1, 0);
    int res = 0;
    for(int s : start){
        cnt[s] = 1;
        q.push_back(s);
    }
    solve(g, indegree, n, q, cnt);

    return 0;
}
