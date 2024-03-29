/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.04%)
 * Total Accepted:    498.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size(), n = nums2.size();
        if (m < n)
            return findMedianSortedArrays(nums2, nums1);
        if (n == 0)
            return m & 1 ? nums1[m/2] : (nums1[m/2] + nums1[m/2-1]) / 2.0;
        int i = 0, j = 0, ilo = 0, ihi = m;
        while (ilo <= ihi) {
            i = ilo + (ihi - ilo) / 2;
            j = (m + n + 1) / 2 - i;
            cout << i << " " << j << endl;
            if (j < 0)
                ihi = i - 1;
            else if (j > n)
                ilo = i + 1;
            else if (i < m && j > 0 && nums2[j-1] > nums1[i])
                ilo = i + 1;
            else if (j < n && i > 0 && nums1[i-1] > nums2[j])
                ihi = i - 1;
            else
                break;
        }
        int num1, num2;
        if (i == 0)
            num1 = nums2[j-1];
        else if (j == 0)
            num1 = nums1[i-1];
        else
            num1 = max(nums1[i-1], nums2[j-1]);

        if ((m + n) & 1)
            return num1;

        if (i == m)
            num2 = nums2[j];
        else if (j == n)
            num2 = nums1[i];
        else
            num2 = min(nums1[i], nums2[j]);

        return (num1 + num2) / 2.0;
    }
};
