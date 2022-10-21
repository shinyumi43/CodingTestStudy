#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, m, min, res;
    cin >> n >> m;

    res = 0;
    for(int i = 0; i < n; i++){
        vector<int> vec(m);

        for(int j = 0; j < m; j++){
            cin >> vec[j];
        }

        min = *min_element(vec.begin(), vec.end()); // vector 내에서 최솟값 찾기
        res = max(res, min); // 각 행의 최솟값과 비교
    }
    
    cout << res;
    return 0;
}