#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int q;
    cin >> q;
    while(q--){
        int n;
        int left = 0; //表示pushed中被掠过的数量
        bool firsTime = true; //标示是不是第一次扣到起点
        cin >> n;
        vector<pair<int, bool>> pushed(n, {0, false}); //true代表被掠过
        vector<pair<int, bool>> poped(n, {0, false});
        int n1 = 0, n2 = 0;
        for(int i = 0; i < n; i++){
            cin >> pushed[i].first;
        }
        for(int i = 0; i < n; i++){
            cin >> poped[i].first;
        }

        while(1){
            if(pushed[n1].first == poped[n2].first){ //匹配
                if(n1 == 0 && firsTime == false){
                    cout << "Yes" << endl;
                    break;
                }
                else
                    firsTime = false;
                if (n1 == n - 1){
                    if(left == 0){
                        cout << "Yes" << endl;
                        break;   
                    }
                    else{
                        while(pushed[n1].second == false){
                            n1--;
                        }
                        n2++;
                    }
                }
                else{
                    if(pushed[n1].second == true){
                        left--;
                        pushed[n1].second = false;
                        n1--; n2++;
                    }
                    else{
                        n1++; n2++;
                    }
                }
                // cout << n1 << " " << n2 << endl;
            }
            else{
                if(firsTime)
                    firsTime = false;
                if(left > (n - n2)){
                    cout << "No" << endl;
                    break;
                }
                if(n1 == n - 1){
                    if(left == 0){
                        cout << "No" << endl;
                        break;
                    }
                    else{
                        while(pushed[n1].second == true){
                            n1--;
                        }
                        // n2++;
                    }
                }
                else if(pushed[n1].second == true){
                    // n2++;
                }
                else{
                    left++;
                    pushed[n1].second = true;
                    n1++;
                }
                // cout << n1 << " " << n2 << endl;
            }
            // if(n1 >= n || n2 >= n){
            //     cout << "No" << endl;
            //     break;
            // }
        }
        if(n2 == n){
            cout << "Yes" << endl;
            break;
        }

    }

    return 0;
}