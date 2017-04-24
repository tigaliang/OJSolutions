//
// Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/#/description
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head = NULL;
    struct ListNode* cur;

    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    cur = head;

    while (1) {
        if (!l1) {
            cur->next = l2;
            break;
        }
        if (!l2) {
            cur->next = l1;
            break;
        }
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    return head;
}

int main(int argc, char const *argv[])
{
    return 0;
}