//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int n, m, ret;
//int map[50][50];
//
//int main() {
//	cin >> n >> m;
//	vector<pair<int, int>> home; //위치 기록
//	vector<pair<int, int>> shop;
//	vector<pair<int, int>> city; //도시의 치킨 거리
//	vector<int> min;
//
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j) {
//			cin >> map[i][j];
//			if (map[i][j] == 1) { home.push_back({ i+1, j+1 }); } //집
//			else if (map[i][j] == 2) { shop.push_back({ i+1, j+1 }); } //치킨집
//		}
//	}	
//
//	for (int i = 0; i < home.size(); ++i) {
//		int res = 0, dis_min = 0x7fffffff, min_idx = 0;
//		for (int j = 0; j < shop.size(); ++j) {
//			res = abs(home[i].first - shop[j].first)
//				+ abs(home[i].second - shop[j].second);
//			if (dis_min > res) { //값을 저장 
//				min_idx = j; 
//				dis_min = res; //가장 가까운 거리의 치킨집과 거리 정보 획득
//			}
//		}
//		city.push_back({ min_idx, dis_min });
//	}
//
//	int idx;
//	sort(city.begin(), city.end()); //first 기준 오름차순, 같을 경우 second 기준 오름차순
//	min.push_back(city[0].second); idx = city[0].first;
//	for (int i = 1; i < city.size(); ++i) {
//		if (idx != city[i].first) {
//			idx = city[i].first;
//			min.push_back(city[i].second);
//		}
//	}
//	sort(min.begin(), min.end());
//	
//	int i = 0;
//	while (m--) {
//		ret += min[i];
//		i++;
//	}
//	
//	cout << ret << "\n";
//
//	return 0;
//
//} //직접 풀이 - 정답이 아님
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct POST {
	int y, x;
};

int n, m, type, ret;
vector<POST> home, shop, pick;

void dfs(int pos) {
	if (pick.size() == m) {
		int candi = 0;

		for (int i = 0; i < home.size(); ++i) {
			int min_dist = 1000000;
			for (int j = 0; j < pick.size(); ++j) {
				min_dist = min(min_dist, abs(home[i].y - pick[j].y) +
					abs(home[i].x - pick[j].x));
			}
			candi += min_dist;
		}

		if (ret > candi) {
			ret = candi;
		}
		return;
	}

	for (int i = pos; i < shop.size(); ++i) {
		pick.push_back(shop[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}

int main() {
	POST target;
	cin >> n >> m;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> type;
			if (type == 1) { 
				target.y = y; target.x = x;
				home.push_back(target);
			}
			else if (type == 2) {
				target.y = y; target.x = x;
				shop.push_back(target);
			}
		}
	}

	ret = 0x7fffffff;
	dfs(0);
	cout << ret << "\n";

	return 0;
}