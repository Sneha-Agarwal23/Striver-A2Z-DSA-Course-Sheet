vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        TreeNode* temp;
        while(root != NULL)
        {
            if(root->left != NULL)
            {
                temp = root->left;
                while(temp->right != NULL)
                {
                    temp = temp->right;
                }
                temp->right = root;
                temp = root->left;
                root->left = NULL;
                root = temp;
            }
            else
            {
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
