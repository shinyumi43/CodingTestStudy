#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, vector<string>> info;
vector<string> answer;

void dfs(string s){
    while(!info[s].empty()){
        string n = info[s].front();
        info[s].erase(info[s].begin()); //방문한 공항의 정보를 삭제
        dfs(n);
    }
    answer.push_back(s);
}

vector<string> solution(vector<vector<string>> tickets) {
    for(auto ticket : tickets){
        string start = ticket[0], end = ticket[1];
        
        if(info.find(start) != info.end()){ //인접 그래프 생성
            auto it = info.find(start);
            it->second.push_back(end);
        }
        else{
            vector<string> temp; temp.push_back(end);
            info.insert(make_pair(start, temp));
        }
    }
    
    for(auto entry : info){
        sort(info[entry.first].begin(), info[entry.first].end()); //알파벳 순서로 정렬
    }
    
    dfs("ICN");
    
    //reverse(answer.begin(), answer.end()); // 경로 순서를 뒤집음
    
    return answer;
}

int main(){
    solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}});
    for(int i = 0; i < answer.size(); ++i){
        cout << answer[i] << " ";
    }
    return 0;
}