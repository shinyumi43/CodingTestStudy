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
//		//1. 회전
//		BLOCK temp = belt[2 * n - 1];
//		for (int i = 2 * n - 1; i >= 1; --i) {
//			belt[i] = belt[i - 1];
//		}
//		belt[0] = temp;
//
//		//단, 회전 후 로봇이 내리는 위치에 있을 경우에 false로 변경
//		if (belt[n - 1].robot == true) { belt[n - 1].robot = false; }
//
//		//2. 벨트 위 로봇 이동
//		for (int i = n - 2; i >= 0; --i) {
//			if (belt[i].robot == true && belt[i + 1].robot == false && belt[i + 1].level > 0) {
//				belt[i].robot = false; //로봇이 이동했기 때문에 false
//				belt[i + 1].robot = true;
//				belt[i + 1].level--;
//				if (belt[i + 1].level == 0) { count++; } //내구도가 -1, 0이 될 경우에 +1
//			}
//		}
//
//		//단, 이동 후 로봇이 내리는 위치에 있을 경우에 false로 변경
//		if (belt[n - 1].robot == true) { belt[n - 1].robot = false; }
//
//		//3. 올리는 위치에 로봇 올림
//		if (belt[0].level > 0 && belt[0].robot == false) {
//			belt[0].robot = true; belt[0].level--;
//			if (belt[0].level == 0) { count++; } //내구도가 -1, 0이 될 경우에 +1
//		}
//
//		//4. 단계를 증가
//		ret++;
//	}
//
//	std::cout << ret << "\n";
//
//	return 0;
//}