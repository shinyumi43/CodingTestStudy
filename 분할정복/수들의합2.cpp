#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, l = 0, r = -1, cnt = 0, sum = 0;
    cin >> n >> m;

    vector<int> v(n); //사이즈에 따른 vector를 생성
    for(int i = 0; i < v.size(); i++){
        cin >> v[i];
    }

    for(int l = 0; l < n; l++){ //left가 n-1에 도달할 때까지
        while(r < n && sum < m) r++, sum += v[r]; //합이 m보다 작고, m보다 작을 때까지 더함
        if(sum == m) cnt++; //합이 m과 같으면, 경우의 수를 하나 추가
        sum -= v[l]; //합이 m보다 크면, v[l]을 빼고 left를 1칸 이동
    }

    // 시간 복잡도가 커지기 때문에 불가능
    // while(true){
    //     if(r == n - 1 && l == n - 1){ break; } //끝에 도달하면, 나가기

    //     for(int i = l; i < r + 1; i++){
    //         sum += v[i]; //left ~ right까지의 합을 도출
    //     }

    //     if(sum < m){ r++; } //m보다 작으면, right를 1칸 이동
    //     else if(sum > m) { l++;} //m보다 크면, left를 1칸 이동
    //     else{ cnt++; } //m과 같으면, 경우의 수를 하나 추가

    //     sum = 0; //sum을 초기화
    // }
    
    cout << cnt << "\n";
    return 0;

}