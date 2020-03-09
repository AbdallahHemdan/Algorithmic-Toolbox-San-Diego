
6. Quick Sort : O(n^2) , (QuickSort is faster in practice)

	QuickSort is a Divide and Conquer algorithm.
	It picks an element as pivot and partitions the given array around the picked pivot.
	There are many different versions of quickSort that pick pivot in different ways

	1.Always pick first element as pivot
	2.Always pick last element as pivot (implemented below)
	3.Pick a random element as pivot
	4.Pick median as pivot
	
	The key process in quickSort is partition().
	Target of partitions is, given an array and an element x of array as pivot,
	put x at its correct position in sorted array and put all smaller elements (smaller than x) before x,
	and put all greater elements (greater than x) after x


Code:
-----
	//Author : Abdallah Hemdan
	#include <bits\stdc++.h>
	using namespace std;

	template<typename T>
	int Partition(T Arr[], int Low, int High) {
		int Pivot = Arr[High]; 
		int i = Low - 1; 

		for (int j = Low; j < High; j++) {
			if (Arr[j] <= Pivot) {
				i++; 
				swap(Arr[j], Arr[i]); 
			}
		}
		swap(Arr[i + 1], Arr[High]); 
		return i + 1;
	}

	template<typename T>
	void quickSort(T Arr[], int Low, int High) {
		if (Low < High) {
			int Pivot = Partition(Arr, Low, High); 

			quickSort(Arr, Low, Pivot - 1); 
			quickSort(Arr, Pivot + 1, High); 
		}
	}

	template<typename T>
	void QuickSort(T Arr[], int n) {
		quickSort(Arr, 0, n - 1); 
	}

	template<typename T>
	void Print(T Arr[], int n) {
		for (int i = 0; i < n; i++)
			cout << Arr[i] << " "; 
		cout << endl;
	}

	int main() {
		int n; cin >> n;
		int* Arr = new int[n];
		for (int i = 0; i < n; i++) cin >> Arr[i]; 

		cout << "Before Sorting " << endl;
		Print(Arr, n); 
		QuickSort(Arr, n); 

		cout << "After Sorting " << endl;
		Print(Arr, n); 
	}
