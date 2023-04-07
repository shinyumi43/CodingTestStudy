#include <iostream>
#include <queue>
using namespace std;

//50 by 50의 2차원 공간에 벽(1) or 빈 공간(0)이 input
//최초 로봇 청소기의 위치와 방향이 input
//위와 같은 순서로 동작 시, 얼마나 청소할 수 있는지

//Simulation 문제
/*
로봇 청소기는 다음과 같이 작동한다.

1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
	1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
	2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우, 
	1. 반시계 방향으로 90도 회전한다.
	2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
	3. 1번으로 돌아간다.
*/

struct ROBOT {
	int y, x, dir;
};

int n, m, ret;
int map[50][50];
ROBOT robot;

//d = 0, 1, 2, 3 (북, 동, 남, 서)
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
		//청소가 되지 않은 경우
		if (map[cur.y][cur.x] == 0) {
			map[cur.y][cur.x] = 2; //청소가 되지 않았으므로 청소를 진행
			++ret;
		}

		//주위 4칸을 확인했을 때 청소되지 않은 빈 칸이 있는 경우
		for (int dir = 0; dir < 4; ++dir) {
			ROBOT next;
			//바로 왼쪽으로 돌기 때문에 dir + 3, 한번 더 회전하기 위해서는 dir * 3
			next.dir = (cur.dir + 3 - dir) % 4; //mod 4를 통해 순회
			next.y = cur.y + dy[next.dir];
			next.x = cur.x + dx[next.dir];

			//map의 밖으로 벗어나는 경우에 대한 예외 처리
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m
				|| map[next.y][next.x] != 0) { //이미 청소가 진행되었거나 벽일 경우에 할 필요가 X
				continue;
			}

			q.push(next); //넣어주도록 함
			break;
		}

		//주위 4칸을 확인했을 때 청소되지 않은 칸이 없는 경우
		if (q.empty()) {
			//dir의 완전 반대 방향으로 진행
			ROBOT next;
			//후진할 때, 방향은 바뀌지 않음, dir의 반대 방향으로 후진
			next.dir = cur.dir;
			next.y = cur.y + dy[(next.dir + 2) % 4];
			next.x = cur.x + dx[(next.dir + 2) % 4];

			//map의 밖으로 벗어나는 경우에 대한 예외처리
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m
				|| map[next.y][next.x] == 1) {
				break; //바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없으면, 종료
			}

			q.push(next);
		}

	}

	cout << ret << "\n";
	return 0;
}