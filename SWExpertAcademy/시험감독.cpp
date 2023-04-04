#include <iostream>
#include <array>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, B, C, val, num = 0;
	long long cnt = 0;
	cin >> N;
	
	//������ ������ �������� �迭 ���� �Ҵ�
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//�� �������� ������ �� �ִ� �������� ��
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		val = arr[i];
		//�� �������� �ݵ�� �����Ѵٴ� ���� ����
		val -= B; cnt++;
		//���� �����ڰ� ������
		if (val > 0) {
			cnt += val / C; val = val % C; //��� ������
			if (val != 0) cnt++; //�������� ����, cnt + 1
		}
	}

	cout << cnt << "\n";

	return 0;
}