// Link to problem
// https://leetcode.com/problems/integer-to-roman

#include <vector>
#include <string>

class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::vector<int> number = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::vector<std::string> symbol = {"M", "CM", "D", "CD", "C", 
                                    "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        std::string result = "";
        int i = 0;
        while (num)
        {
            if (num >= number[i])
            {
                result += symbol[i];
                num -= number[i];
            }
            else
            {
                i++;
            }
        }

        return result;
    }
};