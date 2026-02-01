// Link to problem
// https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class RandomizedSet {
public:
    std::unordered_map<int, int> indexs;
    std::vector<int> items;

    RandomizedSet() {
        std::srand(std::time({}));
        indexs = std::unordered_map<int, int>();
        items = std::vector<int>();
    }
    
    bool insert(int val) {
        if (auto i = indexs.find(val); i == indexs.cend())
        {
            items.push_back(val);
            indexs[val] = items.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (auto i = indexs.find(val); i != indexs.cend())
        {
            int n = items.size();
            items[indexs[val]] = items[n - 1];
            indexs[items[n - 1]] = indexs[val];
            items.pop_back();
            indexs.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        const int random_value = std::rand() % (items.size());
        return items[random_value];
    }
};

int main()
{
    std::vector<std::string> operations = {"RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"};
    std::vector<std::vector<int>> input = {{}, {1}, {2}, {2}, {}, {1}, {2}, {}};

    RandomizedSet rs;
    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i] == "RandomizedSet")
        {
            rs = RandomizedSet();
            std::cout << "null" << std::endl;
        }
        else if (operations[i] == "insert")
        {
            for (auto& val: input[i])
            {
                std::cout << rs.insert(val) << std::endl;
            }
        }
        else if (operations[i] == "remove")
        {
            for (auto& val: input[i])
            {
                std::cout << rs.remove(val) << std::endl;
            }
        }
        else if (operations[i] == "getRandom")
        {
            std::cout << rs.getRandom() << std::endl;
        }
        else
        {
            std::cout << "unknown operation" << std::endl;
        }
    }

    return 0;
}