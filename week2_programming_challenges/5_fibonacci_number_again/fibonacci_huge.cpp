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
int main() {
	ll n, m; 
	cin >> n >> m; 
	cout << Solve(n, m) << endl;
}
