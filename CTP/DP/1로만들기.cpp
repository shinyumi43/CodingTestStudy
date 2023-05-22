#include <iostream>
using namespace std;
/*
문제 : 
X가 3으로 나누어 떨어지면, 3으로 나누기
X가 2로 나누어 떨어지면, 2로 나누기
1을 빼기

정수 N이 주어졌을 때, 연산 세 개를 적절히 활용해서 1을 만들도록
연산을 사용하는 횟수의 최솟값을 구하도록
*/

//Bottom-Up 방식

int dp[1000001]; //기본은 0으로 초기화

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    //연산 횟수의 최솟값을 기록, dp[1] = 0, 최솟값이 나올 수 있는 식이 총 3가지
    for(int i = 2; i <= 1000000; ++i){
        int minval = dp[i - 1] + 1; // dp[i - 1] + 1 (1)
        if(i % 2 == 0) minval = min(minval, dp[i / 2] + 1); //dp[i / 2] + 1 (2)
        if(i % 3 == 0) minval = min(minval, dp[i / 3] + 1); //dp[i / 3] + 1 (3)
        dp[i] = minval;
    }
    cout << dp[N] << "\n";

    return 0;
}