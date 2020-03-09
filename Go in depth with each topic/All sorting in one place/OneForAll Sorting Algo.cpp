Sorting Notes:
---------------
	a sorting algorithm is said to be stable if :
		Two objects with equal key appear in the same order in "Sorted Output" as they appear in "Input"

	-eg.
		I/P:
			peach    
			straw <---
			apple	  |
			spork <---
		O/P:
			apple
			peach
			straw <---
			spork <---
			
		-  Some sorting algorithms are stable by nature like { Insertion sort, Merge Sort, Bubble Sort, etc }
		and some sorting algorithms are note like { Heap-Sort, Quick-Sort, etc }


		* Sorting algorithms are :
		  1-Internal
				1.Insertion
					-insertion
					-Shell
				2.Selection
					-selection
					-Heap
				3.Exchange
					-Bubble
					-Quick

		   2-External (Merge)
				1.Natural
				2.Balanced



1. Selection Sort :
---------------
 	The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
	1) The subarray which is already sorted.
	2) Remaining subarray which is unsorted.
	In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
		

	
Code:
-----	
	//Author : Abdallah Hemdan
	#include <bits\stdc++.h>
	using namespace std ;

	template<typename T>
	void SelectionSort(vector<T> &Arr, int n) {
		for (int i = 0; i < n - 1; i++) {
			int min_ind = i;

			for (int j = i + 1; j < n; j++) {
				if (Arr[j] < Arr[min_ind])
					min_ind = j;
			}

			swap(Arr[min_ind], Arr[i])
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


2. Heap Sort :
--------------
	Heap Sort is also a comparision based sorting technique based on "Binary Heap Data Structure"

What is Binary Heap ?!
--------------------
	Let us first define a "Complete Binary Tree".
	
	- A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible (Source Wikipedia)

	A Binary Heap is a "Complete Binary Tree" where items are stored in a special order 
	such that value in a parent node is greater(or smaller) than the values in its two children nodes.
	The former is called as "max heap" and the latter is called "min heap". The heap can be represented by binary tree or array.

Why array based representation for Binary Heap ?!
------------------------------------------------
	Since a Binary Heap is a Complete Binary Tree, it can be easily represented as array 
	and array based representation is space efficient.
	If the parent node is stored at index (I), the left child can be calculated by (2 * I + 1) 
	and right child by (2 * I + 2) (assuming the indexing starts at 0).

Heap Sort Algorithm for sorting in increasing order:
---------------------------------------------------
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of tree.
3. Repeat above steps while size of heap is greater than 1.

Code:
-----
	//Author : Abdallah Hemdan
	#include <bits\stdc++.h>
	using namespace std;

	template<typename T>
	void Heapify(vector<T>& Arr, int n, int ind) {

		int Largest = ind; // Initialize largest as root 
		int Left = 2 * ind + 1; // left = 2*i + 1 
		int Right = 2 * ind + 2; // right = 2*i + 2 

								 // If left child is larger than root
		if (Left < n && Arr[Left] > Arr[Largest]) {
			Largest = Left;
		}

		// If right child is larger than largest so far 
		if (Right < n && Arr[Right] > Arr[Largest]) {
			Largest = Right;
		}

		// If largest is not root 
		if (Largest != ind) {
			swap(Arr[ind], Arr[Largest]);
			Heapify(Arr, n, Largest); // Recursively heapify the affected sub-tree 
		}
	}

	template<typename T>
	void HeapSort(vector<T>& Arr, int n) {
		// Build heap (rearrange array) 
		for (int i = n / 2 - 1; i >= 0; i--) {
			Heapify(Arr, n, i);
		}

		// One by one extract an element from heap 
		for (int i = n - 1; i >= 0; i--) {
			swap(Arr[0], Arr[i]);
			Heapify(Arr, i, 0); // call max heapify on the reduced heap 
		}
	}

	int main() {
		int n;  cin >> n; 
		vector<int> Arr(n); 

		for (int i = 0; i < n; i++) cin >> Arr[i];
		
		cout << "Before Sorting" << endl;
		for (auto i : Arr) cout << i << " ";
		cout << endl;
		
		HeapSort(Arr, n); 
		
		cout << "After Sorting" << endl;
		for (auto i : Arr) cout << i << " ";
		cout << endl;
	}																											


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

4. Shell Sort: O(n^2)
-------------
	The method starts by sorting pairs of elements far apart from each other,
	then progressively reducing the gap between elements to be compared.
	Starting with far apart elements, it can move some out-of-place elements 
	into position faster than a simple nearest neighbor exchange.


Code:
-----
	//Author: Abdallah Hemdan
	#include <bits\stdc++.h>
	using namespace std;

	template<typename T>
	void ShellSort(T Arr[], int n)
	{
		// We'll start  with big gap and start reduce it 
		for (int gap = n / 2; gap >= 1; gap /= 2) {
			
			for (int i = gap; i < n; i++) {
				T temp = Arr[i];
				int j;
				
				for (j = i; j >= gap && Arr[j - gap] > temp; j -= gap) {
					Arr[j] = Arr[j - gap];
				}
				// put temp (the original a[i]) in its correct location ..
				Arr[j] = temp;
			}
		}
	}

	template<typename T>
	void Print(T Arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << Arr[i] << " ";
		}
		cout << endl;
	}


	int main()
	{
		int n;
		cin >> n;
		int* Arr = new int[n];

		for (int i = 0; i < n; i++)
			cin >> Arr[i];
		
		cout << "Before Sorting" << endl;
		Print(Arr, n);
		
		ShellSort(Arr, n);
		
		cout << "After Sorting" << endl;
		Print(Arr, n);
	}


5. Bubble Sort: 
--------------
	Bubble Sort is the simplest sorting algorithm that works by repeatedly 
	swapping the adjacent elements if they are in wrong order.

	Time Complexity : O(n^2)
	Space Complexity : O(1)
	Sorting in Space : Yes
	Stable : Yes
	O(n) in Best case occurs when array is already sorted.

Code:
-----
	//Author: Abdallah Hemdan
	#include <bits\stdc++.h>
	using namespace std;

	
	template<typename T>
	void BubbleSort(T Arr[], int n) { // Optimized version of Bubble Sort
		bool Swapped;
		for (int i = 0; i < n - 1; i++) {
			Swapped = false;
			for (int j = 0; j < n - i - 1; j++) {
				if (Arr[j] > Arr[j + 1]) {
					swap(Arr[j], Arr[j + 1]);
					Swapped = true; 
				}
			}
			if (!Swapped) // If the array is already sorted then there is no need to continue
				break; 
		}
	}

	template<typename T>
	void Print(T Arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << Arr[i] << " ";
		}
		cout << endl;
	}

	int main() 
	{
		int n; 
		cin >> n;
		int* Arr = new int[n];
		
		for (int i = 0; i < n; i++)
			cin >> Arr[i]; 
		
		cout << "Before Sorting" << endl;
		Print(Arr, n); 
		
		BubbleSort(Arr, n); 
		
		cout << "After Sorting" << endl;
		Print(Arr, n);
	}																										

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
