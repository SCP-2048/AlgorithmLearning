#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, m; cin >> m >> n;
    vector<bool> cnt(1001, false);
    queue<int> q;
    int res = 0;
    for(int i = 0; i < n; i++){
        int x; cin >>x;
        if(cnt[x] == false){
            res++;
            q.push(x);
            cnt[x] = true;
            if(q.size() > m){
                int out = q.front();                
                q.pop();
                cnt[out] = false;
            }
        }
    }
    cout << res << '\n';
    return 0;
}
