#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int ans = 0;

    while(true){
        if(N == 0) break; //0이 되면, 종료

        string tmp = to_string(N);
        int idx = -1;

        for(int i = 0; i < tmp.size(); ++i){
            if(tmp[i] == '1'){ idx = i; break; }
        }

        if(idx != -1){
            // 1을 잘라주도록 함, substr(문자열, 시작위치, 길이)
            tmp = tmp.substr(0, idx) + tmp.substr(idx + 1, tmp.size() - (idx + 1));
            N = 0;
            for(int i = 0; i < tmp.size(); ++i){ N = N * 10 + tmp[i] - '0'; }
        }
        else{ N--; }

        ans++;
    }

    cout << ans << "\n";

    return 0;
}