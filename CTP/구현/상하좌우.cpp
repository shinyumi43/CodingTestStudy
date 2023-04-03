#include <bits/stdc++.h> // ��� ǥ�� ���̺귯���� ���Ե� ���
using namespace std;

int main(void){
    int n, x = 1, y = 1;
    string input;
    char direction[4] = {'R', 'L', 'U', 'D'};
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };

    cin >> n;
    cin.ignore(); // ���� ����
    getline(cin, input);
    for(int i = 0; i < input.size(); i++){
        char ch = input[i];
        int nx = 0, ny = 0;
        // �̵� ��ȹ�� �ϳ��� Ȯ��
        for(int j = 0; j < 4; j++){
            if(ch == direction[j]){
                nx = x + dx[j];
                ny = y + dy[j];
            }
            // ������ ������ ����� ��쿡�� ����
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            // �̵� ����
            x = nx;
            y = ny;
        }
    }
    cout << x << ' ' << y << '\n';
    return 0;
}