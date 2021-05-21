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

bool GreaterOrEqual(string& a, string& b) {
	return(b + a < a + b);
}

string larsal(vector<string> Nums, int n)
{
    sort(Nums.begin(),Nums.end(),GreaterOrEqual); 
    stringstream Salary; 
    for (size_t i = 0; i < n; i++) {
      Salary << Nums[i]; 
    }
    return Salary.str(); 
}

int main() {
	int n;
	cin >> n;
	vector<string> Nums(n);
	for (size_t i = 0; i < n; i++) {
		cin >> Nums[i];
	}
	cout << larsal(Nums, n) << endl;
}

