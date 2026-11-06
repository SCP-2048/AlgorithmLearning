#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int n, res = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++){
        int x = 0;
        cin >> x;
        pq.push(x);
    }
    while(pq.size() > 1){
        int x, y;
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        x = x + y;
        res += x;
        pq.push(x);
    }
    cout << res << '\n';
    return 0;
}
