#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int m;
    vector<char> v;
    vector<char>::iterator it;
    char cmd;
    char param;

    it = v.begin(); //위치를 가리키는 iterator

    cin >> str;
    cin >> m;

    for(int i = 0; i < str.size(); i++){
        v.push_back(str[i]);
    }

    //stack을 활용해서 재풀이

    while(m--){
        cin >> cmd;
        if(cmd == 'P'){
            cin >> param;
            v.insert(it, param); //iterator 위치에 param 삽입
        }
        if(cmd == 'L'){
            if(it != v.begin()){ it = it - 1; }
        }
        if(cmd == 'D'){
            if(it != v.end()){ it = it + 1; }
        }
        if(cmd == 'B'){
            if(it != v.begin()){ v.erase(it); }
        }
    }

    return 0;

}