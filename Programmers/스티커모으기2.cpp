#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//DP problem
int solution(vector<int> sticker)
{
    int answer = 0;
    int temp_max = 0;
    int n = sticker.size();
    vector<int> dp(n);
    
    if(n == 1) return sticker[0];

    //첫 번째 sticker를 뜯은 경우의 점화식
    dp[0] = sticker[0];
    dp[1] = dp[0];
    //sticker를 뜯는 않는 경우(dp[i - 1])와 뜯는 경우(dp[i- 2] + sticker[i]) 중에 최댓값을 선택
    for(int i = 2; i < n - 1; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    }
    dp[n - 1] = dp[n - 2]; //마지막 sticker는 뜯지 못해야 함
    temp_max = *max_element(dp.begin(), dp.end());

    //첫 번째 sticker를 뜯지 않은 경우의 점화식
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    }

    answer = max(temp_max, *max_element(dp.begin(), dp.end()));

    return answer;
}

int main(){
    cout << solution({14, 6, 5, 11, 3, 9, 2, 10}) << "\n";
}