/* Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL. */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    vector<string> shortUrlVector;
    vector<string> longUrlVector;
    
    string randomUrl;
    string foundItem;
    
    string alphanum = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    int stringLength = sizeof(alphanum) - 1;
    
    Solution() {
        shortUrlVector.push_back("ABC");
        longUrlVector.push_back("www.google.com");
        
        shortUrlVector.push_back("XYZ");
        longUrlVector.push_back("www.microsoft.com");
        
        shortUrlVector.push_back("123");
        longUrlVector.push_back("www.apple.com");
        
        shortUrlVector.push_back("321");
        longUrlVector.push_back("www.wikipedia.org");
    }
    
    char genRandom()  // Random string generator function.
    {
        return alphanum.at(rand() % stringLength);
    }
    
    string randomString() {
        string Str;
        for(unsigned int i = 0; i < 21; ++i)
        {
            Str += genRandom();
        }
        return Str;
    }
    
    string findShortUrl(string longUrl) {
        for (unsigned int ii = 0; ii < longUrlVector.size(); ii++) {
            if (longUrlVector[ii] == longUrl) {return shortUrlVector[ii];}
        }
        return "";
    }
    
    string findLongUrl(string shortUrl) {
        for (unsigned int ii = 0; ii < shortUrlVector.size(); ii++) {
            if (shortUrlVector[ii] == shortUrl) {return longUrlVector[ii];}
        }
        return "";
    }
   
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        foundItem = "a";
        foundItem = findShortUrl(longUrl); // see if URL is already encoded
        if (foundItem != "") {return foundItem;}
        
        foundItem = "a";
        while (foundItem != "") {
            randomUrl = randomString();
            foundItem = findLongUrl(randomUrl); // Make sure random URL isn't already in database
        }
        
        shortUrlVector.push_back(randomUrl);
        longUrlVector.push_back(longUrl);
        
        return randomUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return findLongUrl(shortUrl); //returns the long URL related to the short URL 
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));