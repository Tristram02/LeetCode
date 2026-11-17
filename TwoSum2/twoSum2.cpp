// Link to problem
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

#include <vector>

class Solution
{
public:
    std::vector<int> twoSumBrute(std::vector<int>& numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }

                if (numbers[i] + numbers[j] == target)
                {
                    return {i + 1, j + 1};
                }
            }
        }

        return {0, 0};
    }

    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;
        int sum = numbers[i] + numbers[j];
        while(sum != target)
        {
            if (sum > target)
            {
                j--;
            }
            else if (sum < target)
            {
                i++;
            }
            sum = numbers[i] + numbers[j];
        }
        return {i + 1, j + 1};
    }
};