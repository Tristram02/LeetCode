// Link to problem
// https://leetcode.com/problems/same-tree

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
    bool isSameTreeSimpler(TreeNode* p, TreeNode* q)
    {
        if (!p and !q)
        {
            return true;
        }
        
        if (!p or !q)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }

    bool isSameTree(TreeNode* p. TreeNode* q)
    {
        if (!p and !q)
        {
            return true;
        }
        else if(p and q)
        {
            if (p->val not_eq q->val)
            {
                return false;
            }
            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        }
        else
        {
            return false;
        }
    }
};