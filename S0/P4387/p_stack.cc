#include<bits/stdc++.h>
using namespace std;

int check(const int& n, const vector<int>& pushed, const vector<int>& poped){
    stack<int> s;
    int n1 = 0, n2 = 0;

    while(n1 < n){
        s.push(pushed[n1++]);
        while(!(s.empty()) && s.top() == poped[n2]){
            s.pop();
            n2++;
        }
    }
    if(n2 == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;

}

int main(){
    freopen("in.txt", "r", stdin);
    int q;
    cin >> q;
    while(q--){
        int n, x;
        cin >> n;
        vector<int> pushed(n);
        vector<int> poped(n);
        for(int i = 0; i < n; i++){
            cin >> pushed[i];
        }
        for(int i = 0; i < n; i++){
            cin >> poped[i];
        }
        check(n, pushed, poped);
    }

    return 0;
}