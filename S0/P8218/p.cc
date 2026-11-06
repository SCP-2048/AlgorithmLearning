#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n;
    vector<int> sum(n);
    cin >> sum[0];
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        if(l == 1)
            cout << sum[r - 1] << '\n';
        else
            cout << sum[r - 1] - sum[l - 2] << '\n';
    }
    return 0;
}
