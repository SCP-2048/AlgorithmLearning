#include<bits/stdc++.h>
using namespace std;

int num(bool isOne){
    if(isOne)
        return 1;
    else
        return 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> klo(1, 0); klo.push_back(1);
    bool isOne  = true;
    int needle = 1, cnt = 0;
    long long res = 1;
    for(int i = 1; i < n; i++){
        if(cnt == 0){
            isOne = !isOne;
            klo.push_back(num(isOne));
            res+=num(isOne);
            needle++;
            cnt = klo[needle];
        }
        else{
            klo.push_back(num(isOne));
            res+=num(isOne);
        }
        cnt--;
    }
    cout << res << '\n';
    return 0;
}
