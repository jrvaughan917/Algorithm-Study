/* You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer. */

// Solution by James R. Vaughan, LeetCode ID = "JeetCode"

class Solution {
public:
    int climbStairs(int n) {
        int max2steps = 0;
        int twoSteps = 0;
        int uniqueWays = 0;
        
        long long myFactorial = 0;
        long long myNewFactorial = 0;
        long long myMultiplicand = 0;
        
        long long addCount = 0;
        
        max2steps = floor(n/2);
        
        while (twoSteps <= max2steps) {
            if (twoSteps == 0) {
                uniqueWays++;
            } else {
                //myFactorial = factorial(twoSteps);
                //myMultiplicand = multiplicand((n-twoSteps), twoSteps);
                
                addCount = 1;
                myMultiplicand = n - twoSteps;
                myFactorial = 1;
                myNewFactorial = 1;
                
                for (int kk = 0; kk < twoSteps; kk++) {
                    addCount = addCount * myMultiplicand;
                    myNewFactorial = myNewFactorial * myFactorial;
                    
                    if ((addCount % myNewFactorial) == 0) {
                        addCount = addCount / myNewFactorial;
                        myNewFactorial = 1;
                    }
                    
                    myMultiplicand--;
                    myFactorial++;
                }
                
                uniqueWays += (int)addCount;
                
                //uniqueWays += (int)round(myMultiplicand / myFactorial);
                //uniqueWays += addCount;
                //cout << addCount << endl;
                // for say 3 twoSteps, we have (n-3)(n-4)(n-5) / (3!) unique ways
                // if number of steps = 11, we have (8*7*6)/(3*2) = 56 ways
                // if number of steps = 7, we have (4*3*2)/(3*2) = 4 ways
                // if number of steps = 6, we have (3*2)/(3*2) = 1 way
                
            }
            
            twoSteps++;
        }
        
        return uniqueWays;
    }
    
    long long factorial(int n) {
        long long a = 1;
        
        for(int i = 1; i <=n; ++i)
        {
            a *= i;
        }
        return a;
    }
    
    long long multiplicand(int n, int r) {
        long long m = n;
        long long a = n-1;
        for (int i = 1; i < r; i++) { // repeats r-1 times
            m *= a;
            a--;
            
            // if n = 4, r = 3; returns (4)(3)(2) = 24
        }
        
        return m;
    }
};