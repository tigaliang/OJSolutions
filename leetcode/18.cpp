//
// 4Sum
// https://leetcode.com/problems/4sum/#/description
//

#include <stdio.h>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct p {
    int i1;
    int i2;
};
typedef vector<p> vp;

struct r {
    int a, b, c, d;
    bool operator <(const r& x) const {
        return a < x.a ||
            (a == x.a && b < x.b) ||
            (a == x.a && b == x.b && c < x.c) ||
            (a == x.a && b == x.b && c == x.c && d < x.d);
    }
};

class Solution
{
private:
    void sort4(int *a, int *b, int *c, int *d)
    {
        int arr[4];
        arr[0] = *a;
        arr[1] = *b;
        arr[2] = *c;
        arr[3] = *d;
        for (int i = 0; i < 3; ++i) {
            int mini = i;
            for (int j  = i + 1; j < 4; ++j) {
                if (arr[j] < arr[mini]) {
                    mini = j;
                }
            }
            int tmp = arr[i];
            arr[i] = arr[mini];
            arr[mini] = tmp;
        }
        *a = arr[0];
        *b = arr[1];
        *c = arr[2];
        *d = arr[3];
    }
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target)
    {
        int s = nums.size();
        vector<vector<int> > vr;
        if (s < 4) return vr;

        map<int, vp> tmp;
        set<r> ret;

        for (int i = 0; i < s - 1; ++i) {
            for (int j = i + 1; j < s; ++j) {
                int sum = nums[i] + nums[j];
                p p1 = {.i1 = i, .i2 = j};
                if (tmp.find(sum) == tmp.end()) {
                    vp v;
                    v.push_back(p1);
                    tmp[sum] = v;
                } else {
                    tmp[sum].push_back(p1);
                }
            }
        }
        for (map<int, vp>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
            int want = target - it->first;
            map<int, vp>::iterator f = tmp.find(want);
            if (f == tmp.end()) continue;
            if (f->first < it->first) continue;
            vp v1 = it->second;
            vp v2 = f->second;
            for (int i = 0, s1 = v1.size(); i < s1; ++i) {
                for (int j = 0, s2 = v2.size(); j < s2; ++j) {
                    p p1 = v1[i];
                    p p2 = v2[j];
                    if (p1.i1 == p2.i1 || p1.i1 == p2.i2 ||
                        p1.i2 == p2.i1 || p1.i2 == p2.i2) {
                        continue;
                    }
                    int a = nums[p1.i1];
                    int b = nums[p1.i2];
                    int c = nums[p2.i1];
                    int d = nums[p2.i2];
                    sort4(&a, &b, &c, &d);
                    r r1 = {.a = a, .b = b, .c = c, .d = d};
                    ret.insert(r1);
                }
            }
        }

        for (set<r>::iterator it = ret.begin(); it != ret.end(); ++it) {
            vector<int> v;
            v.push_back(it->a);
            v.push_back(it->b);
            v.push_back(it->c);
            v.push_back(it->d);
            vr.push_back(v);
        }

        return vr;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a;
    a.push_back(1);
    a.push_back(0);
    a.push_back(-1);
    a.push_back(0);
    a.push_back(-2);
    a.push_back(2);
    Solution s;
    vector<vector<int> > ret = s.fourSum(a, 0);
    for (int i = 0; i < ret.size(); ++i) {
        printf("%d, %d, %d, %d\n", ret[i][0], ret[i][1], ret[i][2], ret[i][3]);
    }
    return 0;
}