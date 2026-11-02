// Link to problem
// https://leetcode.com/problems/path-sum

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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (not root)
        {
            return false;
        }

        if (not root->left and not root->right)
        {
            return root->val == targetSum;
        }

        targetSum -= root->val;

        return hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum);
    }

};