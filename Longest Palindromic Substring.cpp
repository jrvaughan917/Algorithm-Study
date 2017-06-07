/* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb" */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        string testString = "";
        int halfWay;
        bool isPalindrome = false;
        
        for (int ii = 0; ii < s.length(); ii++) {
        	// iterates entirety of s
        
        	for (int jj = longest.length(); jj <= s.length() - ii; jj++) { 
        	    isPalindrome = true;
        	    if (jj == 0) {jj = 1;}
        	    testString = s.substr(ii, jj);
        	    halfWay = testString.length() / 2;
        	    
        	    if (halfWay == 0) {halfWay = 1;}
        	    
        	    // if length = 7, goes from [0][6], [1][5], [2][4], [3][5]
    	        // if length = 6, goes from [0][5], [1][4], [2][3]
    	        
        	    for (int kk = 0; kk < halfWay; kk++) {
            		if (testString.at(kk) != testString.at(testString.length() - kk - 1)) {isPalindrome = false; break;}	
            	}
            	if (isPalindrome) {
        			if (testString.length() > longest.length()) {longest = testString;}
        		}
        		
        		if (longest.length() >= (s.length() - ii)) {return longest;}
        	}
        }
        return longest;
    }
};