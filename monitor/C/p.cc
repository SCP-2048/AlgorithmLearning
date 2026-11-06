#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    int a;
    if (n % 2)
    {
        a = (n - 1) / 2;
        cout << 1 << ' ' << a << ' ' << a << '\n';
        return;
    }
    if (n % 4)
    {
        a = (n - 2) / 2;
        cout << 2 << ' ' << a << ' ' << a << '\n';
        return;
    }
    else
    {
        a = n / 4;
        cout << a << ' ' << a << ' ' << a * 2 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
