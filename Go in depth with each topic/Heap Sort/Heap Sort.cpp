// Author : Abdallah Hemdan
2) Heap Sort : O(nLogn)
--------------
	- Heap Sort is also a comparision based sorting technique based on "Binary Heap Data Structure"

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
	#include <bits\stdc++.h>
	using namespace std;

	void Heapify(vector<int>& Arr, int n, int ind) {
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
	void BuildHeap(){
		// Build heap (rearrange array) 
		for (int i = n / 2 - 1; i >= 0; i--) {
			Heapify(Arr, n, i); 
		}
	}
	void HeapSort(vector<int>& Arr, int n) {
		BuildHeap(); // Build heap (rearrange array) 
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
