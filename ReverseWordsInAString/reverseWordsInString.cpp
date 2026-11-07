// Link to problem
// https://leetcode.com/problems/reverse-words-in-a-string

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        auto words = std::vector<std::string>();
        char prev = ' ';
        std::string word = "";
        for (auto x : s)
        {
            if (x == ' ' and prev not_eq ' ')
            {
                words.push_back(word);
                word = "";
            }
            else if (x not_eq ' ')
            {
                word += x;
            }
            prev = x;
        }

        if (prev not_eq ' ')
        {
            words.push_back(word);
        }

        std::string result = "";
        for (int i = words.size() - 1; i >= 0; i--)
        {
            result += words[i];
            if (i > 0)
            {
                result += " ";
            }
        }

        return result;
    }

    std::string reverseWordsIsStringStream(std::string s)
    {
        std::istringstream iss(s);
        std::string word;
        std::vector<std::string> words;

        while (iss >> word)
        {
            words.push_back(word);
        }

        std::string result = "";
        for (int i = words.size() - 1; i >= 0; i--)
        {
            result += words[i];
            if (i > 0)
            {
                result += " ";
            }
        }

        return result;
    }

    std::string reverseWordsWithTwoPointers(std::string s)
    {
        std::reverse(s.begin(), s.end());

        int n = s.size();
        int index = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] not_eq ' ')
            {
                if (index not_eq 0)
                {
                    s[index] = ' ';
                    index++;
                }

                int end = i;
                while (end < n and s[end] not_eq ' ')
                {
                    s[index] = s[end];
                    index++, end++;
                }

                std::reverse(s.begin() + index - (end - i), s.begin() + index);

                i = end;
            }
        }

        s.resize(index);
        return s;
    }
};