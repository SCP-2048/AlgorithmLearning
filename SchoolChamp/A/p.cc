#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n;
    long long c, s;
    cin >> n >> c >> s;
    long long waste = 0; int lack = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        s += a;
        if(s > c){
            waste += s - c;
            s = c;
        }
        s -= b;
        if(s < 0){
            lack++;
            s = 0;
        }
    }
    cout << s << ' '<< waste << ' '<<lack<<'\n';


    return 0;
}
