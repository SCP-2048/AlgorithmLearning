#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> minium(n - k + 1, INT_MAX), minimax(n - k + 1, INT_MIN);
    for(auto &x : a) {
        cin >> x;
    }
    deque<int> up, down;
    for(int i = 0; i < k; i++){
        while(!up.empty() && a[up.back()] <= a[i]){
            up.pop_back();
        }
        up.push_back(i);
        while(!down.empty() && a[down.back()] >= a[i]){
            down.pop_back();
        }
        down.push_back(i);
    }
    minium[0] = down.front(); minimax[0] = up.front();
    for(int i = k; i < n; i++){
        if(!up.empty() && up.front() <= i - k){
            up.pop_front();
        }
        if(!down.empty() && down.front() <= i - k){
            down.pop_front();
        }
        
        while(!up.empty() && a[up.back()] <= a[i]){
            up.pop_back();
        }
        up.push_back(i);

        while(!down.empty() && a[down.back()] >= a[i]){
            down.pop_back();
        }
        down.push_back(i);
        minium[i - k + 1] = down.front(); minimax[i - k + 1] = up.front();
    }

    for(auto x : minium) cout << a[x] << ' ';
    cout << '\n';
    for(auto x : minimax) cout << a[x] << ' ';
    cout << '\n';


    return 0;
}
