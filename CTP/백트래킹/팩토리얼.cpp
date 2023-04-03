#include <bits/stdc++.h>
using namespace std;

int factorial(int depth){
    if(depth == 0) { return 1; } //base case
    return depth * factorial(depth - 1);
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << "\n";
}