// Link to problem
// https://leetcode.com/problems/zigzag-conversion

#include <string>
#include <vector>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        std::string result;
        result.reserve(s.length());
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }

};