/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (34.29%)
 * Total Accepted:    65.9K
 * Total Submissions: 191.6K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * The length of path between two nodes is represented by the number of edges
 * between them.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Note: The given binary tree has not more than 10000 nodes. The height of the
 * tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        maxlen = 0;
        track(root);
        return maxlen;
    }
private:
    int maxlen;
    int track(TreeNode *root) {
        if (root == NULL)
            return 0;
        int l = track(root->left),
            r = track(root->right);
        if (root->left) {
            if(root->left->val == root->val)
                ++l;
            else
                l = 0;
        }
        if (root->right) {
            if (root->right->val == root->val)
                ++r;
            else
                r = 0;
        }
        maxlen = max(maxlen, l + r);
        return max(l, r);
    }
};
