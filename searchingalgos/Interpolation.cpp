#include<bits/stdc++.h>
using namespace std ;
int interpolationSearch(int arr[] , int lo, int hi , int x){
    int pos ;
    if(lo <= hi && arr[lo]<=x && x<=arr[hi]) {
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
        if(arr[pos]==x)
            return pos ;
        if(arr[pos]>x){
            return interpolationSearch(arr,lo,pos-1,x); 
        }
        if(arr[pos]<x){
            return interpolationSearch(arr,pos+1,hi,x) ;
        }
    }
    return -1 ;
}



int main()
{
 
    // Array of items on which search will
    // be conducted.
    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21,
                  22, 23, 24, 33, 35, 42, 47 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Element to be searched
    int x = 18;
    int index = interpolationSearch(arr, 0, n - 1, x);
 
    // If element was found
    if (index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found.";
 
    return 0;
}
