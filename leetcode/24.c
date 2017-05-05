//
// Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/#/description
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *cur1, *cur2, *cur3, *prev;

    if (NULL == head || NULL == head->next) {
        return head;
    }

    cur1 = head;
    cur2 = cur1->next;
    cur3 = cur2->next;
    head = cur2;

    while (1) {
        cur2->next = cur1;
        cur1->next = cur3;
        prev = cur1;
        if (cur3 && cur3->next) {
            cur1 = cur3;
            cur2 = cur1->next;
            cur3 = cur2->next;
            prev->next = cur2;
        } else {
            break;
        }
    }

    return head;
}

int main(int argc, char const *argv[])
{
    struct ListNode node1 = { .val = 1 };
    struct ListNode node2 = { .val = 2 };
    struct ListNode node3 = { .val = 3 };
    struct ListNode node4 = { .val = 4 };
    node1.next = &node2;
    node2.next = NULL;//&node3;
    node3.next = &node4;
    node4.next = NULL;

    struct ListNode *head = swapPairs(&node1);
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    return 0;
}