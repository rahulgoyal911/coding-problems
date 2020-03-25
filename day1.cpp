// This problem was recently asked by Google.
// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
// Bonus: Can you do this in one pass?
using namespace std;
#include<iostream>
#include <bits/stdc++.h> 
int fun(int *a,int k){
    set <int, greater <int> > name; 
    int n = 4;
    for(int i=0; i<n ; i++){
        name.insert(a[i]);
        int diff;
        diff = k - a[i];
        set <int, greater <int> > :: iterator itr; 
        for (itr = name.begin(); itr != name.end(); ++itr) 
        { 
            if(*itr == diff){
                return 1;
            }
        } 
    }   
    return 0;
}
int main()
{
    int a[] = {10, 15, 3, 7};
    int k = 17;
    cout<<fun(a,k);
}

