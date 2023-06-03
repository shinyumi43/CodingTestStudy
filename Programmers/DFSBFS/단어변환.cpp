#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

map<string, vector<string>> dict;
map<string, bool> visited;
int answer = 0;

void bfs(string begin, string target){
    queue<pair<string, int>> q;
    q.push({ begin, 0 });
    visited[begin] = true;

    int dep;
    string tmp;
    while(!q.empty()){
        tmp = q.front().first;
        dep = q.front().second;
        q.pop();

        if(tmp == target){ answer = dep; return; }

        for(int i = 0; i < tmp.length(); ++i){
            string str = tmp.substr(0, i) + "*" + tmp.substr(i + 1);

            if(dict.find(str) != dict.end()){
                auto it = dict.find(str);
                for(auto s : it->second){
                    if(!visited[s]){
                        q.push({s, dep+1});
                        visited[s] = true;
                    }
                }
            }
        }
    }

    if(tmp != target) { answer = 0; }
}

void make_graph(string begin, vector<string> words){
    //adjacent graph(begin, words)
    for(auto word : words){
        for(int i = 0; i < word.length(); ++i){
            string str = word.substr(0, i) + "*" + word.substr(i + 1);
            if(dict.find(str) != dict.end()){ //Key O
                auto it = dict.find(str);
                it->second.push_back(word);
            }
            else{ //Key X
                vector<string> temp; temp.push_back(word);
                dict.insert(make_pair(str, temp));
            }
        }
    }
    for(int i = 0; i < begin.length(); ++i){
        string str = begin.substr(0, i) + "*" + begin.substr(i + 1);
        if(dict.find(str) != dict.end()){ //Key O
            auto it = dict.find(str);
            it->second.push_back(begin);
        }
        else{ //Key X
            vector<string> temp; temp.push_back(begin);
            dict.insert(make_pair(str, temp));
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    make_graph(begin, words);
    bfs(begin, target);    
    return answer;
}

int main(){
    int res = solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
    cout << res << "\n";
    return 0;
}


