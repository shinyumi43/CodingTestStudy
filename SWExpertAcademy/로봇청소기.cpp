#include <iostream>
#include <queue>
using namespace std;

//50 by 50�� 2���� ������ ��(1) or �� ����(0)�� input
//���� �κ� û�ұ��� ��ġ�� ������ input
//���� ���� ������ ���� ��, �󸶳� û���� �� �ִ���

//Simulation ����
/*
�κ� û�ұ�� ������ ���� �۵��Ѵ�.

1. ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�.
2. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���,
	1. �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �� �ִٸ� �� ĭ �����ϰ� 1������ ���ư���.
	2. �ٶ󺸴� ������ ���� ĭ�� ���̶� ������ �� ���ٸ� �۵��� �����.
3. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ���, 
	1. �ݽð� �������� 90�� ȸ���Ѵ�.
	2. �ٶ󺸴� ������ �������� ���� ĭ�� û�ҵ��� ���� �� ĭ�� ��� �� ĭ �����Ѵ�.
	3. 1������ ���ư���.
*/

struct ROBOT {
	int y, x, dir;
};

int n, m, ret;
int map[50][50];
ROBOT robot;

//d = 0, 1, 2, 3 (��, ��, ��, ��)
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int main(){
	cin >> n >> m;
	cin >> robot.y >> robot.x >> robot.dir;
	
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cin >> map[y][x];
		}
	}

	queue<ROBOT> q;
	q.push(robot);

	while (!q.empty()) {

		ROBOT cur = q.front(); q.pop();
		//û�Ұ� ���� ���� ���
		if (map[cur.y][cur.x] == 0) {
			map[cur.y][cur.x] = 2; //û�Ұ� ���� �ʾ����Ƿ� û�Ҹ� ����
			++ret;
		}

		//���� 4ĭ�� Ȯ������ �� û�ҵ��� ���� �� ĭ�� �ִ� ���
		for (int dir = 0; dir < 4; ++dir) {
			ROBOT next;
			//�ٷ� �������� ���� ������ dir + 3, �ѹ� �� ȸ���ϱ� ���ؼ��� dir * 3
			next.dir = (cur.dir + 3 - dir) % 4; //mod 4�� ���� ��ȸ
			next.y = cur.y + dy[next.dir];
			next.x = cur.x + dx[next.dir];

			//map�� ������ ����� ��쿡 ���� ���� ó��
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m
				|| map[next.y][next.x] != 0) { //�̹� û�Ұ� ����Ǿ��ų� ���� ��쿡 �� �ʿ䰡 X
				continue;
			}

			q.push(next); //�־��ֵ��� ��
			break;
		}

		//���� 4ĭ�� Ȯ������ �� û�ҵ��� ���� ĭ�� ���� ���
		if (q.empty()) {
			//dir�� ���� �ݴ� �������� ����
			ROBOT next;
			//������ ��, ������ �ٲ��� ����, dir�� �ݴ� �������� ����
			next.dir = cur.dir;
			next.y = cur.y + dy[(next.dir + 2) % 4];
			next.x = cur.x + dx[(next.dir + 2) % 4];

			//map�� ������ ����� ��쿡 ���� ����ó��
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m
				|| map[next.y][next.x] == 1) {
				break; //�ٶ󺸴� ������ ���� ĭ�� ���̶� ������ �� ������, ����
			}

			q.push(next);
		}

	}

	cout << ret << "\n";
	return 0;
}