#include<bits/stdc++.h>
using namespace std;

bool check(const vector<int> &logs, int l, int k){
    int cnt = 0;
    for(auto &log : logs){
        cnt += log / l;
    }
    return cnt >= k;
}

int main(){
    freopen("in.txt", "r", stdin);
    int n, k;
    long long sum = 0;
    cin >> n >> k;
    vector<int> logs(n);
    for(int i = 0; i < n; i++){
        cin >> logs[i];
        sum += logs[i];
    }
    long long left = 1, right = sum / k;

    while(left <= right){
        long long mid = left + (right - left) / 2;
        // if(mid == 0){
        //     cout << 0 << '\n';
        //     return 0;
        // }
        if(check(logs, mid, k)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << min(left, right) << '\n';

    return 0;
}
