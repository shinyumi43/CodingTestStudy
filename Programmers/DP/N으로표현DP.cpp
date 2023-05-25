#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(int N, int number){
    int answer = -1;
    unordered_set<int> s[8]; //중복제거가 필요하므로 unordered_set을 활용

    int sum = 0;
    for(int i = 0; i < 8; ++i){
        sum = sum * 10 + N;
        s[i].insert(sum);
    }

    for(int i = 1; i < 8; ++i){
        for(int j = 0; j < i; ++j){
            for(int a : s[j]){ //s[3] = s[2] U s[0], s[1] U s[1], s[0] U s[2]
                for(int b : s[i-j-1]){
                    s[i].insert(a+b);
                    s[i].insert(a-b);
                    s[i].insert(a*b);
                    if(b != 0){ s[i].insert(a/b); }
                }
            }
        }
    }

    for(int i = 0; i < 8; ++i){
        if(s[i].find(number) != s[i].end()){
            answer = i + 1;
            break;
        }
    }

    return answer;
}

int main(){
    cout << solution(5, 12) << "\n";
    return 0;
}