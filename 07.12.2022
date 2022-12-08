1. https://leetcode.com/problems/range-sum-of-bst/description/
Solution --
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void preorder(TreeNode* root, int low, int high, int &ans){
        if(root == NULL) return;

        if(root -> val <= high and root -> val >= low){
            ans += root -> val;
        }
        preorder(root->left, low, high, ans);
        preorder(root->right, low, high, ans);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        preorder(root, low, high, ans);
        return ans;
    }
};
