#include <iostream>
#include <algorithm> //sort �Լ� Ȱ��
using namespace std;

int main(){
    // 1�� Ǯ��
    int N, M, K, count = 0, total = 0;
    cin >> N >> M >> K;

    int* number = new int[N]; // �����Ҵ�

    for(int i = 0; i < N; i++){
        cin >> number[i];
    }

    sort(number, number + N); // �⺻������ �������� sort

    for(int i = 0; i < M; i++){ 
        if(count != K){
            total += number[N - 1]; // ���� ū �� ���ϱ�
            count++;
        }
        else{
            total += number[N - 2]; // �� ��°�� ū �� ���ϱ�
            count = 0;
        }
    }

    cout << total << "\n";

    // 2�� Ǯ��
    int N, M, K, count = 0, total = 0, first, second;
    cin >> N >> M >> K;

    int* number = new int[N];

    for(int i = 0; i < N; i++){
        cin >> number[i];
    }

    sort(number, number + N); // �⺻������ �������� sort
    first = number[N - 1];
    second = number[N - 2];

    count = (int)(M / (K + 1)) * K + M % (K + 1); // ������ �������� �ʴ� ��쵵 ���

    total += first * count + second * (M - count);

    cout << total << "\n";

    return 0;
}