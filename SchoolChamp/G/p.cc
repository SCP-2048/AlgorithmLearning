#include<bits/stdc++.h>
using namespace std;
const long long m = 998244353;

long long quickPow(long long base, long long x){
    long long res = 1;
    while(x > 0){
        if(x & 1){
            x--;
            res  = (res * base) % m;
        }
        else{
            base = (base * base) % m;
            x = x >> 1;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    long long front = 1;
    long long res = 0;
    long long k = quickPow(3, n - 2);
    for(int i = n - 2; i >= 0; i--){ //i是自由的符号的数量,也是3的指数
        long long k = quickPow(3, i);
        front = (front * a[n - 2 -i]) % m;
        res += (front * k * 2) % m;
    }
    front = (front * a[n - 1]) % m;
    res = (front + res) % m;
    cout << res;

    return 0;
}
