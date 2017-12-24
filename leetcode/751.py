# -*- coding: utf-8 -*-

#
# IP to CIDR
# https://leetcode.com/contest/weekly-contest-64/problems/ip-to-cidr/
#

def ipstrtoint(ipstr):
    ts = ipstr.split('.')
    return int(ts[0]) * 0x1000000 \
        + int(ts[1]) * 0x10000 \
        + int(ts[2]) * 0x100 \
        + int(ts[3])

def inttoipstr(i):
    ts = []
    ts.append(str(i / 0x1000000))
    i %= 0x1000000
    ts.append(str(i / 0x10000))
    i %= 0x10000
    ts.append(str(i / 0x100))
    i %= 0x100
    ts.append(str(i))
    return '.'.join(ts)

def dodo(startipstr, range, ret):
    if range == 0:
        return
    zeronum = 0
    i = 31
    ipint = ipstrtoint(startipstr)
    ipbin = bin(ipint)[2:]
    ipbin = '0' * (32 - len(ipbin)) + ipbin
    while i >= 0:
        if ipbin[i] == '0':
            zeronum += 1
            i -= 1
        else:
            break
    # print zeronum
    while 2 ** zeronum > range:
        zeronum -= 1
    ret.append('%s/%d' %(startipstr, 32 - zeronum))
    c = 2 ** zeronum
    # print inttoipstr(ipint + c)
    dodo(inttoipstr(ipint + c), range - c, ret)

class Solution(object):
    def ipToCIDR(self, ip, range):
        ret = []
        dodo(ip, range, ret)
        return ret

sol = Solution()
print sol.ipToCIDR('117.145.102.62', 8)