#include <vector>
#include <iostream>
using namespace std;

int ans = 0;

void dfs(vector<bool> chk, vector<int> nums, int n, int k, int cnt, int idx){
    //서로 다른 3개를 골랐을 경우
    if(cnt == k){
        //해당 조합을 더하도록
        int sum = 0;
        for(int i = 0; i < n; ++i){
            if(chk[i]) sum += nums[i];
        }

        //sum이 소수인지 check
        for(int i = 2; i < sum; ++i){
            if(sum % i == 0) { return; }
        }

        //소수이면, ans를 1 증가
        ++ans; return;
    }

    for(int i = idx; i < n; ++i){
        if(chk[i]) continue;
        chk[i] = true;
        dfs(chk, nums, n, k, cnt + 1, i);
        chk[i] = false;
    }
}

int solution(vector<int> nums) {
    int answer = -1;

    int n = nums.size(), k = 3, cnt = 0, idx = 0;
    vector<bool> chk(n);
    for(int i = 0; i < n; ++i) { chk[i] = false; }

    dfs(chk, nums, n, k, cnt, idx);
    
    answer = ans;
    return answer;
}

int main(){
    vector<int> nums = { 1,2,7,6,4 };
    cout << solution(nums) << "\n";
    return 0;
}