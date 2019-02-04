// Selection Sort: Time Complexity: O(n2)

// The Main idea : 
// 	The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

// 		1) The subarray which is already sorted.
// 		2) Remaining subarray which is unsorted.

// In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray

// - The Good Of The Selection Sort is it never makes more than O(n) swaps
// and can be useful when memory write is a costly operation.

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
#include <vector>
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
#define     endl                     '\n'

typedef   long long int               ll;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

using namespace std;

void PrintArray(vector<int> &Arr, int n) {
	for (int i = 0; i < n; i++)
		cout << Arr[i] << " ";
}

void SelctionSort(vector<int> &Arr, int n) {
	int indexOfMin;
	
	for (int i = 0; i < n - 1; i++) {
		indexOfMin = i;
		for (int j = i; j < n; j++) {
			if (Arr[j] < Arr[indexOfMin])
				indexOfMin = j;
		}

		swap(Arr[indexOfMin], Arr[i]);
	}
}


int main() {
	int n; 
	cin >> n; 

	vector<int> Arr(n);
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
	
	SelctionSort(Arr, n); 
	PrintArray(Arr, n);
}
