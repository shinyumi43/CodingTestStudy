//플로이드 와샬(모든 정점에서 모든 정점으로 가는 최단경로)
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool score[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for(int i = 0; i < results.size(); ++i){
        int a = results[i][0];
        int b = results[i][1];
        score[a][b] = true; //a가 b를 이긴 경우
    }

    //k는 거쳐가는 노드
    for(int k = 1; k <= n; ++k){
        //j는 출발 노드
        for(int j = 1; j <= n; ++j){
            //i는 도착 노드
            for(int i = 1; i <= n; ++i){
                if(score[j][k] && score[k][i]){
                    //score[j][i] = score[j][k] + score[k][i]; 본래 경로의 최솟값을 삽입
                    score[j][i] = true;
                }
            }
        }
    }

    for(int j = 1; j <= n; ++j){
        int count = 0;
        for(int i = 1; i <= n; ++i){
            if(score[j][i] || score[i][j]) count++;
        }
        if(count == n-1) { answer++; }
    }

    return answer;
}