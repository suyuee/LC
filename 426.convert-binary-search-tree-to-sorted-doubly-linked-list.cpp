/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 *
 * https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/
 *
 * algorithms
 * Medium (54.31%)
 * Likes:    584
 * Dislikes: 68
 * Total Accepted:    47K
 * Total Submissions: 85.1K
 * Testcase Example:  '{"$id":"1","val":4,"left":{"$id":"2","val":2,"left":{"$id":"4","val":1,"left":null,"right":null},"right":{"$id":"5","val":3,"left":null,"right":null}},"right":{"$id":"3","val":5,"left":null,"right":null}}'
 *
 * Convert a BST to a sorted circular doubly-linked list in-place. Think of the
 * left and right pointers as synonymous to the previous and next pointers in a
 * doubly-linked list.
 * 
 * Let's take the following BST as an example, it may help you understand the
 * problem better:
 * 
 * 
 * 
 * 
 * 
 * We want to transform this BST into a circular doubly linked list. Each node
 * in a doubly linked list has a predecessor and successor. For a circular
 * doubly linked list, the predecessor of the first element is the last
 * element, and the successor of the last element is the first element.
 * 
 * The figure below shows the circular doubly linked list for the BST above.
 * The "head" symbol means the node it points to is the smallest element of the
 * linked list.
 * 
 * 
 * 
 * 
 * 
 * Specifically, we want to do the transformation in place. After the
 * transformation, the left pointer of the tree node should point to its
 * predecessor, and the right pointer should point to its successor. We should
 * return the pointer to the first element of the linked list.
 * 
 * The figure below shows the transformed BST. The solid line indicates the
 * successor relationship, while the dashed line means the predecessor
 * relationship.
 * 
 * 
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return NULL;
        Node *cur = root, *prev = NULL, *head = NULL;
        stack<Node *> st;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (prev) {
                prev->right = cur;
                cur->left = prev;
                prev = cur;
            }
            else {
                head = cur;
                prev = cur;
            }
            cur = cur->right;
        }
        prev->right = head;
        head->left = prev;
        return head;
    }
};
// @lc code=end
