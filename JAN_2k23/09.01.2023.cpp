1. https://leetcode.com/problems/binary-tree-preorder-traversal/description/
Solution : 
//! ITERATIVE 
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(!root) return ans;
        s.push(root);

        while(!s.empty())
        {
            TreeNode* temp = s.top();
            ans.push_back(temp->val);
            s.pop();

            if(temp->right) { s.push(temp->right); }
            if(temp->left) { s.push(temp->left); }
        }

        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------

2. https://leetcode.com/problems/combination-sum-iii/description/
Solution :
class Solution
{
public:
    void solution(int index, int t, vector<int> &c, vector<int> &ds, vector<vector<int>> &ans, int k)
    {
        if (t == 0) // BASE CASE
        {
            if(ds.size() == k)
                ans.push_back(ds);
            return;
        }

        for (int i = index; i < c.size(); ++i)
        {
            if (i > index and c[i] == c[i - 1]) // FOR AVOIDING DUPLICATE SUBSEQUENCES
                continue;
            if(c[i] > t) break;   //FOR AVOIDING TLE!\U0001f612
            ds.push_back(c[i]); // PICKING
            solution(i + 1, t - c[i], c, ds, ans, k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int t)
    {
        vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ds;
        vector<vector<int>> ans;
        solution(0, t, c, ds, ans, k);
        return ans;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------

3. https://leetcode.com/problems/bulls-and-cows/description/
Solution : 
class Solution {
public:
    string getHint(string s, string g) {
        int x = 0, y = 0;
        map<char, int> f1;
        map<char, int> f2;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == g[i]) {
                x++;
            }
            else {
                f1[s[i]]++;
                f2[g[i]]++;
            }
        }

        for(auto &i : f2){
            if(f1.find(i.first) != f1.end()){
                y += min(i.second, f1[i.first]);
            }
        }

        return to_string(x)+'A'+to_string(y)+'B';
    }
};