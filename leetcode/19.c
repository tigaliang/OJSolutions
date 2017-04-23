//
// Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/description
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int i;
    struct ListNode *cur1, *cur2;
    struct ListNode *tmp;

    if (head == NULL) {
        return NULL;
    }

    cur1 = head;
    cur2 = head;
    for (i = 0; i < n; ++i) {
        cur2 = cur2->next;
    }

    if (cur2 == NULL) {
        head = head->next;
    } else {
        while (cur2->next) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        tmp = cur1->next;
        cur1->next = cur1->next->next;
    }

    // free(tmp);

    return head;
}

int main(int argc, char const *argv[])
{
    struct ListNode n1;
    n1.val = 1;
    struct ListNode n2;
    n2.val = 2;
    struct ListNode n3;
    n3.val = 3;
    struct ListNode n4;
    n4.val = 4;
    struct ListNode n5;
    n5.val = 5;

    struct ListNode *cur;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;

    cur = removeNthFromEnd(&n1, 5);
    while (cur) {
        printf("%d\n", cur->val);
        cur = cur->next;
    }

    return 0;
}