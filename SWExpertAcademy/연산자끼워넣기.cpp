#include <iostream>
using namespace std;

/*	숫자와 연산자가 input으로 주어지고
	연산자의 배치순서를 바꿔서 계산 결과에 대한 최댓값과 최솟값을 구하는 문제,
	단, 계산할 때 연산자의 우선순위는 무시되고, 앞을 기점으로 순서대로 계산,
	숫자의 최대 개수는 11이고, 연산자는 항상 숫자의 개수 보다 1개가 적음(즉, 최대 10개)

	숫자는 고정이고, 연산자의 순서만 변경될 수 있는 문제
	연산자의 종류는 총 4개(+, -, *, /)
	연산자의 종류가 다르다면, 순서 상관 있음
	연산자의 종류가 같다면, 순서 상관 없음
	위의 경우를 잘 생각해서 모든 경우를 다 만들고, 최댓값과 최솟값을 구하는 문제

	연산자의 우선순위가 무시, 앞을 기점으로 순서대로 계산
	연산자와 피연산자(숫자)가 2개 들어오면, 그때 그때 계산하고 다음 단계로
*/

//결과값 - 만들 수 있는 결과의 최댓값, 최솟값
int N;
int A[11]; //0 ~ 10, 최대 숫자의 개수 11
int op[4]; //0 ~ 9, 최대 연산자의 개수 10
int ret_min = 0x7fffffff, ret_max = -0x7fffffff;

void dfs(int result, int count) { //지금까지 계산한 result, count는 다음 항
	if (count == N - 1) { //계산을 다 마친 경우, 결과값을 도출
		if (ret_min > result) {
			ret_min = result;
		}
		if (ret_max < result) {
			ret_max = result;
		}
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (op[i] != 0) {
			--op[i]; //count를 감소
			///dfs 호출
			if (i == 0) { //+
				dfs(result + A[count + 1], count + 1);
			}
			else if (i == 1) { //-
				dfs(result - A[count + 1], count + 1);
			}
			else if (i == 2) { //*
				dfs(result * A[count + 1], count + 1);
			}
			else if (i == 3) { ///
				dfs(result / A[count + 1], count + 1);
			}
			++op[i]; //count를 증가
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> op[i]; //+, -, *, / 순서로 삽입
	}

	//현재값과 어디까지 계산했는지를 기록
	dfs(A[0], 0);

	cout << ret_max << "\n" << ret_min << "\n";

	return 0;
}