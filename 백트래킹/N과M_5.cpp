#include <bits/stdc++.h>
using namespace std;
#define MAX 10

//back-tracking
int n, m;
int arr[MAX] = {0, }; //print
bool visited[MAX] = {0, }; //visit
vector<int> v;

//DFS
void dfs(int d){
    if(d == m) {
        for(int i = 0; i < m; i++){
            cout << arr[i]; //저장된 수열을 print
            if(i != m - 1) { cout << " "; }
        }
        cout << "\n";
        return;
    }
    for(int i = arr[d - 1] + 1; i <= n; i++){
        if(visited[i] == true) continue; //이미 사용, sub node는 사용할 필요 없음
        arr[d] = v[i]; //실제값 담기
        visited[i] = true; //사용, 진입 전과 후가 같도록
        dfs(d + 1); //다음 depth로 진입
        visited[i] = false; //사용 후 다시 되돌리기
    }
    return;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    v.push_back(0); //index 0
    for(int i = 1; i <= n; i++){ v.push_back(i); } // 0 1 2 3 4 ...

    dfs(0); //depth는 0을 기준으로 시작, d == m이 base이므로

    return 0;
}