//#include <iostream>
//using namespace std;
//
//struct BLOCK
//{	
//	int level;
//	bool robot;
//};
//
//int n, k, ret;
//BLOCK belt[200];
//
//int main() {
//	cin >> n >> k;
//	
//	int cmd;
//	for (int i = 0; i < 2 * n; ++i) {
//		cin >> cmd;
//
//		BLOCK block;
//		block.level = cmd; block.robot = false;
//		belt[i] = block;
//	}
//
//	int count = 0;
//	while (count < k) {
//		//1. ȸ��
//		BLOCK temp = belt[2 * n - 1];
//		for (int i = 2 * n - 1; i >= 1; --i) {
//			belt[i] = belt[i - 1];
//		}
//		belt[0] = temp;
//
//		//��, ȸ�� �� �κ��� ������ ��ġ�� ���� ��쿡 false�� ����
//		if (belt[n - 1].robot == true) { belt[n - 1].robot = false; }
//
//		//2. ��Ʈ �� �κ� �̵�
//		for (int i = n - 2; i >= 0; --i) {
//			if (belt[i].robot == true && belt[i + 1].robot == false && belt[i + 1].level > 0) {
//				belt[i].robot = false; //�κ��� �̵��߱� ������ false
//				belt[i + 1].robot = true;
//				belt[i + 1].level--;
//				if (belt[i + 1].level == 0) { count++; } //�������� -1, 0�� �� ��쿡 +1
//			}
//		}
//
//		//��, �̵� �� �κ��� ������ ��ġ�� ���� ��쿡 false�� ����
//		if (belt[n - 1].robot == true) { belt[n - 1].robot = false; }
//
//		//3. �ø��� ��ġ�� �κ� �ø�
//		if (belt[0].level > 0 && belt[0].robot == false) {
//			belt[0].robot = true; belt[0].level--;
//			if (belt[0].level == 0) { count++; } //�������� -1, 0�� �� ��쿡 +1
//		}
//
//		//4. �ܰ踦 ����
//		ret++;
//	}
//
//	std::cout << ret << "\n";
//
//	return 0;
//}