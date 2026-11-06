#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int n, k, p;
    cin >> n;
    int L[n + 1], R[n + 1];
    bool removed[n + 1] = {};
    L[0] = 1; R[0] = 1;
    L[1] = 0; R[1] = 0;

    for (int i = 2; i <= n; i++){
        cin >> k >> p; //i是被插入的，k是坐标
        if(p == 0){
            L[i] = L[k];
            R[i] = k;
            R[L[k]] = i;            
            L[k] = i;
        }
        else if(p == 1){
            L[i] = k;
            R[i] = R[k];
            L[R[k]] = i;
            R[k] = i;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
       cin >> k;
       removed[k] = true;
    }
    for(int i = R[0]; i != 0; i = R[i]){
        if(!removed[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}