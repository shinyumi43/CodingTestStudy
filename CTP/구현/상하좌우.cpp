#include <bits/stdc++.h> // 모든 표준 라이브러리가 포함된 헤더
using namespace std;

int main(void){
    int n, x = 1, y = 1;
    string input;
    char direction[4] = {'R', 'L', 'U', 'D'};
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };

    cin >> n;
    cin.ignore(); // 버퍼 비우기
    getline(cin, input);
    for(int i = 0; i < input.size(); i++){
        char ch = input[i];
        int nx = 0, ny = 0;
        // 이동 계획을 하나씩 확인
        for(int j = 0; j < 4; j++){
            if(ch == direction[j]){
                nx = x + dx[j];
                ny = y + dy[j];
            }
            // 공간의 범위를 벗어나는 경우에는 무시
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            // 이동 수행
            x = nx;
            y = ny;
        }
    }
    cout << x << ' ' << y << '\n';
    return 0;
}