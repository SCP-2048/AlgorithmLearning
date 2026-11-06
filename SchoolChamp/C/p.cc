#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int n, c, k; cin >> n >> c>>k;
    vector<int> a(n);
    for(auto &x:a){
        cin >> x;
    }
    sort(a.begin(), a.end());
    int res = 0, first = a[0], num = 0;
    for(auto x : a){
        if(x > first + k){
            num = 1;
            res++;
            first = x;
        }
        else{
            num++;
            if(num > c){
                res++;
                num = 1;
                first = x;
            }
        }
    }
    cout << res<<'\n';

    return 0;
}
