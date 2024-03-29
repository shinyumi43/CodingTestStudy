#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int n, m;
int arr[MAX] = {0, };
bool visited[MAX] = {0, };

void dfs(int num, int idx){
    if(idx == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = num; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[idx] = i;
            dfs(i + 1, idx + 1);
            visited[i] = false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    //주어진 자연수 n, m
    cin >> n >> m;

    dfs(1, 0);

    return 0;
}