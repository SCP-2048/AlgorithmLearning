#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        long long n;
        cin >> n;
        int res = 0;
        while(n){
            if(n & 1){ //odd
                res++;
                if((n >> 1) & 1){ //next 1
                    n++;
                }
            }
            n = n >> 1;
        }
        cout << res << '\n';
    }

    return 0;
}
