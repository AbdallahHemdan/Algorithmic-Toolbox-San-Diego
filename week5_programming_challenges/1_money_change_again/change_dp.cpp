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
int CountMinWays(int Coins[], int n, int Money) {
	vector<int> Ways(Money + 1, INT_MAX);
	Ways[0] = 0;
	for (int i = 1; i <= Money; i++) {
		for (int c = 0; c < n; c++) {
			if (i >= Coins[c]) {
				int sub_res = Ways[i - Coins[c]];
				if (sub_res != INT_MAX && sub_res + 1 < Ways[i])
					Ways[i] = sub_res + 1;
			}
		}
	}
	return Ways[Money];
}
int main() {
	int Money; 
	cin >> Money; 
	int Coins[3] = { 1,3,4 };
	cout << CountMinWays(Coins, 3, Money) << endl;

}
