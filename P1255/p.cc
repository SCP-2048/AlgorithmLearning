#include<bits/stdc++.h>
using namespace std;
vector<long long> mem;

long long count(long long a){
    if(a == 0){
        return 1;
    }
    if(a < 0){
        return 0;
    }
    return count(a - 1) + count(a - 2);
}
int main(){
    int n = 0;
    cin >> n;
    cout << count(n);
    return 0;
}