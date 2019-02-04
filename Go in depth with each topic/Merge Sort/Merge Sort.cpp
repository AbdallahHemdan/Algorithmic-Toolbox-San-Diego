// Merge sort is Divide and Conquer algorithm
// O(nLogn).

// The idea is : It divides input array in two halves,
// calls itself for the two halves and then merges the two sorted halves

// MergeSort(arr[], l,  r)
// If r > l
//      1. Find the middle point to divide the array into two halves:  
//              middle m = (l+r)/2
//      2. Call mergeSort for first half:   
//              Call mergeSort(arr, l, m)
//      3. Call mergeSort for second half:
//              Call mergeSort(arr, m+1, r)
//      4. Merge the two halves sorted in step 2 and 3:
//              Call merge(arr, l, m, r)


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


void Merge(int Arr[], int L, int Mid, int R) {
	int LeftSize = Mid - L + 1;
	int RightSize = R - Mid;
	
	int Left[LeftSize];
	int Right[RightSize];

	for (int i = 0; i < LeftSize; i++)
		Left[i] = Arr[L + i];

	for (int i = 0; i < RightSize; i++)
		Right[i] = Arr[Mid + 1 + i];

	int Left_Index = 0;
	int Rigth_Index = 0;
	int Merged_Index = L;

	while (Left_Index < LeftSize && Rigth_Index < RightSize) {
		
		if (Left[Left_Index] <= Right[Rigth_Index]) {
			Arr[Merged_Index] = Left[Left_Index];
			Left_Index++;
		}

		else {
			Arr[Merged_Index] = Right[Rigth_Index];
			Rigth_Index++;
		}

		Merged_Index++;
	}
	
	while (Left_Index < LeftSize) {
		Arr[Merged_Index] = Left[Left_Index];
		Left_Index++; 
		Merged_Index++;
		
	}

	while (Rigth_Index < RightSize) {
		Arr[Merged_Index] = Right[Rigth_Index];
		Rigth_Index++;
		Merged_Index++;
	}

}

void MergeSort(int Arr[], int l, int r) {
	if (r > l) {
		int Mid = (l + r) / 2;

		MergeSort(Arr, l, Mid);
		MergeSort(Arr, Mid + 1, r);
	
		Merge(Arr, l, Mid, r);
	}
}

void PrintArray(int Arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << Arr[i] << " ";
}

int main() {
	int n; 
	cin >> n; 

	int Arr[n];
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
	
	MergeSort(Arr, 0, n - 1);
	PrintArray(Arr, n);
}
