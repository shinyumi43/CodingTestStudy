#include <iostream>
#include <algorithm>
using namespace std;

//(r, c)에 얼음의 양이 삽입, 0 - 얼음이 없음

//step L을 결정, 2^n * 2^n 부분 격자로 나눔
//일부 부분 격자를 90도 회전
//얼음이 있는 칸 3개, 그 이상과 인접하지 않은 칸은 얼음의 양이 1 줄어듦
//(r-1, c), (r+1, c), (r, c-1), (r, c+1) = 인접
//파이어스톰을 q번 시전
//1) 남아있는 얼음의 합
//2) 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
//얼음이 있는 칸 + 얼음이 있는 칸 = 연결
//덩어리는 연결된 칸의 집합, 연결된 칸의 집합이 큼 = 큰 덩어리

/*
2^L, 2^L의 격자 크기로 나누고, 시계 방향으로 90도를 회전
얼음이 3칸 이상 인접하지 않으면 얼음의 양을 1만큼 줄임
DFS or BFS를 통해 완전 탐색을 하며 가장 큰 얼음 덩어리의 칸의 개수를 구함
재귀 함수를 활용해서 간결하게 사용할 수 있음

90도 회전
x' = n - 1 - y; n은 2차원 배열의 크기, index는 0부터 시작하므로 -1
y' = x;
*/

int N, Q, L;
int A[64][64]; //최대 2^6

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void rotate(int cy, int cx, int len, int unit) {
	if (len == unit) {
		int back[64][64]; //back-up
		for (int y = 0; y < len; ++y) {
			for (int x = 0; x < len; ++x) {
				//x축은 교차, y축은 뒤집음
				back[cy + x][cx + len - y - 1] = A[cy + y][cx + x];

			}
		}
		for (int y = 0; y < len; ++y) {
			for (int x = 0; x < len; ++x) {
				//기존 배열에 겹치지 않도록 따로 넣었다가 덮어씀
				A[cy + y][cx + x] = back[cy + y][cx + x];

			}
		}
		return;
	}
	len /= 2; //절반씩 쪼개기
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
				if (A[ny][nx] == 0) { //얼음이 없음
					continue;
				}
				++cnt; //얼음의 수를 증가
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
	++size; //한 칸 진입, 사이즈가 증가
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
			cin >> A[y][x]; //얼음의 양
		}
	}

	while (Q--) {
		cin >> L;
		if (L > 0) { //쪼개서 90도를 돌리는 작업을 수행
			rotate(0, 0, len, (1 << L));
		}
		melt();
	}

	int total = 0, maxSize = 0;
	bool visited[64][64] = { false, };
	for (int y = 0; y < len; ++y) {
		for (int x = 0; x < len; ++x) {
			total += A[y][x]; //얼음의 양
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