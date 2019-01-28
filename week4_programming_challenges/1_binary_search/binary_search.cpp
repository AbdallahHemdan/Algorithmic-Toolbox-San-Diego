/*Author : Abdallah Hemdan */
/***********************************************/
/* Dear online judge:
* I've read the problem, and tried to solve it.
* Even if you don't accept my solution, you should respect my effort.
* I hope my code compiles and gets accepted.
*  ___  __
* |\  \|\  \
* \ \  \_\  \
*  \ \   ___ \emdan
*   \ \  \\ \ \
*    \ \__\\ \_\
*     \|__| \|__|
*/

#include <iostream>
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
#define     endl                     '\n'

typedef   long long int               ll;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


using namespace std;

int BinarySearch(vector<int> Arr, int n, int Target) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (Arr[mid] == Target)
			return mid;
		else if (Arr[mid] < Target) {
			l = mid + 1; 
		}
		else if (Arr[mid] > Target) {
			r = mid - 1;
		}
	}
	return -1; 
}
void FindinFirst(vector<int> First, int n, vector<int> Second, int k) {
	for (int i = 0; i < k; i++)
		cout << BinarySearch(First,n, Second[i]) << " ";
}
int main() {
	int n; 
	cin >> n;
	vector<int> First(n); 
	for (size_t i = 0; i < n; i++)
		cin >> First[i];

	int k;
	cin >> k;
	vector<int> Second(k);
	for (size_t i = 0; i < k; i++)
		cin >> Second[i];

	FindinFirst(First, n, Second, k);
}
