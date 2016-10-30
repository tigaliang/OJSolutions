//
// Queue Reconstruction by Height
// https://leetcode.com/problems/queue-reconstruction-by-height/
//

#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int>    P;
typedef vector< P >       VP;

class Solution {
private:
    void quicksort(VP* people, int l, int r) {
    if (l >= r) {
        return;
    }

    int i = l;
    int j = r;
    P p = (*people)[l];

    while (1) {

        while (j > i
            && ((*people)[j].first < p.first
                || ((*people)[j].first == p.first
                    && (*people)[j].second > p.second))) --j;
        (*people)[i] = (*people)[j];

        while (i < j
            && ((*people)[i].first > p.first
                || ((*people)[i].first == p.first
                    && (*people)[i].second < p.second))) ++i;
        (*people)[j] = (*people)[i];

        if (i == j) {
            (*people)[i] = p;
            break;
        }
    }

    quicksort(people, l, i -1);
    quicksort(people, i + 1, r);
}
public:
    VP reconstructQueue(VP& people) {
        quicksort(&people, 0, people.size() - 1);

        P tmp;
        for (int i = 0; i < people.size(); ++i) { 
            if (people[i].second < i) {
                tmp = people[i];
                for (int j = i; j > tmp.second; --j) {
                    people[j] = people[j - 1];
                }
                people[tmp.second] = tmp;
            }
        }

        return people;
    }
};

int main(int argc, char** argv) {
    // [[9,0],[7,0],[1,9],[3,0],[2,7],[5,3],[6,0],[3,4],[6,2],[5,2]]
    VP people;
    people.push_back(P(9, 0));
    people.push_back(P(7, 0));
    people.push_back(P(1, 9));
    people.push_back(P(3, 0));
    people.push_back(P(2, 7));
    people.push_back(P(5, 3));
    people.push_back(P(6, 0));
    people.push_back(P(3, 4));
    people.push_back(P(6, 2));
    people.push_back(P(5, 2));

    Solution sol;
    people = sol.reconstructQueue(people);

    for (VP::iterator it = people.begin(); it != people.end(); ++it) {
        printf("%d, %d\n", it->first, it->second);
    }

    return 0;
}
