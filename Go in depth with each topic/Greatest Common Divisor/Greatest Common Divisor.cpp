// Greatest Common Divisor 
// (Euclidean Algoritm)

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
int main() {
	int Num_1, Num_2; 
	cin >> Num_1 >> Num_2; 
	cout << GCD(Num_1, Num_2) << endl;
}

// ____________________________________________________________________  

// Greatest Common Divisor of Floating Point Numbers

/*
Input  : 0.3, 0.9
Output : 0.3

Input  : 0.48, 0.108
Output : 0.012
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
double GCD(double a, double b)
{
	if (a < b)
		return GCD(b, a);

	if (fabs(b) < 0.001)
		return a;

	else
		return (GCD(b, a - floor(a / b) * b));
}

int main() {
	double Num_1, Num_2; 
	cin >> Num_1 >> Num_2; 
	cout << GCD(Num_1, Num_2) << endl;
}