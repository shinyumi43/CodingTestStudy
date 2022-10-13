#include <iostream>
#include <algorithm> //sort 함수 활용
using namespace std;

int main(){
    // 1번 풀이
    int N, M, K, count = 0, total = 0;
    cin >> N >> M >> K;

    int* number = new int[N]; // 동적할당

    for(int i = 0; i < N; i++){
        cin >> number[i];
    }

    sort(number, number + N); // 기본적으로 오름차순 sort

    for(int i = 0; i < M; i++){ 
        if(count != K){
            total += number[N - 1]; // 가장 큰 수 더하기
            count++;
        }
        else{
            total += number[N - 2]; // 두 번째로 큰 수 더하기
            count = 0;
        }
    }

    cout << total << "\n";

    // 2번 풀이
    int N, M, K, count = 0, total = 0, first, second;
    cin >> N >> M >> K;

    int* number = new int[N];

    for(int i = 0; i < N; i++){
        cin >> number[i];
    }

    sort(number, number + N); // 기본적으로 오름차순 sort
    first = number[N - 1];
    second = number[N - 2];

    count = (int)(M / (K + 1)) * K + M % (K + 1); // 나누어 떨어지지 않는 경우도 고려

    total += first * count + second * (M - count);

    cout << total << "\n";

    return 0;
}