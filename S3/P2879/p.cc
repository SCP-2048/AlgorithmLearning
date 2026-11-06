#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, I, h, r;
    cin >> n >> I >> h >> r;
    vector<vector<int>> info(r, vector<int>(2));
    vector<int> cows(n + 1);
    cows[I] = h;
    for (auto &x : info){
        cin >> x[0] >> x[1];
    }
    vector<vector<int>> differs(n + 1, {0, 0});
    set<pair<int, int>> seen;
    for(auto x: info){
        int a = x[0], b = x[1];
        if(a > b) swap(a, b);
        if(b - a <= 1) continue;
        if(!seen.insert({a, b}).second) continue;
        // if(differs[a][1] >= 0 || differs[b][0] >= 0){
        differs[a][1]--; differs[a + 1][0]++;
        differs[b][0]--; differs[b - 1][1]++;
        // }
    }
    for(int i = I - 1; i > 0; i--){
        cows[i] = cows[i + 1] + differs[i + 1][0];
    }
    for(int i = I + 1; i <= n; i++){
        cows[i] = cows[i - 1] + differs[i - 1][1];
    }
    for(int i = 1; i <= n; i++){
        cout << cows[i] << '\n';
    }

    return 0;
}
