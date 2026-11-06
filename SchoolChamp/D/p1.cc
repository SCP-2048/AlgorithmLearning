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
        int length_1 = 0;
        while(n){
            if(n & 1){ //odd
                res += (length_1 == 0) ? 1 : 0;
                length_1++;                
            }
            else{ //even
                res += (length_1 == 1) ? 0 : 1;
                length_1 = 0;
            }
            n = n >> 1;
        }
        cout << res << '\n';
    }

    return 0;
}
