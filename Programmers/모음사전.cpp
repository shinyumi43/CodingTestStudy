#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v;
void dfs(vector<char> alphabet, vector<char> comb, int idx, int cnt){
    if(cnt == comb.size()){
        string str = "";
        for(int i = 0; i < comb.size(); ++i){
            str += comb[i];
        }
        v.push_back(str);
        return;
    }
    else{
        for(int i = idx; i < alphabet.size(); ++i){
            comb[cnt] = alphabet[i];
            dfs(alphabet, comb, idx, cnt + 1);
        }
    }
}

int solution(string word){
    int answer = 0;
    vector<char> alphabet = { 'A', 'E', 'I', 'O', 'U' };

    for(int r = 1; r <= 2; ++r){
        vector<char> comb(r);
        dfs(alphabet, comb, 0, 0);
    }

    sort(v.begin(), v.end());
    answer = find(v.begin(), v.end(), word) - v.begin() + 1; //-v.begin()을 해줘야 index를 구할 수 있음
    return answer;
}

int main(){
    int answer = solution("AE");
    cout << answer << "\n";
    return 0;
}