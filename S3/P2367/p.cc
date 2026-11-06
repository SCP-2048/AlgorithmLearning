#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p, res = INT_MAX, pre = 0;
    cin >> n >> p;
    vector<int> differs(n + 1);
    differs[0] = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        differs[i] = x - pre;
        pre = x;
    }
    for(int i = 0; i < p; i++){
        int x, y, z;
        cin >> x >> y >> z;
        differs[x] += z;
        if(y != n)
            differs[y + 1] -= z;
    }
    int grade = 0;
    for(int i = 1; i <= n; i++){
        grade += differs[i];
        res = min(grade, res);
    }
    cout << res << '\n';
    return 0;
}
