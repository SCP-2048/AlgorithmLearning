#include<bits/stdc++.h>
using namespace std;
const long long m = 998244353;


long long quickPow(long long base, long long x){
    long long res = 1;
    while(x){
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
    long long a, b; cin >> a >> b;
    cout << quickPow(a, b);
    
    return 0;
}
