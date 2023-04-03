#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s, str;
    int length;
    vector<string> v;

    cin >> s;
    length = s.size();

    for(int i = 0; i < length; i++){
        str = s.substr(i, length); //문자열 부분 자르기
        v.push_back(str);
    }

    sort(v.begin(), v.end()); //sort를 진행

    for(int i = 0; i < length; i++){
        cout << v[i] << "\n";
    }

    return 0;

}