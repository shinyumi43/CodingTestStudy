#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[8];
vector<int> order;
vector<vector<int>> orders;

void dfs(int count, int total, vector<int> dungeon){
    if(count == total){
        orders.push_back(order);
        // for(int i = 0; i < order.size(); ++i){
        //     cout << order[i] << ' ';
        // }
        // cout << "\n";
        return;
    }
    for(int i = 0; i < dungeon.size(); ++i){
        if(!visited[i]){
            visited[i] = true;
            order.push_back(dungeon[i]);
            dfs(count + 1, total, dungeon);
            order.pop_back();
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> dungeon;
    for(int i = 0; i < dungeons.size(); ++i){ dungeon.push_back(i); }
    
    dfs(0, dungeons.size(), dungeon); //순서를 정리
    
    for(int i = 0; i < orders.size(); ++i){
        int temp = 0, energy = k;
        vector<int> order = orders[i];
        for(int j = 0; j < order.size(); ++j){
            int need = dungeons[order[j]][0];
            int used = dungeons[order[j]][1];
            
            if(energy >= need){ energy -= used; temp++; }
            else { continue; }
        }
        if(temp > answer) { answer = temp; }
        
        if(answer == dungeons.size()){ break; }
    }
    
    return answer;
}

int main(){
    int k = 80;
    vector<vector<int>> dungeons = { {80, 20}, {50, 40}, {30, 10} };

    vector<int> dungeon;
    for(int i = 0; i < dungeons.size(); ++i){ dungeon.push_back(i); }

    //dfs(0, dungeons.size(), dungeon); //순서를 정리
    cout << solution(k, dungeons) << "\n";
    return 0;
}