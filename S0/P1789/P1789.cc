#include<bits/stdc++.h>
//#include<fstream>
using namespace std;
int main(){
    //ifstream fin("input.txt");
    int n, m, k;
    cin >> n >> m >> k;
    bool field[n][n];
    int a[2] = {0};
    memset(field, 1, sizeof(field));

    for (int i = 0; i < m; i++){
        cin >> a[0] >> a[1];
        a[0] -= 1; a[1] -= 1;

        
        for (int x = -2; x < 3; x++){
            for (int y = -2; y < 3; y++){
                if (abs(x) + abs(y) <= 2 && a[0] + x >= 0 && a[1] + y >= 0 && a[0] + x < n && a[1] + y <n){
                    field[a[0] + x][a[1] + y] = 0;
                }
            }
        }
    }

    for (int i = 0; i < k; i++){
        cin >> a[0] >> a[1];
        a[0] -= 1; a[1] -= 1;
        
        for (int x = -2; x < 3; x++){
            for (int y = -2; y < 3; y++){
                if (a[0] + x >= 0 && a[1] + y >= 0 && a[0] + x < n && a[1] + y <n){
                    field[a[0] + x][a[1] + y] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //cout << field[i][j];
            ans += field[i][j];
        }
        cout << "\n" ;
    }
    cout << ans;
    //fin.close();
    return 0;
}