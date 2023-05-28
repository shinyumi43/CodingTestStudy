#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int MAX = 200 + 20;

int cache[MAX][MAX][2]; //범위, 최대/최소
vector<int> nums;
vector<string> opers;

void init(vector<string> arr){
    for(int i = 0; i < arr.size(); ++i){
        if(i % 2 == 0){ nums.push_back(stoi(arr[i])); } //숫자
        else{ opers.push_back(arr[i]); } //연산자
    }
}

int func(int start, int end, bool isMax){
    int& res = cache[start][end][isMax];

    if(res != -1){ return res; }
    if(start == end){ return nums[start]; }

    res = isMax ? -INF : INF;

    for(int i = start; i < end; ++i){
        if(opers[i] == "-"){
            // 최대 = A구간 최대 - B구간 최소, 최소 = A구간 최소 - B구간 최대
            res = isMax ?
                max(res, func(start, i, true) - func(i + 1, end, false)) :
                min(res, func(start, i, false) - func(i + 1, end, true));
        }
        else{
            // 최대 = A구간 최대 + B구간 최대, 최소 = A구간 최소 + B구간 최소
            res = isMax ?
                max(res, func(start, i, true) + func(i + 1, end, true)) :
                min(res, func(start, i, false) + func(i + 1, end, false));
        }
    }

    return res;
}

int solution(vector<string> arr){
    init(arr);
    memset(cache, -1, sizeof(cache));
    return func(0, arr.size() / 2, true);

}

int main(){
    vector<string> arr = { "5", "-", "3", "+", "1", "+", "2", "-", "4" };
	cout << solution(arr) << "\n";
	return 0;
}