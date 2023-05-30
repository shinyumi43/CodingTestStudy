#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i = triangle.size() - 1; i >= 1; --i){
        for(int j = 0; j < triangle[i - 1].size(); ++j){
            int max_val = max(triangle[i][j], triangle[i][j + 1]);
            triangle[i - 1][j] += max_val;
        }
    }
    answer = triangle[0][0];
    return answer;
}