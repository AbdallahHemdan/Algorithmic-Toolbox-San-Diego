// Author : Abdallah Hemdan
1) Selection Sort :  O(n^2)
---------------
 	The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
	1) The subarray which is already sorted.
	2) Remaining subarray which is unsorted.
	In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
		

	
Code:
-----	
	#include <bits\stdc++.h>
	using namespace std ;
	
	void SelectionSort(vector<int> &Arr, int n) {
		for (int i = 0; i < n - 1; i++) {
			int min_ind = i; 
			for (int j = i + 1; j < n; j++) {
				if (Arr[j] < Arr[min_ind])
					min_ind = j; 
			}
			swap(Arr[min_ind], Arr[i]);
		}
	}

	int main() {
		int n; cin >> n; 
		vector<int> Arr(n); 
		for (int i = 0; i < n; i++)
			cin >> Arr[i];
		
		cout << "Before Sort" << endl;
		for (auto i : Arr) cout << i << " ";
		cout << endl; 
		
		SelectionSort(Arr, n);
		cout << "After Sort" << endl;
		
		for (auto i : Arr) cout << i << " ";
		cout << endl;
	}
