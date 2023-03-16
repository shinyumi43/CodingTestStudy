#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<char> left;
    stack<char> right;
    deque<char> print;

    string str;
    char cmd, ch;
    int m, n;

    cin >> str >> m;

    for(int i = 0; i < str.size(); i++){
        left.push(str[i]); //cursor 맨 뒤에 위치, left stack에 문자열 전부 삽입
    }

    while(m--){
        cin >> cmd;
        if(cmd == 'L'){
            if(left.empty()) continue; //cursor가 문장의 맨 앞, left stack 빈 상태
            else { 
                ch = left.top(); //left stack의 top을 right stack으로 push
                left.pop();

                right.push(ch);
            }
        }
        if(cmd == 'D'){
            if(right.empty()) continue; //cursor가 문장의 맨 뒤, right stack이 빈 상태
            else{
                ch = right.top();
                right.pop();

                left.push(ch);
            }
        }
        if(cmd == 'B'){
            if(left.empty()) continue;
            else left.pop(); //left에 있는 top을 삭제
        }
        if(cmd == 'P'){
            cin >> ch;
            left.push(ch); //문자를 left stack에 추가
        }
    }

    n = left.size();
    while(n--){
        ch = left.top();
        left.pop();
        print.push_front(ch); //역방향으로 들어있기 때문에 front 방향 삽입
    }

    n = right.size();
    while(n--){
        ch = right.top();
        right.pop();
        print.push_back(ch); //정방향으로 들어있기 때문에 back 방향 삽입
    }

    for(int i = 0; i < print.size(); i++){
        cout << print[i];
    }
    cout << "\n";

    return 0;

}