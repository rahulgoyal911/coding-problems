// This problem was asked by Facebook.
// Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
// For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
// You can assume that the messages are decodable. For example, '001' is not allowed.


#include <iostream> 
#include <cstring> 
using namespace std; 
   
int countDecoding(char *digits, int n) 
{ 
    if (n == 0 || n == 1) 
        return 1; 
    if(digits[0]=='0') 
          return 0;  
    int count = 0;  
    if (digits[n-1] > '0') 
        count =  countDecoding(digits, n-1); 
    if (digits[n-2] == '1' ||  
                  (digits[n-2] == '2' && digits[n-1] < '7') ) 
        count +=  countDecoding(digits, n-2); 
  
    return count; 
} 
int main() 
{ 
    char digits[] = "1234"; 
    int n = strlen(digits); 
    cout << "Count is " << countDecoding(digits, n); 
    return 0; 
} 
// Modified by Atanu Sen