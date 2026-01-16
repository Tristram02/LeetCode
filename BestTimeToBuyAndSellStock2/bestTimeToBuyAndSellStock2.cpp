// Link to problem
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
#include <vector>

class Solution {
public:
    int max(int a, int b, int c, int d)
    {
        if (a >= b && a >= c && a >= d) return a;
        if (b >= a && b >= c && b >= d) return b;
        if (c >= b && c >= a && c >= d) return c;
        return d;
    }

    int maxProfit(std::vector<int>& prices)
    {
        auto n = prices.size();
        if (n < 2)
        {
            return 0;
        }
        auto profit = std::vector<std::vector<int>>();

        for (int i = 0; i < n; i++)
        {
            profit.push_back(std::vector<int>());
            for (int j = i + 1; j < n; j++)
            {
                if (i == 0)
                {
                    if (j > 1 and profit[i][j-2] >= prices[j] - prices[i])
                    {
                        profit[i].push_back(profit[i][j-2]);
                    }
                    else
                    {
                        profit[i].push_back(prices[j] - prices[i]);
                    }
                }
                else
                {
                    profit[i].push_back(max(prices[j] - prices[i], 
                                        profit[i-1][0] + (prices[j] - prices[i]),
                                        profit[i-1][0],
                                        j > i + 1 ? profit[i][j-(2+i)] : prices[j] - prices[i]));
                }
            }
        }

        return profit[n-2][0] < 0 ? 0 : profit[n-2][0];
    }

    int maxProfit_v2(std::vector<int>& prices)
    {
        auto n = prices.size();
        auto max = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] - prices[i - 1] >= 0)
            {
                max += (prices[i] - prices[i - 1]);
            }
        }

        return max;
    }
};

int main()
{
    auto s = Solution();
    auto prices = std::vector<int>{7,1,5,3,6,4};
    auto res = s.maxProfit_v2(prices);
    
    std::cout << res << std::endl;

    return 0;
}