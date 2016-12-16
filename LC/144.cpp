class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> x;
        traverse(root, x);
        return x;
    }

    void traverse(TreeNode* root, vector<int>& x){
        if(root != NULL){
            x.push_back(root->val);
            traverse(root->left, x);
            traverse(root->right, x);
        }
    }
};
