#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> f(n + 1, 0), a(n + 1);
    stack<int> st;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        while(!st.empty()){
            int index = st.top();
            if(a[index] >= a[i]){
                break;
            }
            else{
                f[index] = i;
                st.pop();
            }
        }
        st.push(i);
    }

    for(int i = 1; i <= n; i++){
        cout << f[i] << ' ';
    }
    return 0;
}
