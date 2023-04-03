#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, num, index, value, count;
    cin >> n;
    deque<pair<int, int>> dq;

    for(int i = 0; i < n; i++){
        cin >> num;
        dq.push_back({i+1, num});
    }

    while(!dq.empty()){
        //index, value의 pair
        int index = dq.front().first;
        int value = dq.front().second;
        dq.pop_front();
        cout << index << " ";

        if(value > 0){ //양수, 오른쪽 이동, 앞에 빼고 뒤로, 정방향 -1
            count = value - 1;
            while(count--){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{ //음수, 왼쪽 이동, 뒤에 빼고 앞으로, 역방향 그대로
            count = abs(value);
            while(count--){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}