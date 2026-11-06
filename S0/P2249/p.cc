#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(!binary_search(a.begin(), a.end(), x)){
            cout << -1 << ' ';
            continue;
        }
        auto it = lower_bound(a.begin(), a.end(), x);
        cout << it - a.begin() + 1 << ' ';
    }
    return 0;
}
