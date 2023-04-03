#include <bits/stdc++.h>
using namespace std;


//재귀함수
int recursion(const char *s, int l, int r){
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else {
        return recursion(s, l+1, r-1);
    }
}

//재귀함수를 호출하는 횟수
int count_recursion(const char *s, int l, int r, int cnt){
    if(l >= r) { return cnt; }
    else if(s[l] != s[r]) { return cnt; }
    else { return count_recursion(s, l+1, r-1, ++cnt); }
}

//앞에서 읽었을 때와 뒤에서 읽었을 때가 같은 문자열인지 확인
int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int isCount(const char *s, int cnt){
    return count_recursion(s, 0, strlen(s)-1, ++cnt);
}

//recursive하는 횟수
int main() {
    int T;
    string S;

    cin >> T;

    while(T--){
        cin >> S;
        cout << isPalindrome(S.c_str()) << " " << isCount(S.c_str(), 0) << "\n";
    }

    return 0;
}