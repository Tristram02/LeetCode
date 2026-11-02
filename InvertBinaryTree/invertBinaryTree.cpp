// Link to problem
// https://leetcode.com/problems/invert-binary-tree

#include <utility>

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
    TreeNode* invertTreeSimpler(TreeNode* root)
    {
        if (not root)
        {
            return nullptr;
        }

        std::swap(root->left, root->right);

        invertTreeSimpler(root->left);
        invertTreeSimpler(root->right);

        return root;
    }

    TreeNode* invertTree(TreeNode* root)
    {
        invert(root);
        return root;
    }

    void invert(TreeNode* root)
    {
        if (root and (root->left or root->right))
        {
            auto tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            invert(root->left);
            invert(root->right);
        }
        return;
    }
};