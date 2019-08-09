/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (42.67%)
 * Total Accepted:    48.3K
 * Total Submissions: 112.3K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all
 * equal.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= len(nums) <= 16.
 * 0 < nums[i] < 10000.
 * 
 * 
 */
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int subsum = sum / k;
        if (subsum * k != sum)
            return false;
        sort(nums.rbegin(), nums.rend());
        return partition(nums, 0, 0, k, subsum);
    }
private:
    bool partition(const vector<int> &nums, int used, int cur, int k, int target) {
        if (k == 1)
            return true;
        for (int i = 0; i < nums.size(); ++i) {
            if (used & (1 << i))
                continue;
            int sum = cur + nums[i];
            if (sum > target)
                break;
            if (sum == target && partition(nums, used | (1 << i), 0, k - 1, target))
                return true;
            else if (partition(nums, used | (1 << i), sum, k, target))
                return true;
        }
        return false;
    }
};
