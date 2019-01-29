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
