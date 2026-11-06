#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int t, m;
    cin >> t >> m;
    vector<pair<int, int>> peels(m);
    for(int i = 0; i < m; i++){
        cin >>  peels[i].first >> peels[i].second; //time, value
    }
    vector<int> arr(t + 1, 0);
    // for(int i = 0; i <= t; i++) cout << arr[i] << ' ';
    // cout << '\n';

    for(int i = 0; i < m; i++){
        for(int j = t; j >= 0; j--){
            if(peels[i].first > j)
                continue;
            arr[j] = max(arr[j], arr[j - peels[i].first] + peels[i].second);
            // cout << arr[j] << ' ';
        }
        // cout << '\n';
    }
    cout << arr[t] << '\n';

    return 0;
}