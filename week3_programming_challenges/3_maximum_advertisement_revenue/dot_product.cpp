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
int CalcIt(vector<int> Profit, vector<int> Clicks, int n);
int main() {
  int n;
  cin >> n;
  vector<int> Profit(n);
  vector<int> Clicks(n);
  for (int i = 0; i < n; i++) cin >> Profit[i];
  for (int i = 0; i < n; i++) cin >> Clicks[i];
  cout << CalcIt(Profit, Clicks, n) << endl;
}
int CalcIt(vector<int> Profit, vector<int> Clicks, int n) {
  sort(Profit.begin(), Profit.end());
  sort(Clicks.begin(), Clicks.end());
  int Sum = 0;
  for (int i = 0; i < n; i++) {
    Sum += Profit[i] * Clicks[i];
  }
  return Sum;
}
