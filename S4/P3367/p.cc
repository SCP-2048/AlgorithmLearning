#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &fa, int a){
    if (fa[a] == a)
        return a;
    return fa[a] = find(fa, fa[a]);
}

void unite(vector<int> &fa, int a, int b){
    fa[find(fa, a)] = find(fa, b);
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> fa(n + 1); 
    int a, b;
    short op;
    for(int i = 0; i < n + 1; i++) fa[i] = i;
    for(int i = 0; i < m; i++){
        cin >> op >> a >> b;
        if(op == 1){
            unite(fa, a, b);
        }
        else if(op == 2){
            if(find(fa, a) == find(fa, b))
                cout << 'Y' << endl;
            else
                cout << 'N' << endl;
        }
    }
    return 0;
}
