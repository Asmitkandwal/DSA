/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // OPTIMAL APPROACH: Fast & Slow Pointers (Tortoise and Hare)
        // Eliminates the need for a first pass to count nodes.
        ListNode* slow = head; // Moves 1 step at a time
        ListNode* fast = head; // Moves 2 steps at a time

        // Loop continues until 'fast' hits the end of the list:
        // - Even length: fast reaches nullptr
        // - Odd length:  fast reaches the last node (fast->next is nullptr)
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // 1 step forward
            fast = fast->next->next; // 2 steps forward
        }

        // When fast reaches the end, slow is guaranteed to be at the middle node
        return slow;
    }
};