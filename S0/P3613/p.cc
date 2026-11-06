#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q, i, j, k;
    cin >> n >> q;
    vector<map<int, int>> shelf(n + 1);
    for(int c = 0; c < q; c++){
        cin >> i;
        if(i == 1){
            cin >> i >> j >> k;
            shelf[i][j] = k;
        }
        else if(i == 2){
            cin >> i >> j;
            cout << shelf[i][j] << endl;
        }
    }
    return 0;
}