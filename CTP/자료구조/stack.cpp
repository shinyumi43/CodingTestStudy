#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string str;
    int param;
    stack<int> st;

    cin >> n;

    while(n--){
        cin >> str;
        if(str == "push"){
            cin >> param;
            st.push(param); //스택에 값을 삽입
        }
        if(str == "size"){
            cout << st.size() << "\n"; //스택 내 값의 개수를 반환 
        }
        if(str == "empty"){
            cout << st.empty() << "\n"; //비어있는지 여부 확인
        }
        if(str == "top"){
            if(st.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << st.top() << "\n";
            }
        }
        if(str == "pop"){
            if(st.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << st.top() << "\n";
                st.pop(); //반환값이 따로 없기 때문에 pop으로 지우는 과정만 처리
            }
        }
    }

    return 0;
}