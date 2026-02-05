// Link to problem
// https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150
//

#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) 
    {
        auto result = nums[0] == 0 ? 1 : nums[0];
        auto zero = nums[0] == 0 ? true : false;
        auto isOnlyZero = true;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == 0 and !zero)
            {
                zero = true;
            }
            else
            {
                result *= nums[i];
            }
        }

        auto answer = std::vector<int>{};
        for (auto& n: nums)
        {
            if (n != 0)
            {
                if (zero)
                {
                    answer.push_back(0);
                }
                else
                {
                    answer.push_back(result / n);
                }
            }
            else
            {
                answer.push_back(result);
            }
        }

        return answer;
    }
};

int main()
{
    auto nums = std::vector<int>{2,3,0,0};
    auto s = Solution();
    auto answer = s.productExceptSelf(nums);

    for (auto& n: answer)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}