#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &fa, int a){
    if(fa[a] == a)
        return a;
    return fa[a] = fa[find(fa, fa[a])];
}

void unite(vector<int> &fa, int a, int b){
    fa[find(fa, a)] = find(fa, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int n; unsigned long long m;
    while(1){
        cin >> n;
        if(n == 0)
            return 0;
        cin >> m;
        vector<int> fa(n + 1);
        for(int i = 0; i <= n; i++){
            fa[i] = i;
        }
        for(int i = 0; i < m; i++){
            int x, y;
            cin >>x >> y;
            unite(fa, x, y);
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(fa[i] == i)
                res++;
        }
        cout << res - 1 << '\n';
    }

    return 0;
}
