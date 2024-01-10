class Solution
{
    TreeNode *rootStart = NULL;

private:
    void find_start(TreeNode *root, int start)
    {
        if (root == NULL)
            return;
        if (root->val == start)
            rootStart = root;
        find_start(root->left, start);
        find_start(root->right, start);
    }

    void find_father(TreeNode *root, int start, unordered_map<TreeNode *, TreeNode *> &mp)
    {
        if (root == NULL)
            return;
        if (root->left)
            mp[root->left] = root;
        if (root->right)
            mp[root->right] = root;

        find_father(root->left, start, mp);
        find_father(root->right, start, mp);
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        // attaching to father:
        unordered_map<TreeNode *, TreeNode *> mp;
        find_father(root, start, mp);

        // find starting node:
        find_start(root, start);
        // cout<<"rootStart->val"<<" "<<rootStart->val<<endl;

        // calcuating Time:
        int time = 0;
        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> q;

        q.push(rootStart);
        // vis[rootStart] = true;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = q.front();
                q.pop();
                vis[top] = true;

                if (top->left != NULL and !vis[top->left])
                    q.push(top->left);
                vis[top->left] = true;
                if (top->right != NULL and !vis[top->right])
                    q.push(top->right);
                vis[top->right] = true;

                if (mp[top] and !vis[mp[top]])
                    q.push(mp[top]);
                vis[mp[top]] = true;
            }
            time += 1;
        }

        return time - 1;
    }
};