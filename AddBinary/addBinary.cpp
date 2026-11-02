// Link to problem
// https://leetcode.com/problems/add-binary

#include <string>
#include <algorithm>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        std::string result = "";
        
        while(i >= 0 or j >= 0 or carry > 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                sum += b[j] - '0';
                j--;
            }
            
            carry = sum / 2;
            result.push_back(char(sum % 2) + '0');
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};