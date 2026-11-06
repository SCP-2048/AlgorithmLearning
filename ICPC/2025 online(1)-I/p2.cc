#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

struct node {
    int weight, package;

    bool operator>(const node& other) const {
        return tie(package, weight) > tie(other.package, other.weight);
    }

    bool operator<(const node& other) const {
        return tie(package, weight) < tie(other.package, other.weight);
    }

    bool operator==(const node& other) const {
        return tie(package, weight) == tie(other.package, other.weight);
    }

    node add(int w, int V) const {
        node res = *this;
        if (res.weight + w > V) {
            res.package++;
            res.weight = w;
        } else {
            res.weight += w;
        }
        return res;
    }
};

vector<node> solve(const vector<vector<pii>>& g, int s, int n, int V) {
    vector<node> dist(n + 1, {INT_MAX, INT_MAX});
    priority_queue<
        pair<node, int>,
        vector<pair<node, int>>,
        greater<pair<node, int>>
    > pq;

    dist[s].weight = 0;
    dist[s].package = 1;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto [to, w] : g[u]) {
            node carry = d.add(w, V);
            if (carry < dist[to]) {
                dist[to] = carry;
                pq.push({carry, to});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, V, T;
    cin >> n >> m >> V >> T;

    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    vector<node> res = solve(g, T, n, V);
    for (int i = 1; i <= n; i++) {
        if (res[i].package == INT_MAX) {
            cout << -1;
        } else {
            cout << res[i].package;
        }

        cout << (i == n ? '\n' : ' ');
    }

    return 0;
}
