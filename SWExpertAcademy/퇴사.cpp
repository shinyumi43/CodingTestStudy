//#include <iostream>
//#include <algorithm>
//using namespace std;
///*
//	DP ������� ����
//	DP[day] = max(DP[day + 1], DP[day + T[day]] + P[day])
//	day���� �����ؼ� ����ϱ��� �ִ� ���� DP[day]�� ����
//	DP[day]�� �� ���� �߿� �ִ��� ����
//	������ ������ �ϴ� ���, DP[day + T[day]] + P[day], ������ ��ȭ�����Ƿ� P[day]�� ����
//	������ ������ ���� �ʴ� ���, DP[day + 1]
//
//	��� Ǯ �� ������?
//
//	0  1  2  3  4  5  6
//  T 3  5  1  1  2  3  2
//  P 10 20 10 20 15 40 200
//	
//	max(������ ��ȭ���� �ʴ� ���, ������ ��ȭ�ϴ� ���) �� �ִ� ��ȯ
//
//	solve(0) = max(solve(1), solve(0 + 3) + 10) = max(45, 45) = 45
//		solve(1) = max(solve(2), solve(1 + 5) + 20) = max(45, 20) = 45
//			solve(2) = max(solve(3), solve(2 + 1) + 10) = max(35, 45) = 45
//				solve(3) = max(solve(4), solve(3 + 1) + 20) = max(15, 35) = 35
//					solve(4) = max(solve(5), solve(4 + 2) + 15) = max(0, 15) = 15
//						solve(5) = max(solve(6), solve(5 + 3) + 40) = max(0, -10000...) = 0
//							solve(6) = max(solve(7), solve(6 + 2) + 200) = max(0, -10000...) = 0
//								solve(7) = 0 //���
//									solve(8) = -1000000...
//*/
//
//int n;
//int t[15], p[15];
//int res[15];
//
//int solve(int day) {
//	if (day > n) return -987654321;
//	if (day == n) return 0;
//
//	int ret = res[day];
//	if (ret != -1) return ret; //������ ������ ���, �״�� ���� return
//
//	ret = max(solve(day + 1), solve(day + t[day]) + p[day]); //������ �ʾ��� ���, �ִ밪�� ��ȯ
//	return ret;
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> t[i] >> p[i];
//		res[i] = -1;
//	}
//
//	int ret = solve(0); //0���� 1�Ϸ� �����ϰ�, ����
//	cout << ret << "\n";
//	return 0;
//}
