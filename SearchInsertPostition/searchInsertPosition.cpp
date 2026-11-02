// Link to problem
// https://leetcode.com/problems/search-insert-position

#include <vector>

class Solution 
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        if (nums.empty())
        {
            return 0;
        }
        return search(nums, 0, nums.size() - 1, target);
    }

    int search(std::vector<int>& nums, int start, int end, int target)
    {
        if (start >= end)
        {
            if (target <= nums[start])
            {
                return start;
            }
            else
            {
                return start + 1;
            }
        }
        auto center = start + (end - start) / 2;
        if (target == nums[center])
        {
            return center;
        }
        else if (target < nums[center])
        {
            return search(nums, start, center - 1, target);
        }
        else
        {
            return search(nums, center + 1, end, target);
        }
    }
};