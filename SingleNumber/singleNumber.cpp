// Link to problem
// https://leetcode.com/problems/single-number

#include <vector>

class Solution
{
public:
    int singleNumber(std::vector<int>& nums)
    {
        int result = 0;
        for (auto x : nums)
        {
            result ^= x;
        }
        return result;
    }
};