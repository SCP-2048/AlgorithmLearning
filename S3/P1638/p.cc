#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    vector<int> line(n);
    pair<int, int> res;
    int num_artists = 0;
    for(auto &x : line){
        cin >> x;
    }
    int left = 0, right = 0;
    while(1){
        int artist = line[right];
        // cout << artist << '\n';
        if(cnt[artist] == 0){
            num_artists++;
        }
        cnt[artist]++;
        if(num_artists == m)
            break;
        if(++right == n){
            cout << 0 << '\n';
            return 0;
        }
    }
    int length = right - left + 1;
    res = {left + 1, right + 1};
    while(right < n){
        int loss = line[left];
        cnt[loss]--;
        left++;
        if(cnt[loss] == 0){
            // cout << right << "->" << right+1 << '\n';
            right++;
            while(1){
                if(right == n){
                    cout << res.first << ' ' << res.second << '\n';
                    return 0;
                }
                cnt[line[right]]++;
                if(line[right] == loss)
                    break;
                // cout << right << "->" << right+1 << '\n';
                right++;
            }
        }
        if(right - left + 1 < length){
            length = right - left + 1;
            res = {left + 1, right + 1};
        }
    }

    return 0;
}
