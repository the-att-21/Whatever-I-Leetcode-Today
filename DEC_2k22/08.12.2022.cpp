100 Leetcode Questions COMPLETED!!!!


1. https://leetcode.com/problems/leaf-similar-trees/
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
    vector<int> leaf1;
    vector<int> leaf2;

    void pre1(TreeNode* root1, vector<int> &leaf1){
        if(root1 == NULL) return;

        if(root1 -> left == NULL and root1 -> right == NULL){
            leaf1.push_back(root1 -> val);
        }
        pre1(root1 -> left, leaf1);
        pre1(root1 -> right, leaf1);
    }

    void pre2(TreeNode* root2, vector<int> &leaf2){
        if(root2 == NULL) return;

        if(root2 -> left == NULL and root2 -> right == NULL){
            leaf2.push_back(root2 -> val);
        }
        pre2(root2 -> left, leaf2);
        pre2(root2 -> right, leaf2);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        pre1(root1, leaf1);
        pre1(root2, leaf2);

        int l1 = leaf1.size();
        int l2 = leaf2.size();

        if(l1!=l2) return 0;

        for(int i = 0; i < l1; i++){
            if(leaf1[i] != leaf2[i]) return 0;
        }

        return 1;
    }
};

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

