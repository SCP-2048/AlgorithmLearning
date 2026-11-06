#include<bits/stdc++.h>
using namespace std;

int compute(stack<int>& s, const char &op){
    vector<int> a(2);
    a[1] = s.top();
    s.pop();
    a[0] = s.top();
    s.pop();
    switch(op){
    case '+':
        return a[0] + a[1];
    case '-':
        return a[0] - a[1];
        break;
    case '*':
        return a[0] * a[1];
        break;
    case '/':
        return a[0] / a[1];
        break;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    stack<int> s;
    string token;
    int l;
    while(getline(cin, token, '.')){
        int len = token.size();
        int i = 0;
        while(i < len){
            string num;

            if(token[i] == '+' || token[i] == '-' || token[i] == '*' || token[i] == '/')
                s.push(compute(s, token[i]));
            else if(token[i] == '@'){
                cout << s.top() << endl;
                return 0;
            }

            while(isdigit(token[i])){
                num.push_back(token[i]);
                i++;
            }
            if(!num.empty())
                s.push(stoi(num));
            i++;
        }
    }

    return 0;
}