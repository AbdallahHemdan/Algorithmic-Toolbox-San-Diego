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

int LCS(string _One, string _Second, int m, int n) {
	vector<vector<int>> Longest(m + 1,vector<int>(n + 1));
	int i, j;
	for (i = 0; i <= m; i++){
		for (j = 0; j <= n; j++){
			if (i == 0 || j == 0)
				Longest[i][j] = 0;

			else if (_One[i - 1] == _Second[j - 1])
				Longest[i][j] = Longest[i - 1][j - 1] + 1;

			else
				Longest[i][j] = max(Longest[i - 1][j], Longest[i][j - 1]);
		}
	}
	return Longest[m][n];
}
int main() {
	int m, n;
	string _One = "", _Second = "";
	cin >> m;
	int Tempo;
	for (size_t i = 0; i < m; i++) {
		cin >> Tempo;
		_One += Tempo;
	}
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> Tempo;
		_Second += Tempo;
	}
	cout << LCS(_One, _Second, m, n) << endl;
}
