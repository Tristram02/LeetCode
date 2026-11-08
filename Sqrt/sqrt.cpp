// Link to problem
// https://leetcode.com/problems/sqrtx

#include <stdint.h>

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }

        uint32_t i = 1;
        while(i * i <= x)
        {
            i++;
        }
        return i - 1;
    }

    int mySqrtBT(int x) // Binary tree
    {
        if (x == 0)
        {
            return 0;
        }

        int left = 1;
        int right = x;
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mid <= x / mid)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};