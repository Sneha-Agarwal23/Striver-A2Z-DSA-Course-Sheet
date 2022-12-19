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
    int countNodes(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        int l = 1, r = 1;
        TreeNode* p = root;
        TreeNode* q = root;
        while(p->left != NULL)
        {
            l++;
            p = p->left;
        }
        while(q->right != NULL)
        {
            r++;
            q = q->right;
        }
        if(l == r)
            return pow(2, l) -1;
        return countNodes(root->left) + countNodes(root->right) + 1;
        
    }
};