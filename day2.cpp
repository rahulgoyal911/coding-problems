// Given an array of integers, return a new array such that each element at index i of the new array is the 
// product of all the numbers in the original array except the one at i.
// for example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
//  If our input was [3, 2, 1], the expected output would be [2, 3, 6].
// Follow-up: what if you can't use division?

using namespace std;
#include<iostream>
void productArray(int arr[],int n){
    if(n==1){
        cout<<0;
        return;
    }
    int i,temp = 1;
    int prod[n];
    for(int i=0;i<n;i++){
        prod[i] = 1;
    }

    for(int i=0;i<n;i++){
        prod[i] = temp;
        temp *= arr[i];
    }
    temp = 1;
    for(int i=n-1;i>=0;i--){
        prod[i] *=temp;
        temp*=arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<prod[i]<<" ";
    }

}

int main()
{
    int a[] = {10, 3, 5, 6, 2};
    int n = sizeof(a)/sizeof(a[0]);
    productArray(a,n);
    return 0;
}