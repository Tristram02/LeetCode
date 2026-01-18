#include <iostream>
#include <vector>

class Solution
{
public:

    int jump(std::vector<int> nums)
    {
        auto n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        auto prevFarthest = 0;
        auto farthest = nums[0];
        auto jumps = 1;
        if (farthest >= n - 1)
        {
            return jumps;
        }

        for (int i = 1; i <= farthest; i++)
        {
            if (i + nums[i] > farthest)
            {
                if (i > prevFarthest)
                {
                    prevFarthest = farthest;
                    jumps++;
                }
                farthest = i + nums[i];
            }

            if (farthest >= n - 1)
            {
                return jumps;
            }
        }
        
        return jumps;
    }
};

int main()
{
    auto s = Solution();
    auto nums = std::vector<int>{2,3,1,1,4};
    std::cout << s.jump(nums) << std::endl;
    return 0;
}