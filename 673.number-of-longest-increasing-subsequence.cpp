/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (33.80%)
 * Total Accepted:    32.9K
 * Total Submissions: 96.8K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 * 
 * 
 * 
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
 * 
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty())        
            return 0;
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j]) {
                    if (dp[i] == dp[j] + 1)
                        count[i] += count[j];
                    else if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                }
        int longest = *max_element(dp.begin(), dp.end());
        int number = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (dp[i] == longest)
                number += count[i];
        }
        return number;
    }
};
