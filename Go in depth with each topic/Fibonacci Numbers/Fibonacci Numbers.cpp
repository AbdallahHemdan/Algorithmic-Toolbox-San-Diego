// Problem : Fibonacci Numbers (Given a number n, print n-th Fibonacci Number)

// Method 1 ( Use recursion )
// ____________________________________________________________________
	/*
	This Solution is not Effeicient Any More (Exponential)
                   fib(5)   
                     /                \
               fib(4)                fib(3)   
             /        \              /       \ 
         fib(3)      fib(2)         fib(2)   fib(1)
        /    \       /    \        /      \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /     \
fib(1) fib(0)

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

typedef   long long int               ll;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

using namespace std;
int FibonacciRecursive(int n) {
	if (n <= 1)
		return n;
	return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}
int main() {
	int FibNum;
	cin >> FibNum; 
	cout << FibonacciRecursive(FibNum) << endl;
} 

// ____________________________________________________________________  

// Method 2 ( Use Dynamic Programming )
// This Solution is More Effeicient But Need More Space  O(n)

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
ll Fibonacci_With_Dynamic_Programming(int n) {
	vector<ll> Arr(n + 2);
	Arr[0] = 0;
	Arr[1] = 1;
	
	for (ll i = 2; i <= n; i++)
		Arr[i] = Arr[i - 1] + Arr[i - 2];
	
	return Arr[n];
}
int main() {
	int FibNum;
	cin >> FibNum; 
	cout << Fibonacci_With_Dynamic_Programming(FibNum) << endl;
}

// ____________________________________________________________________  

// Method 3 ( Space Optimized Method 2 ) O(n) , Space O(1)

//  We can optimize the space used in method 2 by storing the previous 
//two numbers only because that is all we need to get the next Fibonacci number in series

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
ll Fibonacci_With_Dynamic_Programming_Optimized_Space(int n) {
	int a = 0, b = 1, c;
	if (n == 0)
		return 0;
	for (size_t i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int main() {
	int FibNum;
	cin >> FibNum; 
	cout << Fibonacci_With_Dynamic_Programming_Optimized_Space(FibNum) << endl;
}

// ____________________________________________________________________

// Method 4 :(Using formula)
// Time Complexity : O(1) 
// Space Complexity : O(1)

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
ll Fibonacci_With_Formula(int n) {
	double Phi = (1 + sqrt(5)) / 2;
	return round(pow(Phi, n) / sqrt(5));
}
int main() {
	int FibNum;
	cin >> FibNum; 
	cout << Fibonacci_With_Formula(FibNum) << endl;
}

// ____________________________________________________________________

// To Get The Last Of n-th Fibonacci Number We Use The Following Formula
/*
	Fib[0] = 0 ; 
	Fib[1] = 1 ; 
	for(i=2  ==> i<=n)
		Fib[i] = (Fib[i-1]%10 + Fib[i-2]%10) %10 ;
	return Fib[n] ;
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
ll Last_Digit_Of_Fib(int n) {
	vector<ll> Fib(n+2);
	Fib[0] = 0; 
	Fib[1] = 1;
	for (size_t i = 2; i <= n; i++)
		Fib[i] = (Fib[i - 1] % 10 + Fib[i - 2] % 10) % 10;
	return Fib[n];
}
int main() {
	int n; 
	cin >> n; 
	cout << Last_Digit_Of_Fib(n) << endl;
}
// ____________________________________________________________________  
/* 

- Important Fibonacci Formulas:

   1) Fib[1]+Fib[2]+Fib[3]+............+F[n] = Fib[n+2]-Fib[2]
   2) Fib[1]^2+Fib[2]^2+Fib[3]^2+............+F[n]^2 = Fib[n]*Fib[n+1]
*/
