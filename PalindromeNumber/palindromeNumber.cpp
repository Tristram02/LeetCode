// Link to problem
// https://leetcode.com/problems/palindrome-number/
//

#include <cstdint>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        if (x < 10)
        {
            return true;
        }
        if (x % 10 == 0)
        {
            return false;
        }

        uint32_t rev = 0;
        while (x > rev)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev == x or x == rev / 10;
    }
};