#
# Prime Number of Set Bits in Binary Representation
# https://leetcode.com/contest/weekly-contest-67/problems/prime-number-of-set-bits-in-binary-representation/
#

def is_prime(n):
    if n == 2 or n == 3: return True
    if n < 2 or n%2 == 0: return False
    if n < 9: return True
    if n%3 == 0: return False
    r = int(n**0.5)
    f = 5
    while f <= r:
        if n%f == 0: return False
        if n%(f+2) == 0: return False
        f +=6
    return True

class Solution(object):
    def countPrimeSetBits(self, L, R):
        ret = 0
        for i in range(L, R + 1):
            c = bin(i)[2:].count('1')
            if is_prime(c):
                ret += 1
        return ret

sol = Solution()
print sol.countPrimeSetBits(10, 15)