#include <iostream>
#include <vector>
#include <string>
using namespace std;

int answer = 0;
bool visited[20];

void dfs(vector<int> numbers, int count, int target, int sum){
    if(count == numbers.size()){
        if(target == sum){ answer++; }
        return;
    }
    //for문이 있으면, 숫자가 순차적으로 계산되지 못함
    dfs(numbers, count + 1, target, sum + numbers[count]);
    dfs(numbers, count + 1, target, sum - numbers[count]);
}

int solution(vector<int> numbers, int target){
    dfs(numbers, 0, target, 0);
    return answer;
}


int main(){
    int result = solution({1,1,1,1,1}, 3);
    cout << result << "\n";
    return 0;
}