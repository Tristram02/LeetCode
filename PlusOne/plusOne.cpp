// Link to problem
// https://leetcode.com/problems/plus-one

#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        int last = digits.size() - 1;
        while(1)
        {
            if (last < 0)
            {
                digits.insert(digits.begin(), 1);
                return digits;
            }
            if (digits[last] == 9)
            {
                digits[last] = 0;
                last--;
            }
            else
            {
                digits[last]++;
                return digits;
            }
        }
        return digits;
    }

    std::vector<int> plusOneBetter(std::vector<int>& digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};