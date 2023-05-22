#include <iostream>
using namespace std;

//top-down 방식

int dp[1000001];

int f(int n){
    if(dp[n]) return dp[n]; //이미 값이 존재하는 경우, 기존 값을 반환, 반복 X
    if(n == 1) return 0;

    int ret = 1e7; //최댓값
    if(n % 2 == 0) ret = min(ret, f(n / 2) + 1);
    if(n % 3 == 0) ret = min(ret, f(n / 3) + 1);
    ret = min(ret, f(n - 1) + 1); //f(n - 1) + 1과 f(n / 2 or 3) + 1 간의 비교

    dp[n] = ret;
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    cout << f(N) << "\n";
    
    return 0;
}