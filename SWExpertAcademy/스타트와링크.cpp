#include <iostream>
#include <algorithm>
using namespace std;
/*
	��� Ǯ �� ������
	N���� ��� �߿� N/2���� �̰�,
	���� ���� ����� ��� ������ ���̰�,
	������ ���� ����� ��� ������ ������ ����

	��� ����� ���� �����ϴ� ����� ��, nCn/2
	20 * 19 * 18 * ... / (10 * 9 * 8 * 7 ..) = 184756

	���յ� ����� ������ ������ ����ϱ� ���ؼ� N/2 * N/2�� ������ �ʿ�
	10 * 10 = 100
	
	�� ������ ���� 18475600, 2õ�� ���� �����Ƿ� ����� ����

	a�� b�� ���� ���� �� �� �߰��Ǵ� �ɷ�ġ�� �Ʒ��� ����
	table[a][b] + table[b][a]

	���� team1�� team2�� �ִٰ� �����ϸ�,
	table[team1�� ��� ���][team1�� ��� ���]�� ���� ���� team1�� �ɷ�ġ
	table[team2�� ��� ���][team2�� ��� ���]�� ���� ���� team2�� �ɷ�ġ
	team1�� ��� ��θ� ��ø�ؼ� ���ؾ� �ϱ� ������ 2�� for���� �ʿ�
	�̶� ������ �ִ� ����� 10���̱� ������ 10 * 10

6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0
*/

int N, ret;
int S[20][20]; //N�� �ִ밡 20, ���� 100���� �۰ų� ����
int start[10], link[10]; //���� �� ����� ����
int pick[20]; //������ �̾ƾ� �ϱ� ������ ����

void update() {
	//���� ����� link��, ���� ���� ����� start������ �з�
	int start_size = 0, link_size = 0;
	for (int i = 0; i < N; ++i) { //�ε����� �������� �з�
		if (pick[i] == 0) { start[start_size++] = i; }
		else { link[link_size++] = i; }
	}
	
	int start_sum = 0, link_sum = 0;
	for (int i = 0; i < N / 2; ++i) {
		for (int j = i + 1; j < N / 2; ++j) {
			start_sum += (S[start[i]][start[j]] + S[start[j]][start[i]]);
			link_sum += (S[link[i]][link[j]] + S[link[j]][link[i]]);
		}
	}

	//���������� �ּڰ��� ������Ʈ
	if (ret > abs(start_sum - link_sum)) {
		ret = abs(start_sum - link_sum);
	}
}

void dfs(int cur, int pick_count) { //������ �����ϴ� �Լ�
	if (pick_count == N / 2) { //pick_count�� ����� �̾Ҵ����� �ǹ�
		update();
		return; //������ ����ؾ� �ϴ� Ÿ�̹�
	}

	for (int i = cur; i < N; ++i) {
		pick[i] = 1; //�̾Ҵٸ�, 1
		dfs(i + 1, pick_count + 1);
		pick[i] = 0; //�ٽ� ���ƿ���, ���� ���� ������ ǥ��
	}
}

int main() {
	cin >> N; //N�� ¦��

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> S[i][j];
		}
	}

	ret = 0x7fffffff;
	dfs(0, 0); //n�� �߿��� m�� �̾ƾ� �ϱ� ������ dfs �Լ��� Ȱ��
	cout << ret << "\n";

	return 0;
}
