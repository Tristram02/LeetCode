#include <iostream>
#include <vector>

class Solution
{
public:

    int jump(std::vector<int> nums, int index, int goal, int origin)
    {
        if (goal <= 0)
            return 1;

        if (index == origin)
            return -1;

        if (nums[index] == 0)
            return jump(nums, index + nums[index] - 1, goal - nums[index] + 1, origin);
        
        if (index < 0)
            return -1;
        auto x = nums[index];
        auto y = 0;
        auto result = -1;
        while(x--)
        {
            result = jump(nums, index + nums[index] - y, goal - nums[index] + y, index);
            if (result == 1)
            {
                return 1;
            }
            y++;
        }
        return result;
    }

    bool canJump(std::vector<int> nums)
    {
        auto n = nums.size();
        return 1 == jump(nums, 0, n-1, -1);
    }
};

int main()
{
    auto s = Solution();
    auto nums = std::vector<int>{2,2,0,0,4};
    if (s.canJump(nums))
    {
        std::cout << "You can!" << std::endl;
    }
    else
    {
        std::cout << "You cannot!" << std::endl;
    }
    return 0;
}