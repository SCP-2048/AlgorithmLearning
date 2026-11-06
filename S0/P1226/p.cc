#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, p;
    cin >> a >> b >> p;
    int expnt = b;
    long long power = a;
    long long res = 1;
    while(expnt){
        if(expnt & 1){
            res *= power;
            res = res % p;
        }
        power *= power;
        power  = power % p;
        expnt >>= 1;
    }   
    printf("%d^%d mod %d=%d", a, b, p, res);
    return 0;
}
