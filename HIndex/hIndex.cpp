#include <iostream>
#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        auto buckets = std::vector<int>(1001, 0);
        auto n = citations.size();
        auto maxCitation = 0;
        for (int i = 0; i < n; i++)
        {
            buckets[citations[i]]++;
            if (citations[i] > maxCitation)
            {
                maxCitation = citations[i];
            }
        }
        auto sum = 0;
        for (int i = maxCitation; i >= 0; i--)
        {
            if (i < 0)
            {
                break;
            }
            sum += buckets[i];
            if (sum >= i)
            {
                return i;
            }
            else if (sum == n)
            {
                if (i >= n)
                {
                    return n;
                }
                return i;
            }
        }
        
        return 0;
    }
};

int main()
{
    auto s = Solution();
    auto citations = std::vector<int>{3,0,6,1,5};
    std::cout << s.hIndex(citations) << std::endl;
    return 0;
}