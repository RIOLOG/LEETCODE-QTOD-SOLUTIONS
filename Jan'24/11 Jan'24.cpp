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
private:
    //     int helpme(TreeNode* root, int maxi, int mini)
    //     {
    //         if (root == NULL)   return abs(maxi- mini);

    //         maxi = max(maxi, root->val);
    //         mini = min(mini, root->val);

    //         int left = helpme(root->left, maxi, mini);
    //         int right = helpme(root->right, maxi, mini);

    //         return max(left, right);
    //     }

    void helpme(TreeNode *root, int maxi, int mini, int &ans)
    {
        if (root == NULL)
            return;
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        ans = max(ans, (maxi - mini));

        helpme(root->left, maxi, mini, ans);
        helpme(root->right, maxi, mini, ans);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        // if (root == NULL)   return 0;
        // return helpme(root, root->val, root->val);

        if (root == NULL)
            return 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int ans = 0;

        helpme(root, maxi, mini, ans);
        return ans;
    }
};