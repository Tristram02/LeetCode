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

    // Time complexity O(n)
    // Space complexity O(1)
    void rotate_v2(std::vector<int>& nums, int k)
    {
        auto size = nums.size();
        if (k == size)
        {
            return;
        }

        k %= size;
        auto part_1 = (size - k) / 2; 
        auto part_2 = size - k; 
        int j = size - k - 1;

        for (int i = 0; i < size; i++)
        {
            if (i < part_1)
            {
                auto tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j--;
            }
            if (i == (size - k - 1))
            {
                j = 1;
            }
            if (i >= part_2)
            {
                auto tmp = nums[i];
                nums[i] = nums[size - j];
                nums[size - j] = tmp;
                j++;
                if (i >= size - j)
                {
                    break;
                }
            }
        }

        for (int i = 0; i < size / 2; i++)
        {
            auto tmp = nums[i];
            nums[i] = nums[size - i - 1];
            nums[size - i - 1] = tmp;
        }
    }
};

int main()
{
    Solution s = Solution();
    auto nums = std::vector<int>{1,2,3,4,5,6,7};
    int k = 4;
    s.rotate_v2(nums, k);

    for (auto& x : nums)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}