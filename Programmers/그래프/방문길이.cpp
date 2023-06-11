#include <iostream>
#include <set>
#include <string>
using namespace std;

int solution(string dirs){
    int answer = 0;
    int x = 0, y = 0;
    //경로 자체를 저장해주는 방식을 활용
    set<pair<pair<int, int>, pair<int, int>>> s;

    for(auto dir : dirs){
        int nx = x, ny = y;
        if(dir == 'U') { ny++; }
        else if(dir == 'D') { ny--; }
        else if(dir == 'L') { nx--; }
        else if(dir == 'R') { nx++; }

        if(nx < -5 || nx > 5 || ny < -5 || ny > 5 ) continue;

        //find 함수는 찾고자 하는 원소를 찾지 못하면, end()를 반환
        if(s.find({{x, y}, {nx, ny}}) == s.end() && s.find({{nx, ny}, {x, y}}) == s.end()){
            s.insert({{x, y}, {nx, ny}});
            answer++;
        }

        x = nx;
        y = ny;
    }

    return answer;
}

int main(){
    string str = "UDUDUDUDU";
    cout << solution(str) << "\n";

    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;

// int solution(string dirs) {
//     int answer = 0;
//     int cy = 5, cx = 5, dy = 0, dx = 0;
//     bool map[11][11] = { false };
//     char bch = 'X';

//     for(int i = 0; i < dirs.size(); ++i){
//         char ch = dirs[i];

//         if(ch == 'U'){
//             dy = 1;
//             if(cy + dy > 10){ continue; }

//             if(!map[cy][cx] && bch != 'D'){ map[cy][cx] = true; answer++; }
//             cy += dy;
//         }
//         else if(ch == 'D'){
//             dy = -1; 
//             if(cy + dy < ) { continue; }
            
//             if(!map[cy][cx] && bch != 'U'){ map[cy][cx] = true; answer++; }
//             cy += dy;
//         }
//         else if(ch == 'L'){
//             dx = -1;
//             if(cx + dx < 0) { continue; }
            
//             if(!map[cy][cx] && bch != 'R'){ map[cy][cx] = true; answer++; }
//             cx += dx;
//         }
//         else if(ch == 'R'){
//             dx = 1;
//             if(cx + dx > 10 && bch != 'L') { continue; }

//             if(!map[cy][cx]){ map[cy][cx] = true; answer++; }
//             cx += dx;
//         }

//         bch = ch; //이전값을 저장, 점만 다르고 같은 변을 왔다갔다 하는 경우는 제외
//     }

//     return answer;
// }