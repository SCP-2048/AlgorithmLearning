#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> weights(n);
    long long sum = 0;
    for(auto &weight:weights){
        cin >> weight;
        sum += weight;
    }
    if(sum % 2){
        cout << 0 <<'\n';
        return 0;
    }
    unordered_map<long long, int> dp;
    sum /= 2;
    dp.reserve(sum);
    dp[0] = 1;
    
    for(auto weight : weights){
        for(int i = sum; i >= weight; i--){
            dp[i] += dp[i - weight];
        }
        // for(auto x:dp) cout << x << ' ';
        // cout <<'\n';
    }
    
    cout << dp[sum] / 2 << '\n';

    return 0;
}
