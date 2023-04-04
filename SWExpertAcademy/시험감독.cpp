#include <iostream>
#include <array>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, B, C, val, num = 0;
	long long cnt = 0;
	cin >> N;
	
	//응시장 정보를 기준으로 배열 동적 할당
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//각 감독관이 감시할 수 있는 응시자의 수
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		val = arr[i];
		//총 감독관이 반드시 존재한다는 점을 간과
		val -= B; cnt++;
		//남은 응시자가 있으면
		if (val > 0) {
			cnt += val / C; val = val % C; //몫과 나머지
			if (val != 0) cnt++; //나머지가 존재, cnt + 1
		}
	}

	cout << cnt << "\n";

	return 0;
}