#include <iostream>
using namespace std;

int main(){
    int N, K, count = 0; 
    cin >> N >> K;

    // N이 K의 배수가 될 때, N을 K로 나누고 그렇지 않을 경우에 N에서 1을 차감
    while(true){
        if(N == 1) { cout << count << "\n"; break; }

        if(N % K == 0){ N = N / K; count++; }
        else {N--; count++;}
    }

    return 0;
}