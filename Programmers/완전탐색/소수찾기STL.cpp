#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

bool isPrime(int n){ //소수 판별 함수
    if(n < 2) return false;
    
    //에라토스테네스의 체, 소수를 찾으면 해당 수의 배수를 모두 지움
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0){ return false; }
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    vector<char> v; //종이 조각의 각 숫자를 저장
    vector<int> nums; //종이 조각으로 만들 수 있는 모든 수 저장
    
    for(int i = 0; i < numbers.size(); ++i){
        v.push_back(numbers[i]);
    }
    
    sort(v.begin(), v.end()); //next_permutation을 사용하기 위해 정렬을 진행
    do {
        string str = ""; //만들 수 있는 모든 숫자를 nums에 저장
        for(int i = 0; i < v.size(); ++i){
            str.push_back(v[i]);
            nums.push_back(stoi(str));
        }
    } while(next_permutation(v.begin(), v.end()));
    
    //중복 값 지우기
    sort(nums.begin(), nums.end());
    //중복되지 않은 값을 앞으로, 뒤에는 쓰레기값을 저장, 제일 처음 나오는 쓰레기 값의 iterator를 반환
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    for(int i = 0; i < nums.size(); ++i){ //소수일 경우 answer++
        if(isPrime(nums[i])) answer++;
    }

    return answer;
}

int main(){
    string numbers = "0112";
    cout << solution(numbers) << "\n";
}