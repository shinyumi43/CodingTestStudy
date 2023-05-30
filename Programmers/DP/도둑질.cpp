#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000000
using namespace std;

//1) dp[i] = j 는 i번째까지 집을 털었을 경우에 최댓값 j를 의미
//1-1) i번째 집을 털지 않는 경우 : dp[i] = dp[i - 1];
//1-2) i번째 집을 터는 경우 : dp[i] = dp[i - 2] + money[i];

//2) 이와 같은 경우를 첫 번째 집을 터는 경우와 털지 않는 경우로 분리해야 함
//2-1) dp는 첫 번째 집을 터는 경우, dpn은 첫 번째 집을 털지 않는 경우

int dp[MAX];
int dpn[MAX];

int solution(vector<int> money) {
    int n = money.size() - 1;
    int answer = 0;
    
    dp[0] = money[0]; dp[1] = dp[0]; //첫 번째 집에서 도둑질
    dpn[0] = 0; dpn[1] = money[1]; //첫 번째 집에서 도둑질하지 않음
    
    for(int i = 2; i <= n - 1; ++i){
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }
    for(int i = 2; i <= n; ++i){
        dpn[i] = max(dpn[i - 1], dpn[i - 2] + money[i]);
    }
    
    answer = max(dp[n - 1], dpn[n]); //첫 번째 집을 털게 될 경우, n번째 집을 털지 못함
    return answer;
}