// Link to problem
// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
#include <vector>

class Solution {
public:
    // Time complexity O(n)
    // Space complexity O(n)
    void rotate(std::vector<int>& nums, int k)
    {
        auto size = nums.size();
        if (k == size)
        {
            return;
        }
        while (k > size)
        {
            k = k - size;
        }
        auto temp_vec = std::vector<int>{};

        for (int i = 0; i < k; i++)
        {
            temp_vec.push_back(nums[size - k + i]);
        }
        for (int i = 0; i < size - k; i++)
        {
            temp_vec.push_back(nums[i]);
        }

        nums = temp_vec;
    }
};

int main()
{
    Solution s = Solution();
    auto nums = std::vector<int>{1,2,3,4,5,6,7};
    int k = 10;
    s.rotate(nums, k);

    for (auto& x : nums)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}