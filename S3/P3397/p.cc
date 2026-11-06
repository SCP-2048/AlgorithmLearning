#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<int>> carpet(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1 - 1; x <= x2 - 1; x++){
            for(int y = y1 - 1; y <= y2 - 1; y++){
                carpet[x][y]++;
            }
        }
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            cout<<carpet[x][y]<<' ';
        }
        cout << '\n';
    }
    return 0;
}
