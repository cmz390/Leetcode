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
    int minDiffInBST(TreeNode* root) {
        
        
        std::vector<int> whole;
        std::vector<TreeNode*> tree;
        if(root == NULL) return result;
        whole.push_back(root->val);
        tree.push_back(root);
        int i = 0;
        int j = 0;
        int min = root->val;
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

        for(i = 0; i < whole.size(); i++)
        {
        	for(j = 0; j < whole.size(); j++)
        	{

        		if(abs(whole[i] - whole[j]) < min) min = abs(whole[i] - whole[j]);
        	}
        }


        return min;


    }
};