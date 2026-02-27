// Link to problem
// https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>

class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1)
        {
            return true;
        }
        auto newN = n;
        int i = 0;
        do
        {
            if (i > 100)
            {
                return false;
            }

            n = newN;
            newN = 0;
            while (n > 0)
            {
                newN += ((n % 10) * (n % 10));
                n /= 10;
            }
            i++;
        } while(newN != 1);

        return true;
    }
};

int main()
{
    auto s = Solution();
    if (s.isHappy(19))
    {
        std::cout << "Happy" << std::endl;
    }
    else
    {
        std::cout << "Not Happy" << std::endl;
    }

    return 0;
}