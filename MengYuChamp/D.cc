#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long res = 0;
    for(int i = 0; i < 3; i++){
        long long x; cin >> x;
        res += x;
    }
    cout << res << '\n';

    return 0;
}
