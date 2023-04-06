#include <iostream>
#include <algorithm>
using namespace std;
/*
	어떻게 풀 수 있을지
	N명의 사람 중에 N/2명을 뽑고,
	팀은 뽑힌 사람은 모두 동일한 팀이고,
	뽑히지 않은 사람은 모두 동일한 팀으로 생각

	모든 경우의 팀을 조합하는 경우의 수, nCn/2
	20 * 19 * 18 * ... / (10 * 9 * 8 * 7 ..) = 184756

	조합된 경우의 수마다 점수를 계산하기 위해서 N/2 * N/2의 연산이 필요
	10 * 10 = 100
	
	총 연산의 양은 18475600, 2천만 보다 작으므로 충분히 가능

	a와 b가 같은 팀을 할 때 추가되는 능력치는 아래와 동일
	table[a][b] + table[b][a]

	만약 team1과 team2가 있다고 가정하면,
	table[team1의 멤버 모두][team1의 멤버 모두]를 더한 것이 team1의 능력치
	table[team2의 멤버 모두][team2의 멤버 모두]를 더한 것이 team2의 능력치
	team1의 멤버 모두를 중첩해서 비교해야 하기 때문에 2차 for문이 필요
	이때 팀원의 최대 명수가 10명이기 때문에 10 * 10

6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0
*/

int N, ret;
int S[20][20]; //N의 최대가 20, 값은 100보다 작거나 같음
int start[10], link[10]; //팀에 들어간 멤버의 정보
int pick[20]; //선수를 뽑아야 하기 때문에 설정

void update() {
	//뽑은 멤버는 link팀, 뽑지 않은 멤버는 start팀으로 분류
	int start_size = 0, link_size = 0;
	for (int i = 0; i < N; ++i) { //인덱스를 기준으로 분류
		if (pick[i] == 0) { start[start_size++] = i; }
		else { link[link_size++] = i; }
	}
	
	int start_sum = 0, link_sum = 0;
	for (int i = 0; i < N / 2; ++i) {
		for (int j = i + 1; j < N / 2; ++j) {
			start_sum += (S[start[i]][start[j]] + S[start[j]][start[i]]);
			link_sum += (S[link[i]][link[j]] + S[link[j]][link[i]]);
		}
	}

	//지속적으로 최솟값을 업데이트
	if (ret > abs(start_sum - link_sum)) {
		ret = abs(start_sum - link_sum);
	}
}

void dfs(int cur, int pick_count) { //조합을 생성하는 함수
	if (pick_count == N / 2) { //pick_count는 몇명을 뽑았는지를 의미
		update();
		return; //점수를 계산해야 하는 타이밍
	}

	for (int i = cur; i < N; ++i) {
		pick[i] = 1; //뽑았다면, 1
		dfs(i + 1, pick_count + 1);
		pick[i] = 0; //다시 돌아오면, 뽑지 않은 것으로 표시
	}
}

int main() {
	cin >> N; //N은 짝수

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> S[i][j];
		}
	}

	ret = 0x7fffffff;
	dfs(0, 0); //n개 중에서 m개 뽑아야 하기 때문에 dfs 함수를 활용
	cout << ret << "\n";

	return 0;
}
