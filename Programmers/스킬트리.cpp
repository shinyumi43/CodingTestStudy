#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    vector<pair<char, int>> vec;
    for(int i = 0; i < skill.size(); ++i){
        char ch = skill[i];
        vec.push_back({ch, 26});
    }
    
    for(int i = 0; i < skill_trees.size(); ++i){
        string str = skill_trees[i];
        for(int j = 0; j < str.size(); ++j){
            char ch = str[j];
            for(int k = 0; k < vec.size(); ++k){
                if(ch == vec[k].first){ vec[k].second = j; break; }
            }
        }

        answer++;

        for(int j = 0; j < vec.size() - 1; ++j){
            int now = vec[j].second;
            int next = vec[j + 1].second;
            if(next < now){ answer--; break; }
        }

        for(int j = 0; j < vec.size(); ++j){
            vec[j].second = 26; //init
        }
    }

    return answer;
}

int main(){
    string str = "CBD";
    vector<string> str_trees = { "BACDE", "CBADF", "AECB", "BDA" };
    cout << solution(str, str_trees) << "\n";
}