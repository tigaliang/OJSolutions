//
// Group Anagrams
// https://leetcode.com/problems/anagrams/#/description
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef unsigned long long ull;

unsigned primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
    41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        map<ull, vector<string> > ret;
        int size = strs.size();
        for (int i = 0; i < size; ++i) {
            int len = strs[i].size();
            ull product = 1;
            for (int j = 0; j < len; ++j) {
                product *= primes[strs[i][j] - 'a'];
            }
            if (ret.find(product) != ret.end()) {
                ret[product].push_back(strs[i]);
            } else {
                vector<string> v;
                v.push_back(strs[i]);
                ret[product] = v;
            }
        }
        for (map<ull, vector<string> >::iterator it = ret.begin();
            it != ret.end(); ++it) {
            result.push_back(it->second);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");

    Solution sol;
    vector<vector<string> > ret = sol.groupAnagrams(strs);

    for (int i = 0, size = ret.size(); i < size; ++i) {
        vector<string> tmp = ret[i];
        for (int j = 0, ssize = tmp.size(); j < ssize; ++j) {
            printf("%s ", tmp[j].c_str());
        }
        printf("\n");
    }

    return 0;
}