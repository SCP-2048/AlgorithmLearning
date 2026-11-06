#include<bits/stdc++.h>
using namespace std;

int solve(const vector<int> &a, long long sum, int i, const int &n){
    if(i == n){
        return (sum == 0) ? 1 : 0;
    }
    return solve(a, sum + a[i], i + 1, n) + solve(a, sum - a[i], i + 1, n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    long long sum = a[0];
    long res = solve(a, sum, 1, n);
    cout << res << '\n';

    return 0;
}
