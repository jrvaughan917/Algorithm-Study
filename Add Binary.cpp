/* Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    string addBinary(string a, string b) {
        string c = "";
        
        while (a.length() < b.length()) {a = "0" + a;}
        while (b.length() < a.length()) {b = "0" + b;}
        // pad zeroes until both numbers have the same number of digits
        
        int kk = a.length() - 1;
        int carry = 0;
        
        while (kk >= 0) {
        	if (carry == 0) {
        	    if ((a.at(kk) == '0') && (b.at(kk) == '0')) {c = "0" + c; carry = 0;}
        	    if ((a.at(kk) == '1') && (b.at(kk) == '0')) {c = "1" + c; carry = 0;}
        	    if ((a.at(kk) == '0') && (b.at(kk) == '1')) {c = "1" + c; carry = 0;}
        	    if ((a.at(kk) == '1') && (b.at(kk) == '1')) {c = "0" + c; carry = 1;}
        	} else if (carry == 1) {
        	    if ((a.at(kk) == '0') && (b.at(kk) == '0')) {c = "1" + c; carry = 0;}
        	    if ((a.at(kk) == '1') && (b.at(kk) == '0')) {c = "0" + c; carry = 1;}
        	    if ((a.at(kk) == '0') && (b.at(kk) == '1')) {c = "0" + c; carry = 1;}
        	    if ((a.at(kk) == '1') && (b.at(kk) == '1')) {c = "1" + c; carry = 1;}
        	}
        	
        	kk--;
        }
        
        if (carry == 1) {
            c = "1" + c;
        }
    
        return c;
    }
    
};
