#include <iostream>
using namespace std;
/*
	��Ϲ��� ȸ�� ��Ģ
	1. �´��� ���� �ٸ���, B�� A�� ȸ���� ����� �ݴ�� ȸ��
	2. �´��� ���� ������, B�� ȸ������ ����

	N���� 0, S���� 1, -1�� �ݽð�, 1�� �ð�
	10101111
	01111101
	11001110
	00000010
	2
	3 -1
	1 1

	1�� ��� ������ �ð�������� ȸ����Ű��,
	2�� ��� ������ �� �ð� �������� ȸ���ϰ� �ǰ�,
	2���� ȸ���ϱ� ������ 3���� ���ÿ� �ð� �������� ȸ��
	4���� 3���� ȸ���Ͽ�����, �´��� ���� ���� ������ ȸ������ ����
*/

int main() {
	char gear[4][9]; //�������� /n ������ ���� 9�� ����
	for (int i = 0; i < 4; ++i) {
		cin >> gear[i];
	}

	int k;
	cin >> k;
	while (k--) {
		int target, cmd;
		cin >> target >> cmd;
		--target; //gear index�� 0123�̹Ƿ� -1
		int move_cmd[4] = { 0, }; //������ gear�� ��Ī�ؼ� ��� �������� ������ ������
		move_cmd[target] = cmd;
		//target�� left ������ ��Ϲ����� ������
		for (int left = target - 1; left >= 0; --left) {
			int right = left + 1;
			if (gear[left][2] == gear[right][6]) { //���� ������, �������� ����
				break;
			}
			else { //���� �ٸ���, right�� ����� �ݴ�� ������
				move_cmd[left] = move_cmd[right] * -1;
			}
		}
		//target�� right ������ ��Ϲ����� ������
		for (int right = target + 1; right < 4; ++right) {
			int left = right - 1;
			if (gear[left][2] == gear[right][6]) { //���� ������, �������� ����
				break;
			}
			else { //���� �ٸ���, left�� ����� �ݴ�� �����̵���
				move_cmd[right] = move_cmd[left] * -1;
			}
		}

		for (int i = 0; i < 4; ++i) {
			if (move_cmd[i] == 1) { //�ð� �������� �������� �ϴ� ���
				char temp = gear[i][7]; //back-up �� �����
				for(int j = 7; j >= 1; --j){ //7-6, 6-5, 5-4 ... 1-0
					gear[i][j] = gear[i][j - 1];
				}
				gear[i][0] = temp; //0-7
			}
			else if (move_cmd[i] == -1) { //�ݽð� �������� �������� �ϴ� ���
				char temp = gear[i][0]; //back-up �� �����
				for (int j = 0; j < 7; ++j) { //0-1, 1-2, 2-3 ... 6-7
					gear[i][j] = gear[i][j + 1];
				}
				gear[i][7] = temp; //7-0
			}
		}
	}
	
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		if (gear[i][0] == '1') { //���� ����� ���� shift ������ Ȱ��
			ret += (1 << i);
		}
	}
	cout << ret << "\n";
	return 0;
}