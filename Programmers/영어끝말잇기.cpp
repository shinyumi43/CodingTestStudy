#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    int number = 0, order = 1;
    vector<int> answer;
    vector<vector<string>> v(26);
    bool fail = false; 

    for(int i = 0; i < words.size(); ++i){
        if(number == n) { number = 0; ++order; }

        ++number;
        string cur = words[i];
        char cur_front = cur[0];
        int id = cur_front - 97;

        //1 char check
        if(cur.size() == 1) { answer = { number, order }; break; }

        //prev char check
        if(i > 0){
            string prev = words[i - 1];
            char prev_back = prev[prev.size() - 1];

            if(prev_back != cur_front) { answer = { number, order }; break; }
        }

        //exist check
        for(int j = 0; j < v[id].size(); ++j){
            if(v[id][j] == cur) { fail = true; break; }
        }

        if(fail){ answer = { number, order }; break; }
        else{ v[id].push_back(cur); } //0-a, 1-b, ... , 25-z 
    }
    
    if(answer.empty()){ answer = { 0, 0 }; }
    
    return answer;
}

int main(){
    int n = 5;
    vector<string> words = { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "e", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
    vector<int> answer = solution(n, words);
    for(auto ans : answer){
        cout << ans << ' ';
    }
    cout << "\n";
}