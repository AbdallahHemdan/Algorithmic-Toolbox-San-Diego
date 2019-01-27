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
int main() {
	int n, SizeOfKnapSack; 
	cin >> n >> SizeOfKnapSack;
	vector<pair<int, int>> Value_Wigth(n); 
	vector<pair<double,int>> ValuePerUnit(n); 
	for (int i = 0; i < n; i++) {
		cin >> Value_Wigth[i].first >> Value_Wigth[i].second;
		ValuePerUnit[i].first = 1.0 * Value_Wigth[i].first / Value_Wigth[i].second; 
		ValuePerUnit[i].second = Value_Wigth[i].second;
	}
	sort(ValuePerUnit.begin(), ValuePerUnit.end(),greater<pair<double,int>>());
	double Res = 0;
	for (int i = 0; i < ValuePerUnit.size() && SizeOfKnapSack>0; i++) {
		Res += min(ValuePerUnit[i].second, SizeOfKnapSack)*ValuePerUnit[i].first;
		SizeOfKnapSack -= min(ValuePerUnit[i].second, SizeOfKnapSack); 
	}
	cout << fixed << setprecision(4) << Res << endl;
}
