
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
int Solve(vector<pair<int, int>>, vector<int> &);
int main() {
  // freopen("name.txt", "r", stdin);
  int n;
  cin >> n;
  vector<pair<int, int>> periods(n);
  vector<int> segments;

  for (int i = 0; i < n; i++) cin >> periods[i].first >> periods[i].second;
  int Mini_Visits = Solve(periods, segments);

  cout << Mini_Visits << endl;
  for (int i = 0; i < segments.size(); i++) cout << segments[i] << ' ';
  return 0;
}

int Solve(vector<pair<int, int>> periods, vector<int> &segments) {
  sort(periods.begin(), periods.end());
  int current_visit = 0, last_visit = 1, res = 0;

  while (current_visit < periods.size()) {
    while (last_visit < periods.size() &&
           periods[current_visit].second >= periods[last_visit].first &&
           periods[current_visit].second >=
               periods[last_visit]
                   .second)  // the interval is fully enclosed by the segment
    {
      current_visit = last_visit++;
    }
    while (current_visit < periods.size() && last_visit < periods.size() &&
           periods[current_visit].second - periods[last_visit].first >= 0)
      last_visit++;
    res++;
    segments.push_back(periods[current_visit].second);
    current_visit = last_visit;
  }
  return res;
}
