// Link to problem
// https://leetcode.com/problems/minimum-absolute-difference-in-bst

#include <algorithm>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int getMinimumDifference(TreeNode* root)
    {
        int min = __INT_MAX__;
        TreeNode* prev = nullptr;
        return minDiff(root, min, prev);
    }

    int minDiff(TreeNode* root, int& min, TreeNode*& prev)
    {
        if (not root)
        {
            return min;
        }

        minDiff(root->left, min, prev);

        if (prev not_eq nullptr)
        {
            int diff = root->val - prev->val;
            if (diff < min)
            {
                min = diff;
            }
        }

        prev = root;

        minDiff(root->right, min, prev);
        return min;
    }
};