#include<bits/stdc++.h>
using namespace std;

long long check(const vector<int> &a, int h){
    auto pos = upper_bound(a.begin(), a.end(), h);
    long long res = 0;
    for(auto it = pos; it != a.end(); it++){
        res += *it - h;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, m, maxmium = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
        maxmium = max(x, maxmium);
    }
    sort(a.begin(), a.end());
    int left = 0, right = maxmium, mid;
    while(left <= right){
        mid = left + (right - left) / 2;
        long long res = check(a, mid);
        // cout << mid << ' ' << res << '\n';
        if(res == m){
            cout << mid << '\n';
            return 0;
        }
        else if(res < m){
            right = mid - 1;
        }
        else if(res > m){
            left = mid + 1;
        }
    }
    // cout << left << ' ' << right << '\n';
    cout << min(left, right) << '\n';

    return 0;
}
