#include <bits/stdc++.h>
using namespace std;

//시간 초과 문제 발생
int main(){
    int n, m, l, r = 0; //left는 a, right는 b 관리
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> ans;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];

    for(int l = 0; l < n; l++){
        while(b[r] < a[l] && r < m){ ans.push_back(b[r]); r++; }
        ans.push_back(a[l]);
    }

    for(auto e : ans) { cout << e << " "; }
    
    if(r < m){
        for(int i = r; i < m; i++) { cout << b[i] << " ";}
        cout << "\n";
    }

    return 0;
}