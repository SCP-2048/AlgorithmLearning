#include<bits/stdc++.h>
using namespace std;

int solve(unordered_map<int, int> &check, const int& k, int n, int M){
    int needle = M;
    while(needle < n){
        auto it0 = check.find(needle), it1 = check.find(k - needle);
        int v0 = (it0 == check.end() ? 0 : it0 -> second), v1 = (it1 == check.end() ? 0 : it1 -> second);
        // cout << v0 << ' ' << v1 << '\n';
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
        unordered_map<int, int> check;
        check.reserve(n * 2);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            check[x]++;
        }
        int M = 0;
        while(M <= n && check.count(M) > 0){
            M++;
        }
        int q, res = 0; cin >> q;
        unordered_map<int, int> memo; memo.reserve(n * 2);
        for(int i = 0; i < q; i++){
            int k, carry; cin >> k;
            auto it = memo.find(k);
            if(it != memo.end()){
                carry = it -> second;
            }
            else if(k >= M && check.find(k - M) != check.end()){
                carry = solve(check, k, n, M);
                memo[k] = carry;
            }
            else{
                carry = M;
            }
            // printf("%d %d\n",k, carry);
            // cout << "k:" << k << "res:" << carry << '\n';
            res = res ^ carry;
        }
         cout << res << '\n';
    }

    return 0;
}
