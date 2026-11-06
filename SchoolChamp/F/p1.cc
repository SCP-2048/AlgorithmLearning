#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    deque<pair<int, int>> posj;
    deque<pair<int, int>> posf;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'J'){
                posj.push_back({i, j});
            }
            if(g[i][j] == 'F'){
                posf.push_back({i, j});
            }
        }
    }
    int lj = posj.size();
    int lf = posf.size();
    int res = 1;

    while(lj != 0){
        for(int i = 0; i < lj; i++){
            auto [x, y] = posj.front();
            posj.pop_front();
            if(g[x][y] != 'J')
                continue;
            if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
                cout << res;
                return 0;
            }
            if(g[x-1][y] == '.'){
                g[x-1][y] = 'J';
                posj.push_back({x-1, y});
            }
            if(g[x+1][y] == '.'){
                g[x+1][y] = 'J';
                posj.push_back({x+1, y});
            }
            if(g[x][y-1] == '.'){
                g[x][y-1] = 'J';
                posj.push_back({x, y-1});
            }
            if(g[x][y+1] == '.'){
                g[x][y+1] = 'J';
                posj.push_back({x, y+1});
            }
        }

        for(int i = 0; i < lf; i++){
            auto [x, y] = posf.front();
            posf.pop_front();

            if(x != 0 && (g[x-1][y] != '#' && g[x-1][y] != 'F')){
                g[x-1][y] = 'F';
                posf.push_back({x-1, y});
            }
            if(x != n - 1 && (g[x+1][y] != '#' && g[x+1][y] != 'F')){
                g[x+1][y] = 'F';
                posf.push_back({x+1, y});
            }
            if(y != 0 && (g[x][y-1] != '#' && g[x][y-1] != 'F')){
                g[x][y-1] = 'F';
                posf.push_back({x, y-1});
            }
            if(y != m - 1  && (g[x][y+1] != '#' && g[x][y+1] != 'F')){
                g[x][y+1] = 'F';
                posf.push_back({x, y+1});
            }

        }

        res++;
        lj = posj.size();
        lf = posf.size();
    }
    cout << -1;

    return 0;
}
