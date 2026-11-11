// Link to problem
// https://leetcode.com/problems/climbing-stairs

#include <vector>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }

        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++)
        {
            int result = first + second;
            first = second;
            second = result;
        }
        return second;
    }
};