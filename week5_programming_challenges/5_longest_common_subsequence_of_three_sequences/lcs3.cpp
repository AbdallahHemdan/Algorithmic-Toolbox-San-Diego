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
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long int ll;

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

using namespace std;

int LCS(vector<int> _One, vector<int> _Second, vector<int> _third, int a, int b, int c) {
	vector<vector<vector<int>>> Longest(a + 1,vector<vector<int>>(b + 1,vector<int>(c + 1)));

	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				if (i == 0 || j == 0 || k == 0) {
					Longest[i][j][k] = 0;
					continue;
				}
				else if (_One[i - 1] == _Second[j - 1] && _One[i - 1] == _third[k - 1]) {
					Longest[i][j][k] = Longest[i - 1][j - 1][k - 1] + 1;
					continue;
				}
				else {
					Longest[i][j][k] =
						max( max(Longest[i - 1][j][k], Longest[i][j - 1][k]),
							Longest[i][j][k - 1]);
				}
			}

		}
	}
	return Longest[a][b][c];
}

int main() {

	int a, b, c;
	cin >> a;
	vector<int> One(a);
	for (int i = 0; i < a; i++)
		cin >> One[i];

	cin >> b;
	vector<int> Second(b);
	for (int i = 0; i < b; i++) 
		cin >> Second[i];

	cin >> c;
	vector<int> Third(c);
	for (int i = 0; i < c; i++)
		cin >> Third[i];

	cout << LCS(One, Second, Third, a, b, c) << endl;
} 
