#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("in.txt", "r", stdin);
    int n; cin >> n;
    string res = "";
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        size_t pos = s.find_first_not_of('0 ');
        s = s.substr(pos);
        int len0 = res.size(), len1 = s.size();
        if(len0 < len1){
            res = s;
            continue;
        }
        else if(len0 > len1){
            continue;
        }
        else{
            for(int j = 0; j < len0; j++){
                if(res[j] > s[j]){
                    break;
                }
                if(res[j] < s[j]){
                    res = s;
                    break;
                }
            }
        }
    }
    cout << res << '\n';
    return 0;
}
