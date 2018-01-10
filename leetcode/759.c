//
// Employee Free Time
// https://leetcode.com/contest/weekly-contest-66/problems/employee-free-time/
//

#include <stdio.h>

struct Interval {
    int start;
    int end;
};

#include <stdlib.h>

struct list {
    struct Interval *iv;
    struct list *next;
};

#define NEW_NODE(n, i) { (n) = (struct list *)malloc(sizeof(struct list)); (n)->iv = i; (n)->next = NULL; }
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static struct list* merge_interval(struct list *head, struct Interval *ni)
{
    struct list *node1, *node2;
    struct Interval *li;
    struct list *tmp;
    struct list *prev;
    int start, end;
    int flag = 0;

    node1 = head;
    prev = NULL;
    while (node1) {
        li = node1->iv;
        if (li->start > ni->end) {
            // insert before node1
            flag = 1;
            break;
        }

        if (li->end < ni->start) {
            // continue
            prev = node1;
            node1 = node1->next;
            continue;
        }

        start = MIN(li->start, ni->start);
        break;
    }

    if (node1 == NULL) {
        // add to tail
        NEW_NODE(tmp, ni);
        prev->next = tmp;
        return head;
    }

    if (flag == 1) {
        NEW_NODE(tmp, ni);
        tmp->next = node1;
        if (prev)
            prev->next = tmp;
        return prev ? head : tmp;
    }

    node2 = node1->next;
    prev = node1;
    while (node2) {
        if (node2->iv->start >= ni->end)
            break;
        prev = node2;
        node2 = node2->next;
    }

    end = MAX(prev->iv->end, ni->end);
    node1->iv->start = start;
    node1->iv->end = end;

    while (node1->next != node2) {
        tmp = node1->next;
        node1->next = node1->next->next;
        free(tmp);
    }

    return head;
}

struct Interval* employeeFreeTime(struct Interval** schedule, int rowSize, int *colSizes, int* returnSize)
{
    int i, j;
    struct list *scheds = NULL;
    struct list *node;
    struct Interval *ret;

    for (i = 0; i < rowSize; ++i) {
        for (j = 0; j < colSizes[i]; ++j) {
            if (scheds == NULL) {
                NEW_NODE(scheds, &schedule[i][j]);
            } else {
                scheds = merge_interval(scheds, &schedule[i][j]);
            }
        }
    }

    node = scheds;
    *returnSize = 0;
    while (node) {
        if (!node->next || node->iv->end != node->next->iv->start)
            ++(*returnSize);
        node = node->next;
    }
    *returnSize -= 1;

    ret = (struct Interval *)malloc(sizeof(struct Interval) * (*returnSize));
    for (i = 0, node = scheds; i < *returnSize; node = node->next) {
        if (node->iv->end != node->next->iv->start) {
            ret[i].start = node->iv->end;
            ret[i].end = node->next->iv->start;
            ++i;
        }
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    // [[[1,2],[5,6]],[[1,3]],[[4,10]]]
    struct Interval s0[] = { {1,2},{5,6} };
    struct Interval s1[] = { {1,3} };
    struct Interval s2[] = { {4,10} };
    struct Interval* schedule[3];
    int rowSize = 3;
    int colSizes[] = {2, 1, 1};
    int returnSize;
    int i;
    struct Interval *ret;

    schedule[0] = s0;
    schedule[1] = s1;
    schedule[2] = s2;
    ret = employeeFreeTime(schedule, rowSize, colSizes, &returnSize);

    printf("%d\n", returnSize);

    for (i = 0; i < returnSize; ++i)
        printf("%d,%d\n", ret[i].start, ret[i].end);

    return 0;
}