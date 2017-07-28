/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5. */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int currentLast = 0;
        int currentLength = 0;
        int stringLength= s.length();
        
        for (int kk = 0; kk < stringLength; kk++) {
            if (s[kk] == ' ') { // we have a space
                if (currentLength > 0) {
                    currentLast = currentLength;
                }
                currentLength = 0;
            } else {
                currentLength++;
            }
        }
        
        if (currentLength > 0) {
            currentLast = currentLength;
        }
        
        // if s = "" will return 0
        // if s = "bob " will return 3
        // if s = "b bb" will return 2
        
        return currentLast;
        
    }
};