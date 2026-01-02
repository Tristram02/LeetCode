#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 1;
        }

        int number = nums[0];
        int occ = 1;
        int k = nums.size();
        int p = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == number)
            {
                occ++;
            }
            else
            {
                number = nums[i];
                occ = 1;
            }

            if (occ >= 3)
            {
                p++;
            }

            nums[i - p] = nums[i];
        }

        return k - p;
    }
};

int main()
{
    auto S = Solution();

    auto nums = std::vector<int>{1,1,1,1,2,2,2,3,3,4,5,5,5};
    auto k = S.removeDuplicates(nums);
    std::cout << k << ", nums = [";
    for (int i = 0; i < k; i++)
    {
        std::cout << nums[i] << ",";
    }
    std::cout << "]" << std::endl;

    return 0;
}