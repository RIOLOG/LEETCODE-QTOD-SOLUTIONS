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
class Solution
{
    int sum = 0;

private:
    void helpme(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);

        if (root->right == NULL and root->left == NULL)
        {
            string temp = "";
            for (int i = 0; i < ans.size(); i++)
            {
                temp += to_string(ans[i]);
            }

            sum += stoi(temp);
        }

        helpme(root->left, ans);
        helpme(root->right, ans);

        ans.pop_back();
    }

public:
    int sumNumbers(TreeNode *root)
    {
        vector<int> ans;
        helpme(root, ans);
        return sum;
    }
};