
//___________________________________________________________________
// 0-1 Knapsack Problem
// Given weights and values of n items,
// we need to put these items in a knapsack of capacity W
// to get the maximum total value in the knapsack Without Breaking any item(whole OR Nothing)


// 1- the Naive Solution (Recursion) Which Will Try All The items To Get The Optimal Solution
// 	Which Will Be Exponential(2^n) 

// 	wt[] = {1, 1, 1}, W = 2, val[] = {10, 20, 30}

//                        K(3, 2)         ---------> K(n, W)
//                    /            \ 
//                  /                \               
//             K(2,2)                  K(2,1)
//           /       \                  /    \ 
//         /           \              /        \
//        K(1,2)      K(1,1)        K(1,1)     K(1,0)
//        /  \         /   \          /   \
//      /      \     /       \      /       \
// K(0,2)  K(0,1)  K(0,1)  K(0,0)  K(0,1)   K(0,0)

// But,There are a Lot of OverLabing
// So We'll Go With Another approach(DP)

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
#include <vector>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <functional>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long int ll;

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);

using namespace std;
int _0_1_KnapSack(int W, int val[], int wt[], int n) {
  int K[n + 1][W + 1];

  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i - 1] <= w)
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }

  return K[n][W];
}

int main() {
  int n, Capas;
  cin >> n >> Capas;

  int Values[n];
  int Weights[n];

  for (size_t i = 0; i < n; i++) cin >> Values[i];

  for (size_t i = 0; i < n; i++) cin >> Weights[i];

  cout << _0_1_KnapSack(Capas, Values, Weights, n) << endl;
}
