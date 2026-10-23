// Link to problem
// https://leetcode.com/problems/average-of-levels-in-binary-tree

#include <vector>
#include <queue>

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
    std::vector<double> averageOfLevels(TreeNode* root)
    {
        std::vector<double> result;
        std::queue<TreeNode*> q;
        q.push(root);

        while(not q.empty())
        {
            int levelSize = q.size();
            double levelSum = 0;

            for (int i = 0; i < levelSize; i++)
            {
                auto curr = q.front();
                q.pop();

                levelSum += curr->val;

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            result.push_back(levelSum / levelSize);
        }

        return result;
    }
};