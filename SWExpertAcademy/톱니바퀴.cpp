#include <iostream>
using namespace std;
/*
	톱니바퀴 회전 규칙
	1. 맞닿은 극이 다르면, B는 A가 회전한 방향과 반대로 회전
	2. 맞닿은 극이 같으면, B는 회전하지 않음

	N극은 0, S극은 1, -1은 반시계, 1은 시계
	10101111
	01111101
	11001110
	00000010
	2
	3 -1
	1 1

	1번 톱니 바퀴를 시계방향으로 회전시키면,
	2번 톱니 바퀴가 반 시계 방향으로 회전하게 되고,
	2번이 회전하기 때문에 3번도 동시에 시계 방향으로 회전
	4번은 3번이 회전하였지만, 맞닿은 극이 같기 때문에 회전하지 않음
*/

int main() {
	char gear[4][9]; //마지막에 /n 값으로 인해 9로 지정
	for (int i = 0; i < 4; ++i) {
		cin >> gear[i];
	}

	int k;
	cin >> k;
	while (k--) {
		int target, cmd;
		cin >> target >> cmd;
		--target; //gear index는 0123이므로 -1
		int move_cmd[4] = { 0, }; //각각의 gear와 매칭해서 어느 방향으로 움직일 것인지
		move_cmd[target] = cmd;
		//target의 left 방향의 톱니바퀴를 움직임
		for (int left = target - 1; left >= 0; --left) {
			int right = left + 1;
			if (gear[left][2] == gear[right][6]) { //극이 같으면, 움직이지 않음
				break;
			}
			else { //극이 다르면, right의 방향과 반대로 움직임
				move_cmd[left] = move_cmd[right] * -1;
			}
		}
		//target의 right 방향의 톱니바퀴를 움직임
		for (int right = target + 1; right < 4; ++right) {
			int left = right - 1;
			if (gear[left][2] == gear[right][6]) { //극이 같으면, 움직이지 않음
				break;
			}
			else { //극이 다르면, left의 방향과 반대로 움직이도록
				move_cmd[right] = move_cmd[left] * -1;
			}
		}

		for (int i = 0; i < 4; ++i) {
			if (move_cmd[i] == 1) { //시계 방향으로 움직여야 하는 경우
				char temp = gear[i][7]; //back-up 후 덮어쓰기
				for(int j = 7; j >= 1; --j){ //7-6, 6-5, 5-4 ... 1-0
					gear[i][j] = gear[i][j - 1];
				}
				gear[i][0] = temp; //0-7
			}
			else if (move_cmd[i] == -1) { //반시계 방향으로 움직여야 하는 경우
				char temp = gear[i][0]; //back-up 후 덮어쓰기
				for (int j = 0; j < 7; ++j) { //0-1, 1-2, 2-3 ... 6-7
					gear[i][j] = gear[i][j + 1];
				}
				gear[i][7] = temp; //7-0
			}
		}
	}
	
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		if (gear[i][0] == '1') { //점수 계산을 위해 shift 연산을 활용
			ret += (1 << i);
		}
	}
	cout << ret << "\n";
	return 0;
}