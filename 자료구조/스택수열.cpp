#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    stack<int> stk; //stack
    vector<char> res; //+, -
    int n, num, cnt = 1;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num;
        
        while(cnt <= num) { //작거나 같을 때까지 삽입
            stk.push(cnt);
            cnt++;
            res.push_back('+');
        }
        if(stk.top() == num){ //top 숫자만 가질 수 있으면 통과
            stk.pop();
            res.push_back('-');
        }
        else{ //top에서 다음에 올 수열의 수를 가질 수 없으면 실패
            cout << "NO" << "\n";
            return 0;
        }
    }

    for(auto ch : res) {
        cout << ch << "\n";
    }

    return 0;

}