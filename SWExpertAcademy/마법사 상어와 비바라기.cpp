//#include <iostream>
//#include <cstring>
//using namespace std;
//
//struct CLOUD
//{
//	int y, x;
//};
//
//int N, M;
//int cloud_size; //구름의 크기
//int cloud_map[50][50]; //구름의 존재 여부를 기록
//int water[50][50]; //물의 양을 기록
//CLOUD cloud[2500]; //구름의 위치를 기록
//
////방향 설정
//const int dy[] = { 0, -1, -1, -1, 0, +1, +1, +1 };
//const int dx[] = { -1, -1, 0, +1, +1, +1, 0, -1 };
//
////구름 생성
//void create_cloud(int y, int x) {
//	cloud[cloud_size].y = y;
//	cloud[cloud_size].x = x;
//	++cloud_size;
//}
//
////초기 설정
//void init_cloud() {
//	create_cloud(N - 2, 0);
//	create_cloud(N - 2, 1);
//	create_cloud(N - 1, 0);
//	create_cloud(N - 1, 1);
//}
//
////1. 구름 이동
//void move_cloud(int d, int s) {
//	//아주 큰 음수가 될 수 있으므로 항상 양수로 바꿈
//	int dist_y = (dy[d] * s) + (N * 50);
//	int dist_x = (dx[d] * s) + (N * 50);
//	//모든 구름의 이동, 구름의 좌표를 변경
//	for (int i = 0; i < cloud_size; ++i) {
//		cloud[i].y = (dist_y + cloud[i].y) % N;
//		cloud[i].x = (dist_x + cloud[i].x) % N;
//	}
//}
//
////2. 구름이 있는 칸의 바구니에 물의 양이 1 증가
//void increase_water() {
//	for (int i = 0; i < cloud_size; ++i) {
//		++water[cloud[i].y][cloud[i].x];
//	}
//}
//
////3. 구름 삭제
//void delete_cloud() {
//	memset(cloud_map, 0, sizeof(cloud_map)); //0으로 초기화
//	for (int i = 0; i < cloud_size; ++i) {
//		cloud_map[cloud[i].y][cloud[i].x] = 1; //구름의 위치 기록
//	}
//	cloud_size = 0;
//}
//
////4. 물복사 버그 사용
//void copy_bug() {
//	int increase_water[50][50] = { 0, }; //추가된 물의 양
//	for (int y = 0; y < N; ++y) {
//		for (int x = 0; x < N; ++x) {
//			if (cloud_map[y][x] == 1) {
//				int count = 0;
//				for (int d = 1; d < 8; d += 2) { //대각선만
//					int ny = y + dy[d];
//					int nx = x + dx[d];
//					if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
//						continue;
//					}
//					//물이 있는 바구니의 수만큼 물의 양이 증가
//					if (water[ny][nx] >= 1) {
//						++count;
//					}
//				}
//				increase_water[y][x] += count; //증가시킬 수 있는 물의 양
//			}
//		}
//	}
//
//	for (int y = 0; y < N; ++y) {
//		for (int x = 0; x < N; ++x) {
//			water[y][x] += increase_water[y][x]; //나중에 따로 더함
//		}
//	}
//}
//
//void generate_cloud() {
//	for (int y = 0; y < N; ++y) {
//		for (int x = 0; x < N; ++x) {
//			if (water[y][x] >= 2 && cloud_map[y][x] == 0) {
//				create_cloud(y, x);
//				water[y][x] -= 2;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> N >> M;
//	
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < N; ++j) {
//			cin >> water[i][j];
//		}
//	}
//
//	init_cloud();
//	int d, s;
//	for (int i = 0; i < M; ++i) {
//		cin >> d >> s;
//		move_cloud(d - 1, s);
//		increase_water();
//		delete_cloud();
//		copy_bug();
//		generate_cloud();
//	}
//
//	int ret = 0;
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < N; ++j) {
//			ret += water[i][j];
//		}
//	}
//	cout << ret << "\n";
//
//	return 0;
//}
