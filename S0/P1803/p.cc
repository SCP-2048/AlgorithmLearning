#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r};
    }
    sort(ranges.begin(), ranges.end(),
    [](const pii &a, const pii &b){return a.second < b.second;});

    int time = 0, needle = 0, res = 0; //n1代表时间，n2代表时段的次数
    for(auto range : ranges){
        if(range.first >= time){
            time = range.second;
            res++;
            // cout << range.first << range.second << '\n';
        }
    }
    cout << res << '\n';

    return 0;
}
