#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, Num, Sum = 0, Res = 0;
    vector<int> V;
    cin >> N >> M;

    while(N--){
        cin >> Num;
        V.push_back(Num); //삽입을 진행
    }

    for(int i = 0; i < V.size(); i++){
        for(int j = i + 1; j < V.size(); j++){
            for(int k = j + 1; k < V.size(); k++){
                if(V[i] + V[j] + V[k] <= M && V[i] + V[j] + V[k] > Sum){
                    Sum = V[i] + V[j] + V[k];
                }
            }
        }
    }

    cout << Sum << "\n";
    return 0;

    //M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합
    //567, 568, 569, 578, 579, 589, 678, 679, 689, 789
    //012, 013, 014, 023, 024, ...

    //M에 최대한 가까울 수 있도록
}