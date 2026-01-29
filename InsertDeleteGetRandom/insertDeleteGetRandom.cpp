    // Link to problem
// https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

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
        if (auto i = indexs.find(val); i != indexs.cend())
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
            items[indexs[val]] = items[items.size() - 1];
            items.pop_back();
            indexs.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        const int random_value = std::rand() % (items.size() + 1);
        return items[random_value];
    }
};

int main()
{
    return 0;
}