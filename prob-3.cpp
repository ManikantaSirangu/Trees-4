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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp;
        vector<TreeNode*> pathq;
        int fp = 0, fq = 0;
        helper(root, p, q, pathp, pathq, fp, fq);
        int i;
        for(TreeNode* ch: pathp){
            cout<<ch->val<<" ";
        }
        cout<<endl;
        for(TreeNode* ch: pathq){
            cout<<ch->val<<" ";
        }
        cout<<pathp.size()<< " " << pathq.size();

        for(i = 0; i < min(pathp.size(),pathq.size()); i++) {
            if(pathp[i] != pathq[i]) {
                return pathp[i-1];
            }
        }
        return pathp[i-1];

    }
    void helper(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& pathp, 
                        vector<TreeNode*>& pathq, int& fp, int& fq) {
        if(root == NULL) return;

        if(fp != 1)
        {
            pathp.push_back(root);
            if(root == p)
                fp = 1;
        }
        if(fq != 1)
        {
            pathq.push_back(root);
            if(root == q)
                fq = 1;
        }
        helper(root->left, p, q, pathp, pathq, fp, fq);
        helper(root->right, p, q, pathp, pathq, fp, fq);
        if(fp != 1 && pathp.size() > 1)
            pathp.pop_back();
        if(fq != 1 && pathq.size() > 1)
            pathq.pop_back();
    }

};
