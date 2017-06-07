/* Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows. */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    int reverse(int x) {
        int leftmostDigit;
        
        int position = 0;
        int a = 0;
        bool positive = true;
        if (x < 0) {positive = false;}
        int returnInt = 0;
        
        int digitsArray[1000];
        while (x != 0) {
            a = x % 10;
            x = x / 10;
            digitsArray[position] = a;
            position++;
            cout << a;
        }
        
        leftmostDigit = a;
        
        int ii = position-1;
        for (int kk = 0; kk <= ii; kk++) {
            
            returnInt += (digitsArray[kk] * pow(10, position-1));
            position--;
            
        }
        
        if (positive && (returnInt < 0)) {return 0;}
        if (!positive && (returnInt > 0)) {return 0;}
        
        if ((returnInt % 10) != leftmostDigit) {return 0;}
        
        return returnInt;
        
    }
};