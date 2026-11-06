#include<bits/stdc++.h>
using namespace std;

int solve(long long num, int cnt){
    if(num == 0)
        return cnt;
    while((num & 1) == 0)
    {
        num = num >> 1;
    }
    if(num == 1)
        return cnt+1;
    cnt++;
    // cout << num << ' ' << cnt<<'\n';
    return min( solve((num + 1) >> 1, cnt), solve(num >> 1, cnt) );
    // cout << num << ' ' << cnt<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        long long n;
        cin >> n;
        cout << solve(n, 0) << '\n';
    }

    return 0;
}
