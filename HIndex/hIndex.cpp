#include <iostream>
#include <vector>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        auto buckets = std::vector<int>(1001, 0);
        auto n = citations.size();
        auto maxCitation = 0;
        auto hIndex = n;
        for (int i = 0; i < n; i++)
        {
            buckets[citations[i]]++;
            if (citations[i] > maxCitation)
            {
                maxCitation = citations[i];
            }
        }

        for (int i = 0; i <= maxCitation; i++)
        {
            if (hIndex > i)
            {
                if (buckets[i] == hIndex)
                {
                    hIndex = i;
                }
                else
                {
                    hIndex -= buckets[i];
                }
            }
            if (hIndex < i)
            {
                break;
            }
        }
        
        return hIndex;
    }
};

int main()
{
    auto s = Solution();
    auto citations = std::vector<int>{2,3,2};
    std::cout << s.hIndex(citations) << std::endl;
    return 0;
}