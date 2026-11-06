#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct node{
    int weight, package;
    bool operator>(const node& other) const{
        return tie(package, weight) > tie(other.package, other.weight);
    }
    bool operator<(const node& other) const{
        return tie(package, weight) < tie(other.package, other.weight);
    }
    bool operator==(const node& other) const{
        return tie(package, weight) == tie(other.package, other.weight);
    }
    node add(int w, int V) const{
        node res = *this;
        if(res.weight + w > V){
            res.package++;
            res.weight = w;
        }
        else{
            res.weight += w;
        }
        return res;
    }
};
vector<node> solve(const vector<vector<int>> &g, int s, int n, int V){
    vector<node> dist(n + 1, {INT_MAX, INT_MAX});
    priority_queue<pair<node, int>, 
    vector<pair<node, int>>, 
    greater<pair<node, int>>> pq;
    dist[s].weight = 0;
    dist[s].package = 1;
    pq.push({dist[s], s}); //{distance, point}


    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop(); // d is a node
        if(d > dist[u])
            continue;
        for(int v = 1; v <= n; v++){
            int w = g[u][v];
            if(w == INT_MAX)
                continue;
            node carry = d.add(w, V);
            if(carry < dist[v]){
                dist[v] = carry;
                pq.push({dist[v], v}); //{node, the index of the point}

            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, m, v, t;
    cin >> n >> m >> v >> t;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, INT_MAX));
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        if(w < g[x][y]){
            g[x][y] = w;
            g[y][x] = w;
        }
    }
    vector<node> res = solve(g, t, n, v);
    for(int i = 1; i <= n; i++){
        if(res[i].package == INT_MAX){
            cout << -1 << ' ';
            continue;
        }
        cout << res[i].package << ' ';
        // cout << dist[i] << ' ';
    }
    cout << '\n';

    return 0;
}
