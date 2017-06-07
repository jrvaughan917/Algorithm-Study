/* Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list. */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0;
        int carry = 0;
        int position = digits.size() - 1;
    
        sum = digits[position] + 1;
        if (sum == 10) {
        	digits[position] = 0;
        	carry = 1;
        	position--;
        } else { digits[position] = sum; }
        
        while ((carry == 1) && (position >= 0)) {
        	sum = digits[position] + 1;
        	carry = 0;
        	if (sum == 10) {
        		digits[position] = 0;
        		carry = 1;
        		position--;
        	} else { digits[position] = sum; }
        }
        
        if (carry == 1) {digits.insert(digits.begin() , 1);}

        return digits;
    }
};