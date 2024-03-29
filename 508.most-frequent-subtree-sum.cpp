/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
 *
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (55.22%)
 * Total Accepted:    53.5K
 * Total Submissions: 96.7K
 * Testcase Example:  '[5,2,-3]'
 *
 * 
 * Given the root of a tree, you are asked to find the most frequent subtree
 * sum. The subtree sum of a node is defined as the sum of all the node values
 * formed by the subtree rooted at that node (including the node itself). So
 * what is the most frequent subtree sum value? If there is a tie, return all
 * the values with the highest frequency in any order.
 * 
 * 
 * Examples 1
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * return [2, -3, 4], since all the values happen only once, return all of them
 * in any order.
 * 
 * 
 * Examples 2
 * Input:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * return [2], since 2 happens twice, however -5 only occur once.
 * 
 * 
 * Note:
 * You may assume the sum of values in any subtree is in the range of 32-bit
 * signed integer.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        trace(root);
        vector<int> result;
        int frq = 0;
        for (auto &it : m_) {
            int times = it.second;
            int sum = it.first;
            if (times == frq)
                result.push_back(sum);
            else if (times > frq) {
                frq = times;
                result.clear();
                result.push_back(sum);
            }
        }
        return result;
    }
private:
    unordered_map<int, int> m_;
    int trace(TreeNode *root) {
        if (root == NULL)
            return 0;
        int l = trace(root->left);
        int r = trace(root->right);
        int sum = l + r + root->val;
        ++m_[sum];
        return sum;
    }
};
