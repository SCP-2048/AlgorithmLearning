#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int L[n], R[n];
    for(int i = 0; i < n; i++){
        L[i] = (i == 0) ? n - 1 : i - 1;
        R[i] = (i == n - 1) ? 0 : i + 1;
    }
    int ndl = 0, cnt = 0, clock = 0;
    while(cnt < n){
        ndl = R[ndl];
        clock++;
        if (clock == m){
            if(ndl == 0)
                cout << n << ' ';
            else
                cout << ndl << ' ';
            clock = 0;
            R[L[ndl]] = R[ndl];
            L[R[ndl]] = L[ndl];
            cnt++;
        }
    }
    cout << endl;
    return 0;
}
