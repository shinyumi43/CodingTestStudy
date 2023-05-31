#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 9;
void dfs(int N, int number, int count, int curNum){
    if(count >= 9) return;
    if(curNum == number){
        answer = min(answer, count); //최소 횟수를 반환
        return;
    }
    
    int tempNum = 0;
    for(int i = 0; i + count < 9; ++i){ //최대 N의 사용횟수는 9번이므로 이때까지 반복
        tempNum = tempNum * 10 + N; //N, NN, NNN, NNN..
        dfs(N, number, count + 1 + i, curNum + tempNum);
        dfs(N, number, count + 1 + i, curNum - tempNum);
        dfs(N, number, count + 1 + i, curNum * tempNum);
        dfs(N, number, count + 1 + i, curNum / tempNum);
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if(answer == 9) return -1;
    return answer;
}

int main(){
    int N = 5, number = 12;
    dfs(N, number, 0, 0);
}