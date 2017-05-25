/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int ii = 0; ii < nums.size(); ii++) {
            for (int kk = 0; kk < nums.size(); kk++) {
                if(ii != kk) {
                    if ((nums[ii] + nums[kk]) == target)
                    {
                        vector<int> answer {ii, kk};
                        return answer;
                    }
                }
            }
        }
    }
};