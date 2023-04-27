#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    
    int idx = 0;
    int request = d[idx];

    while(true){
        if(idx == d.size()) { break; } //더이상 접근할 수 없음

        if(budget < request){ break; }
        else if(budget == request) {
            budget -= request; answer++;
            break;
        }
        else{
            budget -= request;
            idx++; answer++;
            request = d[idx];
        }
    }

    return answer;
}

int main(){
    vector<int> cmd = {2,2,3,3};
    int budget = 10;

    cout << solution(cmd, budget) << "\n";
    return 0;
}