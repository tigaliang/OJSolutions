//
// Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/?tab=Description
//

#include <stdio.h>
#include <vector>
#include <map>
#include <string>

class Solution {
public:
	std::string fractionToDecimal(int numerator, int denominator) {
		typedef long long LL;
		typedef std::pair<LL, LL> PLL;
		std::string ret("");
		std::map<PLL, int> record;
		LL num;
		LL den;
		std::map<PLL, int>::iterator mit;
		int i;
		char tmp;
		LL quotient;

		num = numerator;
		den = denominator;

		if ((num < 0 && den > 0) || (num > 0 && den < 0)) {
			ret += "-";
		}

		num = num < 0 ? -num : num;
		den = den < 0 ? -den : den;

		ret += std::to_string(num / den);
		num %= den;
		if (num) ret += ".";

		while (num) {
			quotient = num * 10 / den;
			num = num * 10 % den;

			mit = record.find(PLL(quotient, num));

			if (mit != record.end()) {
				tmp = ret[ret.length() - 1];
				for (i = ret.length() - 1; i > mit->second; --i) {
					ret[i] = ret[i - 1];
				}
				ret[i] = '(';
				ret += tmp;
				ret += ')';
				break;
			} else {
				record.insert(std::pair<PLL, int> (PLL(quotient, num), ret.length()));
				ret += std::to_string(quotient);
			}
		}
		return ret;
	}
};

int main(int argc, char const *argv[])
{
	Solution sol;

	printf("%s\n", sol.fractionToDecimal(7, -12).c_str());
	
	return 0;
}
