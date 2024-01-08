class Solution
{
private:
    void helpme(TreeNode *root, int low, int high, int &sum)
    {
        if (root == NULL)
            return;
        if (root->val >= low and root->val <= high)
            sum += root->val;
        helpme(root->left, low, high, sum);
        helpme(root->right, low, high, sum);
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        // recrursion:
        int sum = 0;
        helpme(root, low, high, sum);
        return sum;
    }
};