// Introduction To Greedy Algorithm 
// 	Greedy Algorithm Used in Optimization Problems ==> (Maximization,Minimization) Problems
// 	In Greedy We Get a Selection Methods Which
// 	We Apply To Get The Optimal Solution(Feasible Solution)
//___________________________________________________________________

// Fractional Knapsack Problem :

// Given weights and values of n items,
// we need to put these items in a knapsack of capacity W
// to get the maximum total value in the knapsack.

// In Fractional Knapsack, we can break items for maximizing the total value of knapsack. 
// the greedy approach is to calculate the ratio (value/weight)
// for each item and sort the item on basis of this ratio.
// Then take the item with the highest ratio and add them
// until we can’t add the next item as a whole and at the end add the next item as much as we can.
// Which will always be the optimal solution to this problem.

/*Author : Abdallah Hemdan */
/***********************************************/
/*
   ___  __
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
#include <algorithm>
#include <iomanip>
#include <vector>
#include <functional>
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
	vector<pair<double, int>> ValuePerUnit(n);
	
	for (int i = 0; i < n; i++) {
		cin >> Value_Wigth[i].first >> Value_Wigth[i].second;
		ValuePerUnit[i].first = 1.0 * Value_Wigth[i].first / Value_Wigth[i].second;
		ValuePerUnit[i].second = Value_Wigth[i].second;
	}
	
	sort(ValuePerUnit.begin(), ValuePerUnit.end(), greater<pair<double, int>>());
	
	double Res = 0;
	
	for (int i = 0; i < ValuePerUnit.size() && SizeOfKnapSack>0; i++) {
		Res += min(ValuePerUnit[i].second, SizeOfKnapSack)*ValuePerUnit[i].first;
		SizeOfKnapSack -= min(ValuePerUnit[i].second, SizeOfKnapSack);
	}
	
	cout << fixed << setprecision(4) << Res << endl;
}
