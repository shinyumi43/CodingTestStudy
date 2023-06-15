#include <iostream>
using namespace std;

//최대공약수
long long gcd(int a, int b)
{
	long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w, int h) {
	long long W = w;
	long long H = h;
    //(w/gcd + h/gcd - 1) * gcd = (w + h - gcd), 잘린 사각형의 개수
	long long tmp = (W + H) - gcd(W, H);

	return (W * H) - tmp;
}

int main(){
    int w = 8;
    int h = 12;
    
    cout << solution(8, 12) << "\n";
    return 0;
}