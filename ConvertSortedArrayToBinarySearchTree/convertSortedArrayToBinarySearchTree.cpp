// Link to problem
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

#include <vector>
#include <span>

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
    TreeNode* sortedArrayToBST(std::span<int> nums) 
    {
        if (nums.empty())
        {
            return nullptr;
        }

        auto center = nums.size() / 2;

        auto node = new TreeNode(nums[center]);
        node->left = sortedArrayToBST(nums.first(center));
        node->right = sortedArrayToBST(nums.subspan(center + 1));

        return node;
    }
};