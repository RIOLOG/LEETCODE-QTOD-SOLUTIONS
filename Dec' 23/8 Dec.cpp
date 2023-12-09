class Solution 
{
private:
    string s = "";
    void helpme(TreeNode* root)
    {
        if (root == NULL)   return ;
        s += to_string(root->val);
        if(root->left != NULL)
        {
            s += '(';
            helpme(root->left);
            s += ')';
        }
        
        if (root->left == NULL and root->right != NULL)
        {
            s += '(';
            s += ')';
        }
        
        if (root->right != NULL)
        {
            s += '(';
            helpme(root->right);
            s += ')';
        }
    }
    
public:
    string tree2str(TreeNode* root)
    {
        helpme(root);
        return s;
    }
};