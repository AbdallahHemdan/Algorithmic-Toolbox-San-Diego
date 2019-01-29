/*Author : Abdallah Hemdan */
/***********************************************/
/*
   ___  ___
* |\  \|\  \
* \ \  \_\  \
*  \ \   ___ \emdan
*   \ \  \\ \ \
*    \ \__\\ \_\
*     \|__| \|__|
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
typedef   long long int               ll;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

using namespace std;

ll Periodic(ll m) {
	ll a = 0, b = 1, c = a + b;
	for (int i = 0; i < m*m; i++) {
		c = (a + b) % m;
		a = b;
		b = c;
		if (a == 0 && b == 1)
			return i + 1;
	}
}
int Solve(ll n, ll m) {
	long long remainder = n % Periodic(m);

	long long first = 0;
	long long second = 1;

	long long res = remainder;

	for (int i = 1; i < remainder; i++) {
		res = (first + second) % m;
		first = second;
		second = res;
	}

	return res % m;
}

// Sum Of (Fib[0]^2+Fib[1]^2+.....+Fib[n]^2) = Fib[n]*Fib[n+1]
int main() {
	ll n; 
	cin >> n;
	cout << (Solve(n + 1,10)*Solve(n,10)) % 10 << endl;
}
