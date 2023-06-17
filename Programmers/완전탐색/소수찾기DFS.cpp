#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool visited[7]; //방문 체크
vector<int> arr; //만들어진 숫자를 담을 문자열
string temp; //임시 숫자를 담을 문자열

//소수 판별 함수
bool isPrime(int n){ 
    if(n < 2) return false;
    
    //에라토스테네스의 체, 소수를 찾으면 해당 수의 배수를 모두 지움
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0){ return false; }
    }
    
    return true;
}

// bool isPrime(int num){ //소수인지를 판별하는 함수
//     if(num < 2) return false;

//     for(int i = 2; i < num; ++i){
//         if(num % i == 0) return false;
//     }

//     return true;
// }

void dfs(int cnt, int sum, string nums){
    if(cnt == sum){
        arr.push_back(stoi(temp)); //그때까지 누적된 문자열을 삽입
        return;
    }

    for(int i = 0; i < nums.size(); ++i){ //순열을 만드는 백트래킹을 구현
        if(!visited[i]){
            visited[i] = true;
            temp.push_back(nums[i]);
            dfs(cnt + 1, sum, nums);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

int solution(string numbers){
    int answer = 0;
    
    for(int i = 0; i < 7; ++i){ visited[i] = false; }

    for(int i = 1; i <= numbers.size(); ++i){
        dfs(0, i, numbers); //1자리, 2자리 ..에 대해 각각 순열을 구성
    }

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); //중복을 제거
    
    for(int i = 0; i < arr.size(); ++i){
        if(isPrime(arr[i])){ answer++; }
    }

    return answer;
}

int main(){
    string numbers = "17";
    cout << solution(numbers) << "\n";
}
