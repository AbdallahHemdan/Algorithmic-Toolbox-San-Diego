#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

class PriorityQueue {
private:
	vector<int> pq;
	int Parent(int x) {
		return (x - 1) / 2; 
	}
	int Left_Child(int x) {
		return 2 * x + 1; 
	}
	int Right_Child(int x) {
		return 2 * x + 2; 
	}
	void Heapify_Down(int i) {
		int left = Left_Child(i);
		int right = Right_Child(i);
		
		int Largest = i;
		if (left < pq.size()) {
			if (pq[left] > pq[Largest]) {
				Largest = left;
			}
		}
		if (right < pq.size()) {
			if (pq[right] > pq[Largest]) {
				Largest = right;
			}
		}
		if (Largest != i) {
			swap(pq[Largest], pq[i]);
			Heapify_Down(Largest);
		}
	}
	void Heapify_Up(int i) {
		int parent = Parent(i);
		if (i && pq[parent] < pq[i]) {
			swap(pq[parent], pq[i]);
			Heapify_Up(parent);
		}
	}
public:
	int Size() {
		return pq.size();
	}
	bool Empty() {
		return Size() == 0; 
	}
	void Push(int key) {
		pq.push_back(key);
		int index = Size() - 1; 
		Heapify_Up(index);
	}
	void Pop() {
		try	{
			if (Empty()) {
				throw out_of_range("Vector<X>::at() : " 
					"index is out of range(Heap underflow)");
			}
			pq[0] = pq.back();
			pq.pop_back();
			Heapify_Down(0);
		}
		catch (const std::exception& error) {
			cout << error.what() << endl;
		}
	}
	int Top() {
		try {
			if (Empty()) {
				throw out_of_range("Vector<X>::at() : "
					"index is out of range(Heap underflow)");
			}
			return pq[0];
		}
		catch (const std::exception& error) {
			cout << error.what() << endl;
		}
	}
};
int main() {
	PriorityQueue pq;
	pq.Push(3);
	pq.Push(2);
	pq.Push(15);

	cout << "The Size of the Priority Queue " << pq.Size() << endl;

	cout << pq.Top() << " ";
	pq.Pop();

	cout << pq.Top() << " ";
	pq.Pop();

	pq.Push(5);
	pq.Push(4);
	pq.Push(45);

	cout << endl << "Size is " << pq.Size() << endl;

	cout << pq.Top() << " ";
	pq.Pop();

	cout << pq.Top() << " ";
	pq.Pop();

	cout << pq.Top() << " ";
	pq.Pop();

	cout << pq.Top() << " ";
	pq.Pop();

	cout << endl;
	cout << std::boolalpha << pq.Empty() << endl;

	pq.Top();	// Top operation on an empty heap
	pq.Pop();	// Pop operation on an empty heap

}
