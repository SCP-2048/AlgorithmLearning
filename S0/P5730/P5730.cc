#include<bits/stdc++.h>
using namespace std;
int main()
{
    const string a[10][5] = {
    {"XXX", "X.X", "X.X", "X.X", "XXX"}, // 0
    {"..X", "..X", "..X", "..X", "..X"}, // 1
    {"XXX", "..X", "XXX", "X..", "XXX"}, // 2
    {"XXX", "..X", "XXX", "..X", "XXX"}, // 3
    {"X.X", "X.X", "XXX", "..X", "..X"}, // 4
    {"XXX", "X..", "XXX", "..X", "XXX"}, // 5
    {"XXX", "X..", "XXX", "X.X", "XXX"}, // 6
    {"XXX", "..X", "..X", "..X", "..X"}, // 7
    {"XXX", "X.X", "XXX", "X.X", "XXX"}, // 8
    {"XXX", "X.X", "XXX", "..X", "XXX"}, // 9
    };
    int n;
    string s;
    cin >> n >> s;
    
    vector<short> b(n);
    for (int i = 0; i < n; i++){
        b[i] = s[i] - '0';
    }
    
    for(int j = 0; j < 5; j++){
        for (int i = 0; i < n; i++){
            cout << a[b[i]][j];
            if (i < n - 1)
                cout << ".";
        }
        cout << "\n" ;
   }
    return 0;
}