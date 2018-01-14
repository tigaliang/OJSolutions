#
# Partition Labels
# https://leetcode.com/contest/weekly-contest-67/problems/partition-labels/
#

class Solution(object):
    def partitionLabels(self, S):
        ret = []
        start = 0
        while True:
            print S[start]
            end = S.rfind(S[start])
            tmp = S[start:end+1]
            i = 0
            while i < len(tmp):
                c = tmp[i]
                new_end = S.rfind(c)
                if new_end > end:
                    end = new_end
                    tmp = S[start:end+1]
                i += 1

            ret.append(end - start + 1 )

            start = end + 1
            if start >= len(S):
                break
        return ret

sol = Solution()
print sol.partitionLabels('ababcbacadefegdehijhklij')