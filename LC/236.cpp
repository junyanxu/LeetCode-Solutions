class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){return NULL;}
        else if(root == p|| root == q){
            return root;
        }
        else{
            TreeNode* l = lowestCommonAncestor(root->left, p, q);
            TreeNode* r = lowestCommonAncestor(root->right, p, q);
            if(l && r){return root;}
            else if(l){
                return l;
            }
            else if(r){
                return r;
            }
            else{
               return NULL;
            }
        }
    }
};
