/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (31.63%)
 * Total Accepted:    385.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = min(max(3, x / 2), 50000);
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long product = (long)mid * mid;
            if (product == x)
                return mid;
            else if (product > x)
                r = mid;
            else
                l = mid + 1;
        }
        return r - 1;
    }
};
