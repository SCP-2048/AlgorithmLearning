#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    long long res = 0;
    while(pq.size() > 1){
        int x, y;
        x = pq.top(); pq.pop();
        y = pq.top(); pq.pop();
        res += x + y;
        pq.push(x + y);
    }
    cout << res;
    return 0;
}
