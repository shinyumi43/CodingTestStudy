#include <iostream>
#include <algorithm>
using namespace std;

//(r, c)�� ������ ���� ����, 0 - ������ ����

//step L�� ����, 2^n * 2^n �κ� ���ڷ� ����
//�Ϻ� �κ� ���ڸ� 90�� ȸ��
//������ �ִ� ĭ 3��, �� �̻�� �������� ���� ĭ�� ������ ���� 1 �پ��
//(r-1, c), (r+1, c), (r, c-1), (r, c+1) = ����
//���̾���� q�� ����
//1) �����ִ� ������ ��
//2) �����ִ� ���� �� ���� ū ����� �����ϴ� ĭ�� ����
//������ �ִ� ĭ + ������ �ִ� ĭ = ����
//����� ����� ĭ�� ����, ����� ĭ�� ������ ŭ = ū ���

/*
2^L, 2^L�� ���� ũ��� ������, �ð� �������� 90���� ȸ��
������ 3ĭ �̻� �������� ������ ������ ���� 1��ŭ ����
DFS or BFS�� ���� ���� Ž���� �ϸ� ���� ū ���� ����� ĭ�� ������ ����
��� �Լ��� Ȱ���ؼ� �����ϰ� ����� �� ����

90�� ȸ��
x' = n - 1 - y; n�� 2���� �迭�� ũ��, index�� 0���� �����ϹǷ� -1
y' = x;
*/

int N, Q, L;
int A[64][64]; //�ִ� 2^6

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void rotate(int cy, int cx, int len, int unit) {
	if (len == unit) {
		int back[64][64]; //back-up
		for (int y = 0; y < len; ++y) {
			for (int x = 0; x < len; ++x) {
				//x���� ����, y���� ������
				back[cy + x][cx + len - y - 1] = A[cy + y][cx + x];

			}
		}
		for (int y = 0; y < len; ++y) {
			for (int x = 0; x < len; ++x) {
				//���� �迭�� ��ġ�� �ʵ��� ���� �־��ٰ� ���
				A[cy + y][cx + x] = back[cy + y][cx + x];

			}
		}
		return;
	}
	len /= 2; //���ݾ� �ɰ���
	rotate(cy, cx, len, unit);
	rotate(cy + len, cx, len, unit);
	rotate(cy, cx + len, len, unit);
	rotate(cy + len, cx + len, len, unit);
}

void melt() {
	int len = (1 << N);
	int back[64][64]; 
	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			int cnt = 0;
			for (int d = 0; d < 4; ++d) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || ny >= len || nx < 0 || nx >= len) {
					continue;
				}
				if (A[ny][nx] == 0) { //������ ����
					continue;
				}
				++cnt; //������ ���� ����
			}
			if (cnt >= 3 || A[y][x] == 0) {
				back[y][x] = A[y][x];
			}
			else {
				back[y][x] = A[y][x] - 1;
			}

		}
	}

	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			A[y][x] = back[y][x];
		}
	}
}

void dfs(int y, int x, bool visited[64][64], int& size) {
	++size; //�� ĭ ����, ����� ����
	int len = (1 << N);
	for (int d = 0; d < 4; ++d) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (nx < 0 || nx >= len || ny < 0 || ny >= len) {
			continue;
		}
		if (visited[ny][nx] == true || A[ny][nx] == 0) {
			continue;
		}
		visited[ny][nx] = true;
		dfs(ny, nx, visited, size);
	}
}

int main() {
	cin >> N >> Q;
	int len = (1 << N);
	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			cin >> A[y][x]; //������ ��
		}
	}

	while (Q--) {
		cin >> L;
		if (L > 0) { //�ɰ��� 90���� ������ �۾��� ����
			rotate(0, 0, len, (1 << L));
		}
		melt();
	}

	int total = 0, maxSize = 0;
	bool visited[64][64] = { false, };
	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			total += A[y][x]; //������ ��
			if (visited[y][x] == false && A[y][x] != 0) {
				visited[y][x] = true;
				int curSize = 0;
				dfs(y, x, visited, curSize);
				if (maxSize < curSize) {
					maxSize = curSize;
				}
			}
		}
	}
	
	cout << total << "\n";
	cout << maxSize << "\n";

	return 0;
}