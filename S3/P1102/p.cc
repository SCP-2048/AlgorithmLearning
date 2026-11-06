#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, c; cin >> n >> c;
    unordered_map<int, int> cnt;
    cnt.reserve(n * 2);
    vector<int> a(n);
    for(auto &x:a){
        cin >> x;
        cnt[x]++;
    }
    long long res = 0;
    for(auto x : a){
        res += cnt[x + c];
    }
    cout << res << '\n';

    return 0;
}
