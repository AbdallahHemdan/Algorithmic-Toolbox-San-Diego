// Task: Given two polynomials represented by two arrays, 
// write a function that multiplies given two polynomials.

// Input:  A[] = {5, 0, 10, 6} 
//         B[] = {1, 2, 4} 
// Output: prod[] = {5, 10, 30, 26, 52, 24}

// Sol: A simple solution is to one by one consider every term of first polynomial
// and multiply it with every term of second polynomial.
// Following is algorithm of this simple method.



// multiply(A[0..m-1], B[0..n-1])
// 1) Create a product array prod[] of size m+n-1.
// 2) Initialize all entries in prod[] as 0.
// 3) Travers array A[] and do following for every element A[i]
// ...=> Traverse array B[] and do following for every element B[j]
//           prod[i+j] = prod[i+j] + A[i] * B[j]
// 4) Return prod[].

// -----------------------------------------------------------

/*Author : Abdallah Hemdan */
/***********************************************/
/*
   ___  ___
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

// We Just Apply The Approch of Multiply Each item of Poltnomial_1 
// with Each item of Poltnomial_2 and Sum Up Them

vector<int> PolynomialMulti(vector<int> &Poly1, int n, vector<int> &Poly2, int m) {
	vector<int> Result(n + m - 1,0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Result[i + j] += Poly1[i] * Poly2[j];
		}
	}
	return Result; 
}

void printResult(vector<int> &Res) {
	for (int i = 0; i < Res.size(); i++)
		cout << Res[i] << " ";
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> Poly1(n);
	vector<int> Poly2(m);
	
	for (int i = 0; i < n; i++)
		cin >> Poly1[i];

	for (int i = 0; i < m; i++)
		cin >> Poly2[i];

	vector<int> ResOfMulti = PolynomialMulti(Poly1, n, Poly2, m);
	printResult(ResOfMulti);
}
