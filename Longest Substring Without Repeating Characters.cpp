/* Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring. */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
		int kk = 0;
		string substring;
		int longest = 0;
		string newChar;

		while (kk < length) {
			newChar = s.at(kk);
			if (substring.find(newChar) != string::npos) {

				int ii = 0;
				while (ii < length) 
				{
					if (substring.at(0) != s.at(kk)) { substring.erase(0,1); }
					if (substring.at(0) == s.at(kk)) { substring.erase(0,1); break;}
					
					ii++;
				}
			}

			substring += newChar;
			//cout << substring << endl;
			if (substring.length() > longest) { longest = substring.length(); }
			kk++;
		};

		//cout << substring << endl;

		return longest;
    }
};