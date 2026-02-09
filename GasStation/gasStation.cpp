// Link to problem
// https://leetcode.com/problems/gas-station/?envType=study-plan-v2&envId=top-interview-150
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // Iteration - time exceeded
    int canCompleteCircuitIteration(vector<int>& gas, vector<int>& cost) {
        auto n = gas.size();
        auto result = std::vector<int>();
        auto lastIndex = 0;
        for (int i = 0, j = 0; i < n; i++, j++)
        {
            if (j == n)
            {
                j = 0;
            }
            auto diff = gas[j] - cost[j];
            auto res = diff + (i > 0 ? result[i - 1] : 0);
            if (res >= 0)
            {
                result.push_back(res);
            }
            else
            {
                result.clear();
                i = -1;
                j = ++lastIndex - 1;
                if (j == n) 
                {
                    return -1;
                }
            }
        }

        if (result[n - 1] < 0)
        {
            return -1;
        }
        return lastIndex;
    }

    int canComplete(vector<int>& gas, vector<int>& cost, int* start)
    {
        auto n = gas.size();
        if (*start == n)
        {
            return -1;
        }
        auto result = std::vector<int>();
        for (int i = 0; i < n; i++)
        {
            auto idx = (*start + i) % n;
            auto diff = gas[idx] - cost[idx];
            auto res = diff + (i > 0 ? result[i - 1] : 0);
            if (res >= 0)
            {
                result.push_back(res);
            }
            else
            {
                (*start)++;
                return canComplete(gas, cost, start);
            }
        }
        return result[n - 1];
    }

    // Recursion - space exceeded
    int canCompleteCircuitRecursion(vector<int>& gas, vector<int>& cost)
    {
        auto start = 0;
        auto result = canComplete(gas, cost, &start);
        if (result < 0)
        {
            return -1;
        }
        else
        {
            return start;
        }
        
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        auto n = gas.size();
        auto result = 0;
        auto currentGas = 0;
        auto lastIndex = 0;
        for (int i = 0; i < n; i++)
        {
            auto diff = gas[i] - cost[i];
            result += diff;
            currentGas += diff;
            if (currentGas < 0)
            {
                currentGas = 0;
                lastIndex = i + 1;
            }
        }

        if (result < 0)
        {
            return -1;
        }
        return lastIndex;
    }
};

int main()
{
    auto gas = vector<int>{1,2,3,4,5};
    auto cost = vector<int>{3,4,5,1,2};
    auto s = Solution();
    
    std::cout << s.canCompleteCircuit(gas, cost) << std::endl;
    return 0;
}