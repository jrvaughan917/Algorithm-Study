/* Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999. */

class Solution {
public:
    int romanToInt(string s) {
        int charPosition = 0;
        int totalValue = 0;
        string currentChar;
        string lookaheadChar;
        
        while (charPosition < s.length()) {
            currentChar = s.at(charPosition);
            
            if ((charPosition + 1) < s.length()) {
                lookaheadChar = s.at(charPosition + 1);
                // Having current char and lookahead char, we look at both
                if (currentChar == "I") {
                    if (lookaheadChar == "V") {totalValue += 4; charPosition += 2;}
                    else if (lookaheadChar == "X") {totalValue += 9; charPosition += 2;}
                    else {totalValue += 1; charPosition++;}
                }
                if (currentChar == "V") {totalValue += 5; charPosition++;}
                if (currentChar == "X") {
                    if (lookaheadChar == "L") {totalValue += 40; charPosition += 2;}
                    else if (lookaheadChar == "C") {totalValue += 90; charPosition += 2;}
                    else {totalValue += 10; charPosition++;}
                }
                if (currentChar == "L") {totalValue += 50; charPosition++;}
                if (currentChar == "C") {
                    if (lookaheadChar == "D") {totalValue += 400; charPosition += 2;}
                    else if (lookaheadChar == "M") {totalValue += 900; charPosition += 2;}
                    else {totalValue += 100; charPosition++;}
                }
                if (currentChar == "D") {totalValue += 500; charPosition++;}
                if (currentChar == "M") {totalValue += 1000; charPosition++;}
            } else {
                // It is last char remaining
                if (currentChar == "I") {totalValue += 1;}
                if (currentChar == "V") {totalValue += 5;}
                if (currentChar == "X") {totalValue += 10;}
                if (currentChar == "L") {totalValue += 50;}
                if (currentChar == "C") {totalValue += 100;}
                if (currentChar == "D") {totalValue += 500;}
                if (currentChar == "M") {totalValue += 1000;}
                charPosition++;
            }
        }
        
        return totalValue;
    }
};