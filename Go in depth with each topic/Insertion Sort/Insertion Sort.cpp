
3. Insertion Sort: O(n^2)
-----------------
	Insertion sort is a simple sorting algorithm that works
	the way we sort playing cards in our hands
	We take each element and put it in its right position

	Time Complexity : O(n^2)
	Space Complexity : O(1)
	Sort in Place : Yes
	Stable : Yes

	Insertion Sort is very useful when data is already sorted


Code:
------
	//Author : Abdallah Hemdan
	#include <bits\stdc++.h>
	using namespace std;

	template<typename T>
	void InsertionSort(vector<T>& Arr, int n) {
		T Key; 
		int i, j;
		for (i = 1; i < n; i++) {
			Key = Arr[i];
			j = i - 1;

			while (j >= 0 && Arr[j] > Key) {
				Arr[j + 1] = Arr[j];
				j--;
			}
			Arr[j + 1] = Key;
		}
	}

	template<typename T>
	void Print(vector<T> Arr, int n) {
		for (int i = 0; i < n; i++)
			cout << Arr[i] << " ";
	}


	int main() {
		int n; cin >> n;
		vector<int> Arr(n);

		for (int i = 0; i < n; i++) cin >> Arr[i];
		
		cout << "Before Sorting" << endl;
		Print(Arr, n);
		
		InsertionSort(Arr, n);
		
		cout << "After Sorting" << endl;
		Print(Arr, n);
	}
