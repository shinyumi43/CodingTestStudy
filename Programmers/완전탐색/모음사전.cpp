#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string temp; //임시 문자열
vector<string> res; //전체 중복순열

void dfs(int cnt, int num, string alphabet){
    if(cnt == num){
        res.push_back(temp); //순열에 삽입
        return;
    }

    for(int i = 0; i < alphabet.size(); ++i){
        temp.push_back(alphabet[i]);
        dfs(cnt + 1, num, alphabet);
        temp.pop_back();
    }
}

int solution(string word){
    int answer = 0;

    for(int i = 1; i <= 5; ++i){
        dfs(0, i, "AEIOU");
    }

    sort(res.begin(), res.end()); //알파벳순으로 정렬
    int index = find(res.begin(), res.end(), word) - res.begin(); //인덱스를 반환
    
    return answer = index + 1;
}

int main(){
    int answer = solution("I");

    cout << answer << "\n";
    return 0;
}