//
// Find Anagram Mappings
// https://leetcode.com/contest/weekly-contest-66/problems/find-anagram-mappings/
//

#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, int> idx;
        for (int i = 0; i < B.size(); ++i)
            idx[B[i]] = i;
        vector<int> r;
        for (int i = 0; i < A.size(); ++i)
            r.push_back(idx[A[i]]);
        return r;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> A;
    vector<int> B;
    A.push_back(12);
    A.push_back(28);
    A.push_back(46);
    A.push_back(32);
    A.push_back(50);
    B.push_back(50);
    B.push_back(12);
    B.push_back(32);
    B.push_back(46);
    B.push_back(28);
    vector<int> r;
    Solution s;
    r = s.anagramMappings(A, B);
    for (int i = 0; i < r.size(); ++i)
        printf("%d\n", r[i]);
    return 0;
}