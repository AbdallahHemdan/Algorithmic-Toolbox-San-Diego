// Least Common Multiple
/* An efficient solution is based on below formula for LCM of two numbers ‘a’ and ‘b’.

   a x b = LCM(a, b) * GCD (a, b)

   LCM(a, b) = (a x b) / GCD(a, b) 
*/

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
int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

ll LCM(ll a, ll b) {
	return (ll(a)*b) / GCD(b, a%b);
}

int main() {
	ll Num1 , Num2; 
	cin >> Num1 >> Num2;
	cout << LCM(Num1,Num2) << endl;
}

// ____________________________________________________________________

// Least Common Mutiple Without Using GCD

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

ll LCM(ll a, ll b) {
	int large = max(a, b);
	int small = min(a, b);
	for (size_t i = large; ; i += large)
		if (i%small == 0)
			return i;
}
int main() {
	ll Num1 , Num2; 
	cin >> Num1 >> Num2;
	cout << LCM(Num1,Num2) << endl;
}
