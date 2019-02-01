/*Author : Abdallah Hemdan */ 
/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
 *  ___  __    	
 * |\  \|\  \	
 * \ \  \_\  \	
 *  \ \   ___ \emdan 
 *   \ \  \\ \ \     
 *    \ \__\\ \_\      
 *     \|__| \|__|     
 */

#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
#define     endl                     '\n'

typedef   long long int               ll ;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

using namespace std;

ll Make_operation(ll Operand_1, ll Operand_2, char op) {
	if (op == '*')
		return Operand_1 * Operand_2;
	else if (op == '+')
		return Operand_1 + Operand_2;
	else if (op == '-')
		return Operand_1 - Operand_2;
}

ll Maximize_The_Expre(const string &Expre) {
	int Len = Expre.size();
	int NumOfOperands = (Len + 1) / 2;

	ll Mini[NumOfOperands][NumOfOperands];
	ll Maxi[NumOfOperands][NumOfOperands];

	memset(Mini, 0, sizeof(Mini)); // initialize to 0
	memset(Maxi, 0, sizeof(Maxi)); // initialize to 0
	for (int i = 0; i < NumOfOperands; i++) {

		Mini[i][i] = stoll(Expre.substr(2 * i, 1));
		Maxi[i][i] = stoll(Expre.substr(2 * i, 1));
	}

	for (int s = 0; s < NumOfOperands - 1; s++) {
		for (int i = 0; i < NumOfOperands - s - 1; i++) {
			int j = i + s + 1;
			ll MinValue = LLONG_MAX;
			ll MaxValue = LLONG_MIN;

			for (int k = i; k < j; k++) {
				ll a = Make_operation(Mini[i][k], Mini[k + 1][j], Expre[2 * k + 1]);
				ll b = Make_operation(Mini[i][k], Maxi[k + 1][j], Expre[2 * k + 1]);
				ll c = Make_operation(Maxi[i][k], Mini[k + 1][j], Expre[2 * k + 1]);
				ll d = Make_operation(Maxi[i][k], Maxi[k + 1][j], Expre[2 * k + 1]);

				MinValue = min(MinValue, min(a, min(b, min(c, d))));
				MaxValue = max(MaxValue, max(a, max(b, max(c, d))));

			}
			Mini[i][j] = MinValue;
			Maxi[i][j] = MaxValue;
		}
	}

	return Maxi[0][NumOfOperands - 1];
}

int main() {
	string Expresion;
	cin >> Expresion;

	cout << Maximize_The_Expre(Expresion) << endl;
}
