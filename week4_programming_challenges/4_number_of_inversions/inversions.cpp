/*Author : Abdallah Hemdan */
/***********************************************/
/*
   ___  ___
* |\  \|\  \
* \ \  \_\  \
*  \ \   ___ \emdan
*   \ \  \\ \ \
*    \ \__\\ \_\
*     \|__| \|__|
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
typedef   long long int               ll;

using namespace std;
  
int MERGESORT(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 

int mergeSort(int arr[], int array_size) { 
    int temp[array_size]; 
    return MERGESORT(arr, temp, 0, array_size - 1); 
} 

int MERGESORT(int arr[], int temp[], int left, int right) { 
    int mid, inv_count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
        inv_count = MERGESORT(arr, temp, left, mid); 
        inv_count += MERGESORT(arr, temp, mid + 1, right); 
  
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 

int merge(int arr[], int temp[], int left, int mid, int right) { 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; 
    j = mid; 
    k = left;
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
  
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
  
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
  
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count; 
} 
int main(){
    int n ; 
    scanf("%d",&n);
    int arr[n];
    for(int i=0 ;i<n ;i++)
        scanf("%d",&arr[i]);
    cout << mergeSort(arr,n) << endl ;
}

