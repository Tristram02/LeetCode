// Link to problem
// https://leetcode.com/problems/number-of-1-bits

#include <bitset>

class Solution
{
public:
    int hammingWeight(int n)
    {
        std::bitset<32> a(n);
        return a.count();
    }

    int hammingWeight(int n)
    {
        int count  = 0;
        while (n > 0)
        {
            if (n%2)
            {
                count++;
            }
            n /= 2;
        }
        return count;
    }
};