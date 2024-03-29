/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.79%)
 * Total Accepted:    317.9K
 * Total Submissions: 940.5K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
private:
    int findLow (vector<int> &nums, int pos, int lowBound) {
        int l = lowBound, r = pos - 1, target = nums[pos];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r + 1;
    }
    int findHigh (vector<int> &nums, int pos, int highBound) {
        int l = pos + 1, r = highBound, target = nums[pos];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l - 1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] == target) 
                return {findLow(nums, mid, l), findHigh(nums, mid, r)};
            else
                r = mid - 1;
        }
        return {-1, -1};
    }
};
