#include<bits/stdc++.h>
using namespace std;

pair<int, int> partition(vector<int> &a, int left, int right){
    int mid = (right + left) / 2, upper = right, lower = left, needle = left;
    int pivot = a[mid];
    while(needle <= upper){
        if(a[needle] < pivot){
            swap(a[needle], a[lower]);
            lower++;
            needle++;
        }
        else if(a[needle] > pivot){
            swap(a[needle], a[upper]);
            upper--;
        }
        else{
            needle++;
        }
    }
    return {lower, upper};
}

void quickSort(vector<int> &a, int left, int right){
    if(left >= right)
        return;
    auto [lower, upper] = partition(a, left, right);
    quickSort(a, left, lower - 1);
    quickSort(a, upper + 1, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    quickSort(a, 0, n - 1);
    for(int x : a){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
