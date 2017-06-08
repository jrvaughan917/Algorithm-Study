/* Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length. */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> wordBench;
        string justifiedWordBench;
        vector<string> returnWords;
        vector<string> spacesBench;
        int remainingSpace = 0;
        int benchChars = 0;
        int spacePosition = 0;
        string newWord;
        
        while (words.size() > 0) {
            wordBench.clear();
            justifiedWordBench = "";
            
            wordBench.push_back(words[0]);
            words.erase(words.begin());
            // insert the word into the wordBench
            
            remainingSpace = maxWidth - (wordBench.back()).size();
            
            while ((words.size() > 0) && ((remainingSpace) >= (words[0]).size() + 1)) {
                cout << ((remainingSpace) > (words[0]).size() + 1);
                wordBench.push_back(words[0]);
                words.erase(words.begin());
                remainingSpace = remainingSpace -1 - (wordBench.back()).size();
            }
            // wordBench is now full.
            
            if (wordBench.size() == 1) {
                remainingSpace = maxWidth - (wordBench[0]).size();
                justifiedWordBench += wordBench[0];
                
                for (int ii = 0; ii < remainingSpace; ii++) {
                    justifiedWordBench += " "; // pad spaces until maxWidth
                }
                
            } else if (words.size() == 0) {
                // the last line has to be left justified...
                benchChars = 0;
                for (int kk = 0; kk < wordBench.size(); kk++) {
                    benchChars += (wordBench[kk]).size();
                }
                remainingSpace = maxWidth - benchChars;
                // count up how many spaces remain
                spacesBench.clear();
                
                for (int jj = 0; jj < (wordBench.size() -1); jj++) {
                    spacesBench.push_back(" ");
                    remainingSpace--;
                    // initialize the spaces bench with a set number of elements
                }
                
                // now have a full wordBench and a full spacesBench, we need to combine them
                for (int mm = 0; mm < wordBench.size(); mm++) {
                    justifiedWordBench += wordBench[mm];
                    
                    if (mm < spacesBench.size()) {
                        justifiedWordBench += spacesBench[mm];
                    }
                }
                
                // now we add the remaining spaces to the right...
                for (int ii = 0; ii < remainingSpace; ii++) {
                    justifiedWordBench += " "; // pad spaces until maxWidth
                }
            } else {
                benchChars = 0;
                for (int kk = 0; kk < wordBench.size(); kk++) {
                    benchChars += (wordBench[kk]).size();
                }
                remainingSpace = maxWidth - benchChars;
                // count up how many spaces remain
                
                spacesBench.clear();
                for (int jj = 0; jj < (wordBench.size() -1); jj++) {
                    spacesBench.push_back(" ");
                    remainingSpace--;
                    // initialize the bench with a set number of elements
                }
                
                spacePosition = 0;
                while (remainingSpace > 0) {
                    if (spacePosition >= spacesBench.size()) {spacePosition = 0;}
                    spacesBench[spacePosition] += " ";
                    remainingSpace--;
                    spacePosition++;
                    // iterate across the spacesBench and add remaining spaces from left to right
                }
                // now have a full wordBench and a full spacesBench, we need to combine them
                for (int mm = 0; mm < wordBench.size(); mm++) {
                    justifiedWordBench += wordBench[mm];
                    
                    if (mm < spacesBench.size()) {
                        justifiedWordBench += spacesBench[mm];
                    }
                }
            }
            
            returnWords.push_back(justifiedWordBench);
        }
        
        return returnWords;
    }
};