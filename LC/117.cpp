class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root){return;}
        TreeLinkNode *p = root->next;
        TreeLinkNode *temp = NULL;
        while(p){
            if(p->left){
                temp = p->left;
                break;
            }
            if(p->right){
                temp = p->right;
                break;
            }
            p = p->next;
        }
        if(root->right){
            root->right->next = temp;
        }
        if(root->left){
            root->left->next = root->right? root->right: temp;
        }
        connect(root->right);
        connect(root->left);

    }
};
