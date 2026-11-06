#include<bits/stdc++.h>
using namespace std;
int main(){
    int x, i = 0;
    long long ans = 0;
    while(cin >> x){
        i++;
        ans += x;
    }
    ans = ans << (i - 1);
    return ans;

}