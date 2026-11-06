#include<bits/stdc++.h>
using namespace std;
typedef pair<long, int> pli;

long long compute(const int& x, const int& a, const int& b, const int& c){
    return a * x * x + b * x + c;
}

int main(){
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> sheet(n);
    vector<int> needles(n, 1);
    priority_queue<pli, vector<pli>, greater<pli>> pq; //{value, ith function}
    for(int i = 0; i < n; i++)
        cin >> get<0>(sheet[i]) >> get<1>(sheet[i]) >> get<2>(sheet[i]);
    
    for(int i = 0; i < n; i++){
        pq.push({compute(needles[i], get<0>(sheet[i]), get<1>(sheet[i]), get<2>(sheet[i]))
        , i});
    }

    while(m--){
        auto f = pq.top();
        pq.pop();
        cout << f.first << ' ';
        needles[f.second]++;
        pq.push({compute(needles[f.second], get<0>(sheet[f.second]), get<1>(sheet[f.second]), get<2>(sheet[f.second])),
        f.second});
    }

    return 0;
}
