/* The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ?   ?

The above arrows point to positions where the corresponding bits are different. */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int remainder;
        string binaryX;
        string binaryY;
        int hammingDistance;
 
        while (x > 0)
        {
            remainder = x % 2;
            x = floor(x/2);
            binaryX.insert(0, to_string(remainder));
        }
        // 1000 % 2 [0] 500
        // 500 % 2 [0] 250
        // 250 % 2 [0] 125
        // 125 % 2 [1] 62
        // 62 % 2 [0] 31
        // 31 % 2 [1] 15
        // 15 % 2 [1] 7
        // 7 % 2 [1] 3
        // 3 % 2 [1] 1
        // 1 % 2 [1] 0
        // 512 + 256 + 128 +64 +32 + 8 = 1000
        
        while (y > 0)
        {
            remainder = y % 2;
            y = floor(y/2);
            binaryY.insert(0, to_string(remainder));
        }
        
        while (binaryX.length() < binaryY.length()) {
            binaryX.insert(0, "0"); // make both strings same length
        }
        
        while (binaryY.length() < binaryX.length()) {
            binaryY.insert(0, "0"); // make both strings same length
        }
        
        cout << binaryX << " " << binaryY << " " ;
        hammingDistance = 0; // had to do this to get rid of a bug
        
        for (int ii = 0; ii < binaryX.length(); ii++) {
            if (binaryX[ii] != binaryY[ii]) {
                hammingDistance++;
                cout << hammingDistance; // had to do this to get rid of a bug
            }
        }
        
        return hammingDistance;
        

    }
};