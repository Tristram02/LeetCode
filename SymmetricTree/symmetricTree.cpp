// Link to problem
// https://leetcode.com/problems/symmetric-tree

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (not root)
        {
            return true;
        }

        return symmetric(root->left, root->right);
    }

    bool symmetric(TreeNode* p, TreeNode* q)
    {
        if (not p and not q)
        {
            return true;
        }

        if (not p or not q)
        {
            return false;
        }

        if (p->val not_eq q->val)
        {
            return false;
        }

        return symmetric(p->left, q->right) and symmetric(p->right, q->left);
    }
};