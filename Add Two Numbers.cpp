/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Solution by James R. Vaughan, LeetCode ID = "JeetCode"
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummy = new ListNode(0), *current;
        current = dummy;
        
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1-> next;
            }
            if (l2) {
                carry += l2 -> val;
                l2 = l2->next;
            }
            
            current->next = new ListNode(carry%10);
            current = current->next;
            carry /= 10;
            
        }
        
        return dummy->next;
    }
};