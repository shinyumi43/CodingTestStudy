#include <iostream>
using namespace std;

int main(){
    int N, K, count = 0; 
    cin >> N >> K;

    // N�� K�� ����� �� ��, N�� K�� ������ �׷��� ���� ��쿡 N���� 1�� ����
    while(true){
        if(N == 1) { cout << count << "\n"; break; }

        if(N % K == 0){ N = N / K; count++; }
        else {N--; count++;}
    }

    return 0;
}