#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    queue<int> qa;
    queue<int> qb;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(auto a : A) qa.push(a);
    for(auto b : B) qb.push(b);

    while(!qb.empty() && !qa.empty()){
        int a = qa.front();
        int b = qb.front();

        if(a < b){
            answer++;
            qa.pop();
        }
        qb.pop();
    }

    return answer;
}

int main(){
    cout << solution({5,1,3,7}, {2,2,6,8}) << "\n";
    cout << solution({2,2,2,2}, {1,1,1,1}) << "\n";
}