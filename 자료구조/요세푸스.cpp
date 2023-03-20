#include <bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k, count = 0, num, length;
    cin >> n >> k;

    queue<int> circle;
    queue<int> print;

    for(int i = 0; i < n; i++){
        circle.push(i + 1); // 1 ~ 7까지 삽입
    }

    while(!circle.empty()){
        count++;
        if(k == count) { 
            count = 0; 
            num = circle.front();
            circle.pop();
            print.push(num); //순열 print에 삽입

        }
        else {  
            num = circle.front();
            circle.pop();
            circle.push(num); //다시 circle에 삽입
        }
    }

    length = print.size();
    cout << "<";
    for(int i = 0; i < length - 1; i++){
        cout << print.front() << ", ";
        print.pop();
    }
    cout << print.front() << ">";
    print.front();
    
    return 0;
}