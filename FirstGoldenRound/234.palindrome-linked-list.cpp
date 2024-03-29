/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (36.43%)
 * Total Accepted:    273.4K
 * Total Submissions: 750K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool check(ListNode *&slow, ListNode *quick) {
        if (quick == NULL)
            return true;
        bool checkNext = check(slow, quick->next);
        if (slow->val != quick->val)
            return false;
        slow =slow->next;
        return checkNext;
    }
public:
    bool isPalindrome(ListNode* head) {
        return check(head, head);  
    }
};
