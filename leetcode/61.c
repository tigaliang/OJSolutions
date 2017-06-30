//
// Rotate List
// https://leetcode.com/problems/rotate-list/#/description
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode *i, *j;
    struct ListNode *new_head;
    int l;

    if (NULL == head)
        return NULL;

    i = head;
    l = 1;
    while (i->next) {
        ++l;
        i = i->next;
    }

    k = k % l;
    if (0 == k)
        return head;

    k = l - k - 1;
    j = head;
    while (k--)
        j = j->next;

    new_head = j->next;
    j->next = NULL;
    i->next = head;

    return new_head;
}

int main(int argc, char const *argv[])
{
    return 0;
}