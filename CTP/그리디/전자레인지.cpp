#include <bits/stdc++.h>
using namespace std;

int main(){
    // A = 5*60 = 300, B = 1*60 = 60, C = 10
    int T, a = 0, b = 0, c = 0;
    cin >> T;

    // 10�� ����� �ƴ� ���, ���� �� ����
    if(T % 10 != 0) { cout << -1 << "\n"; }
    else{
        a = T / 300;
        b = (T % 300) / 60;
        c = ((T % 300) % 60) / 10;
        cout << a << " " << b << " " << c << "\n";
    }

    return 0;
}