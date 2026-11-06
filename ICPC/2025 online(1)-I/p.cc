#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct node{
    unsigned int distance;
    int pos;
    int res;
};
struct compareNode{
    bool operator()(const node &x, const node &y) const{
        return x.distance > y.distance;
    }
};

vector<int> solve(const vector<vector<pii>> &g, int s, int n){
    vector<unsigned int> dist(n + 1, UINT_MAX);
    vector<int> weight(n + 1, 0), packages(n + 1, 0);
    priority_queue<node, vector<node>, compareNode> pq;
    pq.push({0, s}); //{distance, point}
    dist[s] = 0;
    while(!pq.empty()){
        auto [d, u, res] = pq.top(); pq.pop();
        if(d > dist[u])
            continue;
        for(auto [v, w] : g[u]){
            if(w + d < dist[v]){
                dist[v] = w + d;
                pq.push({dist[v], v});
            }
        }
    }
    return packages;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, m, v, t;
    cin >> n >> m >> v >> t;
    vector<vector<pii>> g(n + 1);
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    vector<int> res = solve(g, t, n);
    for(int i = 1; i <= n; i++){
        // if(dist[i] == UINT_MAX){
            // cout << -1 << ' ';
            // continue;
        // }
        // cout << dist[i] / v + 1 << ' ';
        // cout << dist[i] << ' ';
    }
    cout << '\n';

    return 0;
}
