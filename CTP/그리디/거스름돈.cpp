#include <iostream>
using namespace std;

// ���� �׸���(�Ž�����), ���� ū ������ ȭ����� Ȯ�� -> �ּ��� ���� ������ �Ž������� �� �� ����
int main(){
    int N;
    cin >> N;

    int coins[] = { 500, 100, 50, 10, 5, 1 }; // �Ž����� ������ ���� ���� �ܵ��� ����
    int remainer = 1000 - N;
    int count = 0;

    for(int i = 0; i < 6; i++){
        count += remainer / coins[i]; // ���� ū ������ ������
        remainer %= coins[i]; // �������� �ٽ� ����
    }

    cout << count << "\n";

    return 0;
}