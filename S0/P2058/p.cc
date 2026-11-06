#include<bits/stdc++.h>
using namespace std;
struct ship{
    int t;
    unordered_map<int, int> passengers;
};
int main(){
    int n, k, x;
    cin >> n;
    vector<ship> ships(n);
    queue<ship> line;
    unordered_map<int, int> cnt;
    int ans = 0;

    for(int i = 0; i < n; i++){
        cin >> ships[i].t >> k;
        while(k--){
            cin >> x;
            ships[i].passengers[x]++;
        }

        line.push(ships[i]);
        for(auto &p : ships[i].passengers){
            if (cnt[p.first] == 0)
                ans++;
            cnt[p.first] += p.second;
        }
        while (line.front().t <= (ships[i].t - 86400)){
            for(auto &p : line.front().passengers){
                cnt[p.first] -= p.second;
                if (cnt[p.first] == 0)
                    ans--;
            }           
            line.pop();
        }
        /*for (const auto &p : cnt){
            if (p.second != 0)
                ans++;
        } */
        cout << ans << endl;

    }

    return 0;
}