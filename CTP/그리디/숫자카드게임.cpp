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

        min = *min_element(vec.begin(), vec.end()); // vector ������ �ּڰ� ã��
        res = max(res, min); // �� ���� �ּڰ��� ��
    }
    
    cout << res;
    return 0;
}