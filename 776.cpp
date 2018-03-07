/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBST(vector<int> &array)
    {
        
    }

    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        
        std::vector<int> whole;
        std::vector<int> small;
        std::vector<int> large;
        std::vector<TreeNode*> tree;
        vector<TreeNode*> result = {NULL, NULL};
        if(root == NULL) return result;
        whole.push_back(root->val);
        tree.push_back(root);
        int i = 0;
        TreeNode* temp;
        while(i < tree.size())
        {
			temp = tree[i];
			if(temp->left != NULL)
			{
				tree.push_back(temp->left);
				whole.push_back(temp->left->val);
			}        	
			if(temp->right != NULL)
			{
				tree.push_back(temp->right);
				whole.push_back(temp->right->val);
			} 
        	i++;
        }

        for(i = 0; i < tree.size(); i++)
        {
        	if(whole[i] > V) large.push_back(whole[i]);
        	else small.push_back(whole[i]);
        }

        

    }

};