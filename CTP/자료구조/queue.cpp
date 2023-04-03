#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string str;
    int param;
    queue<int> q;
    cin >> n;

    while(n--){
        cin >> str;
        if(str == "push"){
            cin >> param;
            q.push(param);
        }
        if(str == "size"){
            cout << q.size() << "\n";
        }
        if(str == "empty"){
            cout << q.empty() << "\n";
        }
        if(str == "front"){
            if(q.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << q.front() << "\n";
            }
        }
        if(str == "back"){
            if(q.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << q.back() << "\n";
            }
        }
        if(str == "pop"){   
            if(q.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << q.front() << "\n";
                q.pop(); //먼저 front로 빼준 뒤에 pop을 진행
            }
        }
    }
    
    return 0;
}
using namespace std;

int main(){
    int n;
    string str;
    int param;
    queue<int> q;
    cin >> n;

    while(n--){
        cin >> str;
        if(str == "push"){
            cin >> param;
            q.push(param);
        }
        if(str == "size"){
            cout << q.size() << "\n";
        }
        if(str == "empty"){
            cout << q.empty() << "\n";
        }
        if(str == "front"){
            if(q.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << q.front() << "\n";
            }
        }
        if(str == "back"){
            if(q.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << q.back() << "\n";
            }
        }
        if(str == "pop"){   
            if(q.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << q.front() << "\n";
                q.pop(); //먼저 front로 빼준 뒤에 pop을 진행
            }
        }
    }
    
    return 0;
}