#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    unordered_set<pair<int, int>> posj;
    unordered_set<pair<int, int>> posf;
    // unordered_map<int, pair<int, int>> posJ;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'J'){
                posj.insert({i, j});
            }
            if(g[i][j] == 'F'){
                posf.insert({i, j});
            }
        }
    }
    int res = 0;

    while(1){
        for(auto [x, y] : posj){
            if(x == 0 || x == n - 1 || y == 0 || y == m-1){
                cout << res;
                return 0;
            }
            if(g[x-1][y] == '.'){
                g[x-1][y] = 'J';
                posj.insert({x-1, y});
            }
            if(g[x+1][y] == '.'){
                g[x+1][y] = 'J';
                posj.insert({x+1, y});
            }
            if(g[x][y-1] == '.'){
                g[x][y-1] = 'J';
                posj.insert({x, y-1});
            }
            if(g[x][y+1] == '.'){
                g[x][y+1] = 'J';
                posj.insert({x, y+1});
            }
        }

        for(auto [x, y] : posf){
            if(x != 0 && (g[x-1][y] == '.' || g[x-1][y] == 'J')){
                if(g[x-1][y] == 'J'){
                    posj.erase({x-1,y});
                }
                g[x-1][y] = 'F';
                posf.insert({x-1, y});
            }
            if(x != n - 1 && (g[x+1][y] == '.' || g[x+1][y] == 'J')){
                if(g[x+1][y] == 'J'){
                    posj.erase({x+1,y});
                }
                g[x+1][y] = 'F';
                posf.insert({x+1, y});
            }
            if(y != 0 && (g[x][y-1] == '.' || g[x][y-1] == 'J')){
                if(g[x][y-1] == 'J'){
                    posj.erase({x,y-1});
                }
                g[x][y-1] = 'F';
                posf.insert({x, y-1});
            }
            if(y != m - 1 && (g[x][y+1] == '.' || g[x][y+1] == 'J')){
                if(g[x][y+1] == 'J'){
                    posj.erase({x,y+1});
                }
                g[x][y+1] = 'F';
                posf.insert({x, y+1});
            }
        }

        res++;
    }
    cout << -1;
    

    return 0;
}
