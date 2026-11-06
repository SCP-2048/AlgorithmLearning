#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int m; cin >> m;
    int left = 1, right = 4, sum = 10;
    while(right - left >= 1){
        if(sum < m){
            right++;
            sum += right;
        }
        if(sum > m){
            sum -= left;
            left++;
        }
        if(sum == m){
            cout << left << ' ' << right << '\n';
            right++;
            sum += right;
        }
    }

    return 0;
}
