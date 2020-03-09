/*Author : Abdallah Hemdan */
/* ___   __
* |\  \|\  \
* \ \  \_\  \
*  \ \   ___ \emdan
*   \ \  \\ \ \
*    \ \__\\ \_\
*     \|__| \|__|
*/
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

void TowerOfHanoi(int n, char From, char To, char  Aux) {
	if (n == 1) {
		cout << "Move Disk 1 from rod " << From << " to rod " << To << endl;
		return;
	}
	TowerOfHanoi(n - 1, From, Aux, To); 
	cout << "Move Disk " << n << " from rod " << From << " to rod " << To << endl;
	TowerOfHanoi(n - 1, Aux, To, From);
}

int main() {
	int n; 
	cin >> n; 
	cout << endl << endl;

	/// For n disks, total (2n – 1) moves are required.
	TowerOfHanoi(n, 'A', 'C', 'B'); 
	cout << endl;
}
