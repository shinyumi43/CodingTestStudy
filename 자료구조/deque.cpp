#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int param;
    string str;
    deque<int> dq;

    cin >> n;

    while(n--){
        cin >> str;
        if(str == "push_front"){
            cin >> param;
            dq.push_front(param);
        }
        if(str == "push_back"){
            cin >> param;
            dq.push_back(param);
        }
        if(str == "size"){
            cout << dq.size() << "\n";
        }
        if(str == "empty"){
            cout << dq.empty() << "\n";
        }
        if(str == "front"){
            if(dq.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << dq.front() << "\n";
            }
        }
        if(str == "back"){
            if(dq.empty()){
                cout << "-1" << "\n";
            }
            else{
                cout << dq.back() << "\n";
            }
        }
        if(str == "pop_front"){
            if(dq.empty()){
                 cout << "-1" << "\n";
            }
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        if(str == "pop_back"){
            if(dq.empty()){
                 cout << "-1" << "\n";
            }
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
    }

    return 0;
}


