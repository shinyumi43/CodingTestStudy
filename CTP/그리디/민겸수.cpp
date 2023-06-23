#include <iostream>
#include <vector>
#include <string>
using namespace std;

string max_str(string s){
    string ret = "";

    int idx = 0;
    while(idx < s.size()){
        if(s[idx] == 'M'){
            int end_idx = idx;

            while(end_idx < s.size()){
                if(s[end_idx] == 'M') end_idx++;
                else break;
            }

            // 십진수로 변환
			if (end_idx == s.size()) {
				for (int len = 0; len < end_idx - idx; len++) {
					ret += "1";
				}
			}
			else {
				ret += "5";
				for (int len = 0; len < end_idx - idx; len++) {
					ret += "0";
				}
			}

			// idx 갱신
			idx = end_idx + 1;
        }
        else{
            ret += "5";
            idx++;
        }
    }

    return ret;
}


string min_str(string s){
	string ret = "";

	int idx = 0;
	while (idx < s.size()) {
		if (s[idx] == 'M') {
			int end_idx = idx;
			while (end_idx < s.size()) {
				if (s[end_idx] == 'M') end_idx++;
				else break;
			}

			// 십진수로 변환
			ret += "1";
			end_idx--;

			for (int len = 0; len < end_idx - idx; len++) {
				ret += "0";
			}

			// idx 갱신
			idx = end_idx + 1;
		}
		else {
			ret += "5";
			idx++;
		}
	}

	return ret;
}


int main(){
    string str;
    cin >> str;

    cout << max_str(str) << "\n";
    cout << min_str(str) << "\n";

    return 0;
}