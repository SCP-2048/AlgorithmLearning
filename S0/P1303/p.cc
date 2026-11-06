#include<bits/stdc++.h>
using namespace std;
string add(const string& s1, const string& s2){
    string res;
    int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
    if(i == 0 && j == 0)
        return "0";
    while(i >=0 || j >= 0 || carry != 0){
        if(i >= 0) carry += s1[i--] - '0';
        if(j >= 0) carry += s2[j--] - '0';
        res.push_back(char(carry % 10 + '0'));
        carry /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string times(int a, const string& s){
    string res;
    int carry = 0;
    int len = s.size();
    for(int i = len - 1; i >= 0; i--){
        carry += a * (s[i] - '0');
        res.push_back(char(carry % 10 + '0'));
        carry /= 10;
    }
    if(carry != 0)
        res.push_back(char(carry + '0'));
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 == "0" || s2 == "0"){
        cout << 0;
        return 0;
    }
    string res, tem;
    int len = s1.size();

    for(int i = 0; i < len; i++){
        tem = times(s1[len - i - 1] - '0', s2);
        for(int j = i; j > 0; j--)
            tem.push_back('0');
        res = add(res, tem);
    }

    bool firstZero = true;
    for(char c : res){
        if (c != '0'){
            cout << c;
            firstZero = false;
        }
        else if (!firstZero){
            cout << c;
        }
    }

    return 0;
}