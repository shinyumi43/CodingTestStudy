#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    deque<int> dq;
    cin >> n;

    while(n > 0){
        dq.push_front(n);
        n--;
    }

    while(dq.size() > 1){
        dq.pop_front();
        int param = dq.front();
        dq.pop_front();
        dq.push_back(param);
    }

    cout << dq.front() << "\n";

    return 0;
}