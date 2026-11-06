#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("in.txt", "r", stdin);
    int n, k, p;
    cin >> n;
    vector<int> line(n);
    line[0] = 1;
    for (int i = 2; i <= n; i++){
        cin >> k >> p;
        auto it = find(line.begin(), line.end(), k);
        if(p == 0){
            line.insert(it, i);
        }
        else if(p == 1){
            line.insert(it + 1, i);
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        auto it = find(line.begin(), line.end(), k);
        if (it != line.end())
            line.erase(it);
    }
    for(int s : line){
        if(s != 0)
            cout << s << " ";
    }
    cout << endl;

    return 0;
}