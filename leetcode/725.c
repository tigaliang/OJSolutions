//
// Split Linked List in Parts
// https://leetcode.com/problems/split-linked-list-in-parts/description/
//

#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize)
{
    struct ListNode *node;
    int len = 0;
    int size, remain, real_size;
    struct ListNode **ret;
    int i, s;
    struct ListNode *prev;

    node = root;
    while (node) {
        ++len;
        node = node->next;
    }

    size = len / k;
    remain = len % k;

    *returnSize = k;
    ret = (struct ListNode **)malloc(sizeof(struct ListNode *) * k);
    for (i = 0; i < k; ++i)
        ret[i] = NULL;

    node = root;
    for (i = 0; i < k; ++i) {
        ret[i] = node;
        real_size = size + (i < remain ? 1 : 0);
        for (s = 0; s < real_size; ++s) {
            if (s == real_size - 1)
                prev = node;
            if (node)
                node = node->next;
        }
        if (prev)
            prev->next = NULL;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    struct ListNode n4 = {4,NULL};
    struct ListNode n3 = {3,&n4};
    struct ListNode n2 = {2,&n3};
    struct ListNode n1 = {1,&n2};
    struct ListNode **r;
    struct ListNode *n;
    int returnSize;
    int i;

    r = splitListToParts(&n1, 5, &returnSize);

    for (i = 0; i < returnSize; ++i) {
        n = r[i];
        while (n) {
            printf("%d ", n->val);
            n = n->next;
        }
        printf("\n");
    }
    return 0;
}