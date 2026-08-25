#include<bits/stdc++.h>
using namespace std;

struct Life{
    int x, y, direction; //x是横，y是纵
    bool operator==(const Life& other) const{
        return x == other.x && y == other.y;
    }
    void move(const vector<string>& map){
        switch (direction) {
            case 0:
                if (y == 0 || map[y - 1][x] == '*')
                    direction++;
                else
                    y--;
                break;
            case 1:
                if (x == 9 || map[y][x + 1] == '*')
                    direction++;
                else
                    x++;
                break;
            case 2:
                if (y == 9 || map[y + 1][x] == '*')
                    direction++;
                else
                    y++;
                break;
            case 3:
                if (x == 0 || map[y][x - 1] == '*')
                    direction = 0;
                else
                    x--;
                break;
        }
    }
};

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    vector<string> map(10);
    Life john, john_original, cow, cow_original;
    for(int i = 0; i < 10; i++){
        cin >> map[i];
        for(int j = 0; j < 10; j++){
            if (map[i][j] == 'F')
                john_original = {j, i, 0};
            if (map[i][j] == 'C')
                cow_original = {j, i , 0};
        }
    }
    john = john_original;
    cow = cow_original;
    int time = 0;
    set<tuple<int,int,int,int,int,int>> track;

    while(++time){
        john.move(map);
        cow.move(map);

        if (john.x == cow.x && john.y == cow.y){
            cout << time << endl;
            return 0;
        }
        auto t = make_tuple(john.x, john.y, john.direction,
                            cow.x, cow.y, cow.direction);

        if (track.count(t)){
            cout << 0 << endl;
            return 0;
        }
        else
            track.insert(t);
    }
    return 0;

}