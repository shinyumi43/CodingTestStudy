#include <bits/stdc++.h>
using namespace std;

int main(){
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; //숫자 개수
    double res; //중간 결과
    string cmd; //문자열

    cin >> n >> cmd;

    vector<int> num(n); //숫자 대응
    stack<double> eval; //피연산자

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i] >= 'A' && cmd[i] <= 'Z'){ //피연산자
            eval.push(num[cmd[i] - 'A']); //A ~ Z에 해당하는 위치의 값
        }
        else{ //연산자
            if(!eval.empty()){
                double a = eval.top();
                eval.pop();
                double b = eval.top();
                eval.pop();

                if(cmd[i] == '+'){
                    res = b + a;
                }
                else if(cmd[i] == '-'){
                    res = b - a;
                }
                else if(cmd[i] == '*'){
                    res = b * a;
                }
                else if(cmd[i] == '/'){
                    res = b / a;
                }

                eval.push(res);
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << eval.top() << "\n";
    eval.pop();
   
    return 0;

}