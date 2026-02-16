// Link to problem
// https://leetcode.com/problems/valid-parentheses/
//

#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        auto parentheses = std::stack<char>{};

        for (auto c : s)
        {
            if (parentheses.empty() and 
                (c == ']' || c == '}' || c == ')'))
            {
                return false;
            }
            
            if (c == ']' && parentheses.top() == '[')
            {
                parentheses.pop();
                continue;
            }

            if (c == '}' && parentheses.top() == '{')
            {
                parentheses.pop();
                continue;
            }
            if (c == ')' && parentheses.top() == '(')
            {
                parentheses.pop();
                continue;
            }

            parentheses.push(c);
        }

        if (!parentheses.empty())
        {
            return false;
        }
        return true;
    }
};