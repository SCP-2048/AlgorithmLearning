#include<bits/stdc++.h>
using namespace std;

bool check(const vector<int> &a, int m, int dist, int n){
    cout << "check" << ' '<< dist<<'\n';
    int l = 0, r = 0;
    while (r++ < n + 1){
        if (a[r] - a[l] < dist)
        {
            if(m-- == 0)
                return false;
        }
        else{
            l = r;
        }
        // cout << l <<' '<< r <<' '<< m << '\n';
    }
    return true;
}

int main(){
    freopen("in.txt", "r", stdin);
    int length, n, m;
    cin >> length >> n >> m;
    vector<int> a(n + 2);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = 0; a[n + 1] = length;
    int l = 0, r = length;
    while(l < r){
        int mid = (l + r + 1) / 2;
        // printf("%d %d %d %d\n", l, mid, r, check(a, m, mid, n));
        if(check(a, m, mid, n)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << l << '\n';
    return 0;
}
