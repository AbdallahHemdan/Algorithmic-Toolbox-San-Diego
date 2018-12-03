#include<iostream>

using namespace std ; 

// Function To Add Two Numbers  
int Sum(int a, int b) {
	return a + b; 
}

int main() {
	int a, b; 
	cin >> a >> b; 
	cout << Sum(a, b) << endl;
}
