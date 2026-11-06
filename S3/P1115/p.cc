#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    if(n == 0) return 0;
    vector<long> a(n + 1);
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    long res = LONG_MIN, bottom = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, a[i] - a[bottom]);
        if(a[i] < a[bottom]){
            bottom = i;
        }
    }
    cout << res << '\n';
    return 0;
}
