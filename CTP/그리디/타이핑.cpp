#include <iostream>
using namespace std;

int main(){
    string cmd;
    int cnt = 0;
    char isnow, isnext, istype = 'L';

    cin >> cmd;

    for(int i = 0; i < cmd.size() - 1; ++i){
        char now = cmd[i];
        char next = cmd[i + 1];

        //상태값을 저장
        if(islower(now)) { isnow = 'L'; }
        else { isnow = 'U'; }

        if(isupper(next)){ isnext = 'U'; }
        else { isnext = 'L'; }

        //now가 input 가능
        if(isnow == istype) { cnt++; continue; }

        //모두 input 불가, 마름모
        if(isnow != istype && isnext != istype){
            if(istype == 'L') { istype = 'U'; }
            else { istype = 'L'; }
            cnt++;
        }
        //now만 input 가능, 별
        else if(isnow == istype && isnext != istype){
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
