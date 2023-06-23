#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//문제
//1차원 도로에 건초더미를 배치, 적절히 배치되었는지 확인하기 위해 쿼리에 대답
//길을 따라 특정 간격 내에 있는 건초더미의 수를 묻고 있음

//입력
//첫 번째 줄 N, Q
//다음 줄 N개의 개별 정수가 포함됭 있으며, 각 위치에 건초 더미가 있음을 나타냄
//Q행에는 각각 두 개의 정수 A와 B가 포함되어 A와 B 사이의 건초 더미 수에 대한 쿼리를 제공

//출력
//각 쿼리에 대한 건초더미의 수를 출력

int main(){
    //메모리 초과
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, Q;
    cin >> N >> Q;

    vector<long long> tmp;
    long long cmd;
    for(long long i = 0; i < N; ++i){
        cin >> cmd;
        tmp.push_back(cmd);
    }

    sort(tmp.begin(), tmp.end());

    // long long point = 0;
    // vector<long long> v;
    // for(long long i = 0; i < tmp.size(); ++i){
    //     long long temp = tmp[i];
    //     for(long long j = point; j < temp; ++j){
    //         v.push_back(0);
    //     }
    //     v.push_back(1);
    //     point = temp + 1;
    // }

    // long long start, end;
    // for(long long i = 0; i < Q; ++i){
    //     long long ans = 0;
    //     cin >> start >> end;
    //     for(long long j = start; j <= end; ++j){
    //         if(v[j] == 1) { ans += 1; }
    //     }
    //     cout << ans << "\n";
    // }
    

    return 0;
}