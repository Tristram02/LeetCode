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
        uint32_t rev = 0;
        auto y = x;
        while (x)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        if (rev == y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};