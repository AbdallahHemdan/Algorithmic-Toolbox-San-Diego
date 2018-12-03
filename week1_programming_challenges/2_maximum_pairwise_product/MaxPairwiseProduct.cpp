#include<iostream>
#include<algorithm>
#include<vector>

using namespace std; 

// Function To Calc The Max Product
long long int MaxPairwiseProductFast(vector<int> arr, int n) {
	sort(arr.begin(), arr.end()); 
	return (long long int)(arr[n - 1]) * (arr[n - 2]); 
}

int main() {
	int n; 
	cin >> n; 
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	long long int Res = MaxPairwiseProductFast(arr, n);
	cout << Res << endl; 
}
