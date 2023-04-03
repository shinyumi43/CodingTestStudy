#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string cmd;
    char ch;

    cin >> t;

    bool check;

    while(t--){
        stack<char> left; //"("
        stack<char> right; //")"
        check = true; //초기화
        
        cin >> cmd;
        
        for(int i = 0; i < cmd.size(); i++){
            ch = cmd[i];
            if(ch == '(') left.push(ch);
            if(ch == ')') right.push(ch);

            if(left.size() < right.size()) { check = false; } //무조건 "("가 선행
        }

        if(left.size() == right.size() && check){ cout << "YES" << "\n"; }
        else { cout << "NO" << "\n"; }
    }

    return 0;

}