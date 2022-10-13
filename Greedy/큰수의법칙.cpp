#include <iostream>
#include <algorithm> //sort 함수 활용
using namespace std;

int main(){
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

    return 0;
}