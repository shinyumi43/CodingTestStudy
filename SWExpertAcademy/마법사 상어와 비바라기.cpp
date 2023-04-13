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
//int cloud_size; //������ ũ��
//int cloud_map[50][50]; //������ ���� ���θ� ���
//int water[50][50]; //���� ���� ���
//CLOUD cloud[2500]; //������ ��ġ�� ���
//
////���� ����
//const int dy[] = { 0, -1, -1, -1, 0, +1, +1, +1 };
//const int dx[] = { -1, -1, 0, +1, +1, +1, 0, -1 };
//
////���� ����
//void create_cloud(int y, int x) {
//	cloud[cloud_size].y = y;
//	cloud[cloud_size].x = x;
//	++cloud_size;
//}
//
////�ʱ� ����
//void init_cloud() {
//	create_cloud(N - 2, 0);
//	create_cloud(N - 2, 1);
//	create_cloud(N - 1, 0);
//	create_cloud(N - 1, 1);
//}
//
////1. ���� �̵�
//void move_cloud(int d, int s) {
//	//���� ū ������ �� �� �����Ƿ� �׻� ����� �ٲ�
//	int dist_y = (dy[d] * s) + (N * 50);
//	int dist_x = (dx[d] * s) + (N * 50);
//	//��� ������ �̵�, ������ ��ǥ�� ����
//	for (int i = 0; i < cloud_size; ++i) {
//		cloud[i].y = (dist_y + cloud[i].y) % N;
//		cloud[i].x = (dist_x + cloud[i].x) % N;
//	}
//}
//
////2. ������ �ִ� ĭ�� �ٱ��Ͽ� ���� ���� 1 ����
//void increase_water() {
//	for (int i = 0; i < cloud_size; ++i) {
//		++water[cloud[i].y][cloud[i].x];
//	}
//}
//
////3. ���� ����
//void delete_cloud() {
//	memset(cloud_map, 0, sizeof(cloud_map)); //0���� �ʱ�ȭ
//	for (int i = 0; i < cloud_size; ++i) {
//		cloud_map[cloud[i].y][cloud[i].x] = 1; //������ ��ġ ���
//	}
//	cloud_size = 0;
//}
//
////4. ������ ���� ���
//void copy_bug() {
//	int increase_water[50][50] = { 0, }; //�߰��� ���� ��
//	for (int y = 0; y < N; ++y) {
//		for (int x = 0; x < N; ++x) {
//			if (cloud_map[y][x] == 1) {
//				int count = 0;
//				for (int d = 1; d < 8; d += 2) { //�밢����
//					int ny = y + dy[d];
//					int nx = x + dx[d];
//					if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
//						continue;
//					}
//					//���� �ִ� �ٱ����� ����ŭ ���� ���� ����
//					if (water[ny][nx] >= 1) {
//						++count;
//					}
//				}
//				increase_water[y][x] += count; //������ų �� �ִ� ���� ��
//			}
//		}
//	}
//
//	for (int y = 0; y < N; ++y) {
//		for (int x = 0; x < N; ++x) {
//			water[y][x] += increase_water[y][x]; //���߿� ���� ����
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
