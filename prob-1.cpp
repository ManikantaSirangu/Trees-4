//t-c: n
//s-c: h
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
    int max = -1;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return max;
    }
    void inorder(TreeNode* root, int& k)
    {
        if(root == NULL)
            return;

        inorder(root->left, k);
        if(--k == 0)
            max = root->val;

        inorder(root->right, k);
        return;
    }
};
