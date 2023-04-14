////최대 N이 499인 2차원 공간에 각 칸의 모래의 양이 input으로 주어짐
////정해진 규칙에 의해서 토네이도가 이동
////토네이도에 의해 정해진 규칙대로 모래가 이동
////토네이도의 이동이 종료되었을 때, 공간 밖으로 나간 모래의 양의 합을 출력하는 문제*/
////
////토네이도의 이동
////시작점은 항상 cy = N / 2, cx = N / 2로 중앙
////토네이도는 아래 순서로 이동, left -> down -> right -> up
////매순간 방향을 바꾸면, 쉽게 구현할 수 있음
////visited[][] 배열을 이용해서 이동 가능하다면 이동을 진행
////
////토네이도의 이동에 따른 모래의 이동
////토네이도의 이동 4방향에 따른 y위치를 기준으로 y'의 모래가 이동하는 table을 구현
////어떤 규칙이 있고, 그 규칙을 어떻게 코드로 만들어낼 수 있는지
//
///*
//* left, 중심점을 기준으로 table을 기록
//index  0   1   2   3   4    5   6   7   8
//dy	  -1   1  -2   2   0   -1   1  -1   1
//dx	   1   1   0   0  -2    0   0  -1  -1
//rate   1   1   2   2   5    7   7  10  10
//*/
//
//#include <iostream>
//using namespace std;
//
//int N;
//int A[499][499];
//
////이동하는 순서, left - down - right - up
//int dy[] = { 0, 1, 0, -1 };
//int dx[] = { -1, 0, 1, 0 };
//
////모래가 흩날리는 위치, y 기준
//int windy[4][9] = {
//	{-1, 1, -2, 2, 0, -1, 1, -1, 1}, //left
//	{-1, -1, 0, 0, 2, 0, 0, 1, 1}, //down
//	{1, -1, 2, -2, 0, 1, -1, 1, -1}, //right
//	{1, 1, 0, 0, -2, 0, 0, -1, -1} //up
//};
//
////모래가 흩날리는 위치, x 기준
//int windx[4][9] = {
//	{1, 1, 0, 0, -2, 0, 0, -1, -1}, //left
//	{-1, 1, -2, 2, 0, -1, 1, -1, 1}, //down
//	{-1, -1, 0, 0, 2, 0, 0, 1, 1}, //right
//	{1, -1, 2, -2, 0, 1, -1, 1, -1} //up
//};
//
////흩날린 위치에서 모래의 양
//int rate[9] = { 1, 1, 2, 2, 5, 7, 7, 10, 10 };
//
////격자의 밖으로 나간 모래의 양을 계산
//int wind(int cy, int cx, int dir) {
//	int ret = 0;
//	int sand = A[cy][cx]; //원본 sand
//	int sum = 0;
//	for (int i = 0; i < 9; ++i) { //9개의 방향을 돌면서
//		int ny = cy + windy[dir][i]; //dir은 left, down, right, up을 의미
//		int nx = cx + windx[dir][i];
//		//공간에 얼마 만큼의 모래가 들어가야 하는지를 저장
//		int wind_sand = (sand * rate[i]) / 100; //원본 sand에 rate를 곱하고 100으로 나눔, 이 sand 만큼 이동
//		sum += wind_sand; //비율이 적힌 칸으로 이동한 모래의 양
//		if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
//			ret += wind_sand; //map 밖으로 나갔다면, 그 나간 모래의 양을 더함
//			continue;
//		}
//		A[ny][nx] += wind_sand; //map 밖으로 나가지 않았다면, 이동할 곳에 sand를 보냄
//	}
//	//a의 위치를 파악
//	int ny = cy + dy[dir];
//	int nx = cx + dx[dir];
//	int a = (sand - sum); //비율이 적힌 칸으로 이동하지 않은 남은 모래의 양
//	if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
//		ret += a; //map 밖으로 나갔다면, 그 나간 모래의 양을 더함
//	}
//	else {
//		A[ny][nx] += a; //map 밖으로 나가지 않았다면, 이동할 곳에 sand를 보냄
//	}
//
//	return ret;
//}
//
////토네이도의 이동
//int solve(int cy, int cx) {
//	int ret = 0;
//	bool visited[499][499] = { false, };
//	int dir = -1; //초기 이동 방향은 -1, left
//	
//	while ((cy != 0) || (cx != 0)) { //토네이도가 소멸하기 전까지
//		visited[cy][cx] = true;
//		int nd = (dir + 1) % 4;
//		int ny = cy + dy[nd]; //다음 (y, x) 위치
//		int nx = cx + dx[nd];
//		if (visited[ny][nx] == true) { //이미 이전에 방문
//			nd = dir; //이동하는 방향으로 1번 더 이동
//			ny = cy + dy[nd];
//			nx = cx + dx[nd];
//		}
//		ret += wind(ny, nx, nd); //격자의 밖으로 나간 모래의 양 더하기
//		cy = ny, cx = nx, dir = nd; //위치 갱신
//	}
//
//	return ret;
//}
//
//int main() {
//
//	cin >> N;
//
//	for (int y = 0; y < N; ++y) {
//		for (int x = 0; x < N; ++x) {
//			cin >> A[y][x];
//		}
//	}
//
//	int cy = N / 2;
//	int cx = N / 2;
//	int ret = solve(cy, cx);
//
//	cout << ret << "\n";
//	return 0;
//}
//
//
