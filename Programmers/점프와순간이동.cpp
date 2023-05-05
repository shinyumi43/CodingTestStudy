#include <iostream>
using namespace std;

//짝수 - 순간이동, 홀수 - +1(건전지), 숫자는 -1
int solution(int n)
{
    int ans = 0;

    while(n > 0){
        if(n % 2 == 0){ n = n / 2; }
        else{ ++ans; n = n - 1; }
    }

    return ans;
}

int main(){
    cout << solution(5000) << "\n";
}