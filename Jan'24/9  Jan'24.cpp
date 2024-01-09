class Solution
{
private:
    bool helpme(TreeNode *r1, TreeNode *r2)
    {
        if (r1 == NULL and r2 == NULL)
            return true;
        if (r1 == NULL or r2 == NULL)
            return false;

        if (!r1->left and !r1->right and !r2->left and !r2->left)
        {
            if (r1->val != r2->val)
                return false;
            return true;
        }

        return helpme(r1->left, r2->left) and helpme(r1->right, r2->right);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        // dfs
        return helpme(root1, root2);
    }
};