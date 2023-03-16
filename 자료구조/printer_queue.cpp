#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false); //속도 향상

    int t, n, m, num, cnt;
    cin >> t; //test case 수
    
    while(t--){
        cin >> n >> m;
        cnt = 0; //test case 기준으로 cnt를 초기화

        priority_queue<int> pq; //priority queue, 내림차순, 중요도 순 프린트 순서
        queue<pair<int, int>> q; //문서 위치, 중요도 값의 pair queue

        for(int i = 0; i < n; i++){
            cin >> num;
            q.push({i, num}); //index, importance pair
            pq.push(num); //importance 기준 queue
        }

        while(!q.empty()){
            int index = q.front().first;
            int value = q.front().second;
            q.pop(); //1. importance 확인

            if(pq.top() == value) { //2. 현재 문서의 importance가 가장 높다면, 인쇄 진행
                pq.pop(); //가장 높은 importance 제거
                cnt++;
                if(index == m) { cout << cnt << "\n"; break; }
            }
            else { //현재 문서보다 중요도가 높은 문서가 존재, pq 내의 top과 다름
                q.push({index, value}); //맨 뒤로 삽입
            }
        }
    }

    return 0;
}