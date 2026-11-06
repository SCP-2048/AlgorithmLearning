#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> indegree(n + 1, 0), len(n + 1, 0);
    vector<vector<int>> g(n + 1);
    deque<int> q;
    q.push_back(0);
    for(int i = 1; i <= n; i++){
        cin >> len[i] >> len[i];
        while(1){
            int x; cin >> x;
            g[x].push_back(i);
            indegree[i]++;
            if(x == 0){
                break;
            }
        }
    }

    vector<int> finish(n + 1, 0);
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(int v : g[u]){
            finish[v] = max(finish[v], finish[u] + len[v]);
            if(--indegree[v] == 0){
                q.push_back(v);

            }
        }
        
    }
    
    int res = 0;
    for(auto x : finish){
        res = max(x, res);
    }
    cout << res;

    return 0;
}
