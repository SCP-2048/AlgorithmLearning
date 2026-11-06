#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int l, n, k;
    cin >> l >> n >> k;
    vector<int> a(n);
    priority_queue<int, vector<int>> pq;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        pq.push(a[i] - a[i - 1]);
    }
    while(k--){
        int len = pq.top(); pq.pop();
        if((len & 1) == 0){ //even
            len /= 2;
            // cout << "even:"<<len<<'\n';
            pq.push(len); pq.push(len);
        }
        else{ //odd
            len /= 2;
            // cout << "odd:"<<len<<'\n';
            pq.push(len + 1); pq.push(len);
        }
    }
    cout << pq.top() << '\n';

    return 0;
}
