// Link to problem
// https://leetcode.com/problems/candy

#include <vector>

class Solution
{
public:
    int candy(std::vector<int>& ratings)
    {
        int n = ratings.size();
        
        if (n < 2)
        {
            return 1;
        }

        std::vector<int> candies(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }
        int sum = 0;
        for (auto x : candies)
        {
            sum += x;
        }

        return sum;
    }

    int candy(std::vector<int>& ratings)
    {
        int n = ratings.size();
        
        if (n < 2)
        {
            return 1;
        }

        int totalCandies = 1;
        int up = 0;
        int down = 0;
        int peak = 0;

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                down = 0;
                up++;
                peak = up;
                totalCandies += (1 + up);
            }
            else if (ratings[i] == ratings[i - 1])
            {
                down = 0;
                up = 0;
                peak = 0;
                totalCandies += 1;
            }
            else
            {
                down++;
                up = 0;
                totalCandies += down + (down > peak ? 1 : 0);
            }
        }
        return totalCandies;
    }
};