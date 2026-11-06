#include<bits/stdc++.h>
using namespace std;
struct student {
    string name;
    int chinese, math, english;
    int sum() const{
        return chinese + math + english;
    }
};

bool check(student& stu1, student& stu2){
    return (abs(stu1.chinese - stu2.chinese) <= 5) && 
    (abs(stu1.math - stu2.math) <= 5) && 
    (abs(stu1.english - stu2.english) <= 5) && 
    (abs(stu1.sum() - stu2.sum()) <= 10);
}

int main(){
    int n;
    vector<student> stu;
    cin >> n;


    for(int i = 0; i < n; i++){
        student tem;
        cin >> tem.name >> tem.chinese >> tem.math >> tem.english;
        stu.push_back(tem);
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j< n; j++){
            if(check(stu[i], stu[j])){
                cout << stu[i].name << ' ' << stu[j].name << '\n';
            }
        }
    }
    
    return 0;
}