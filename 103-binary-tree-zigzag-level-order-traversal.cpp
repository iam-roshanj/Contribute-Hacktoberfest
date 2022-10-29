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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>vt;
        queue<TreeNode*>q;
        q.push(root);
        int f=1;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>temp;
          if(root==NULL)
              return vt;
            while(sz--)
            {
              TreeNode* var = q.front();
                
                temp.push_back(var->val);
                if(var->right)
                    q.push(var->right);
                if(var->left)
                    q.push(var->left);
                q.pop();
            }
            if(f>0)
                reverse(temp.begin(),temp.end());
            int k=0;
                vt.push_back(temp);
          
            f=f*-1;
        }
        return vt;
    }
};
