#include <bits/stdc++.h>
using namespace std;

void RF(int n, int row, int col){
    RF(1 + 4 * (n - 1), row, col);

    if(n == 1) { return; }

    // RF(n - 1, row + 2, col - 2);
}


void drawSqure(); //사각형을 그리는 함수를 만들기 

//똑같은 형태를 가지는데 크기만 달라짐, 재귀를 활용
int main() {
    //변의 길이가 1+4(n-1)임을 확인할 수 있음 
    //좌상단 좌표를 기준으로 바깥쪽부터 안쪽으로 들어가듯이 재귀를 진행
    //안쪽으로 갈수록 오른쪽으로 두 칸, 아래로 두 칸 움직임을 확인
    //분할 정복, 한 변의 길이와 좌상단 좌표를 통해 그릴 수 있음
    int n;
    cin >> n;

    char display[397][397];

    int len = 1 + 4 * (n - 1);
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            display[i][j] = 0; //전부 초기화
        }
    }
    
}