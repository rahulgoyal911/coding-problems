// This problem was asked by Stripe.
// Given an array of integers, find the first missing positive integer in linear time and constant space. 
// In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
// For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
#include <bits/stdc++.h> 
using namespace std; 
void swap(int* a, int* b) 
{ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int segregate(int arr[], int size) 
{ 
    int j = 0, i; 
    for (i = 0; i < size; i++) { 
        if (arr[i] <= 0) { 
            swap(&arr[i], &arr[j]); 
            j++; 
        } 
    } 
  
    return j; 
} 

int findMissingPositive(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) { 
        if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0) 
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; 
    } 
  
    for (i = 0; i < size; i++) 
        if (arr[i] > 0) 
            return i + 1; 
  
    return size + 1; 
} 

int findMissing(int arr[], int size) 
{ 

    int shift = segregate(arr, size); 
    return findMissingPositive(arr + shift, size - shift); 
} 
  
 
int main() 
{ 
    int arr[] = { 0, 10, 2, -10, -20 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    int missing = findMissing(arr, arr_size); 
    cout << "The smallest positive missing number is " << missing; 
    return 0; 
} 