#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &check, const int& k, int n){
    // auto get = [&](int x){
        // return 0 <= x && x <= 5000 
    // }
    int needle = 0;
    while(needle < n){
        // cout << v0 << ' ' << v1 << '\n';
        int v0 = check[needle], v1 = (k - needle >= 0 && k - needle <= 5000) ? check[k - needle] : 0;
        if(v0 + v1 == 1){
            if(needle * 2 > k && k - needle >= 0){
                return needle;
            }
        }
        else if(v0 + v1 == 0){
            return needle;
        }
        needle++;
    }
    return needle;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        unordered_map<int, int> um;
        vector<int> check(5002, 0);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(x <= 5000){
                check[x]++;
            }
            um[x]++;
        }
        int q, res = 0; cin >> q;
        unordered_map<int, int> memo;
        for(int i = 0; i < q; i++){
            int k, carry; cin >> k;
            if(memo.count(k)){
                carry = memo[k];
            }
            else{
                carry = solve(check, k, n);
                memo[k] = carry;
            }
            // printf("%d %d\n",k, carry);
            // cout << "k:" << k << "res:" << carry << '\n';
            res = res ^ carry;
        }
         cout << res << '\n';
    }

    return 0;
}
