#include <iostream>
using namespace std;

// 백준 그리디(거스름돈), 가장 큰 단위의 화폐부터 확인 -> 최소의 동전 개수로 거스름돈을 줄 수 있음
int main(){
    int N;
    cin >> N;

    int coins[] = { 500, 100, 50, 10, 5, 1 }; // 거스름돈 개수가 가장 적게 잔돈을 제공
    int remainer = 1000 - N;
    int count = 0;

    for(int i = 0; i < 6; i++){
        count += remainer / coins[i]; // 가장 큰 돈으로 나누기
        remainer %= coins[i]; // 나머지로 다시 저장
    }

    cout << count << "\n";

    return 0;
}