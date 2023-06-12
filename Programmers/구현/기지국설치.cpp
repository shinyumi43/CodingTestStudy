#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int now = 1;
    int index = 0;
    
    while(now <= n){
        //내 위치가 범위 안에 있는 경우
        if(now >= stations[index] - w && now <= stations[index] + w){
            now = stations[index] + w; //이동
            index++;
        }
        else{ //그렇지 않은 경우, 기지국을 새로 설치
            answer++;
            now += w * 2; //지금 속한 전파 위치의 가장 우측으로 이동
        }
        //다음 칸으로 이동
        now++;
    }

    return answer;
}