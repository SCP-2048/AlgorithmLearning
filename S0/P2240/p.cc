#include<bits/stdc++.h>
using namespace std;

struct Pile{
    int m, v;
    double q;

};

int main(){
    int n, t;
    cin >> n >> t;
    vector<Pile> piles(n);

    for(int i = 0; i < n; i++){
        cin >> piles[i].m >> piles[i].v;
        piles[i].q = (double)piles[i].v / piles[i].m;
    }
    sort(piles.begin(), piles.end(), [](const Pile& x, const Pile& y){
        return x.q > y.q;
    });

    double res = 0;

    for(Pile p : piles){
        if (p.m <= t){
            t -= p.m;
            res += p.v;
        }
        else{
            res += t * p.q;
            break;
        }
    }
    printf("%.2f", res);

    return 0;
}