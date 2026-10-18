// Link to problem
// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int maxDepthSimplest(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }

    int maxDepth(TreeNode* root)
    {
        return maxDepthRec(root, 1);
    }

    int maxDepthRec(TreeNode* root, int depth)
    {
        if (!root)
        {
            return depth - 1;
        }

        auto a = maxDepthRec(root.left, depth + 1);
        auto b = maxDepthRec(root.right, depth + 1);
        
        return a > b ? a : b;
    }
};