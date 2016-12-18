class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *leftMost = root;

        while(leftMost) {
            root = leftMost;
            while(root && !root->left && !root->right) root = root->next;
            if(!root) return;
            leftMost = root->left ? root->left : root->right;
            TreeLinkNode *cur = leftMost;

            while(root) {
                if(cur==root->left) {
                    if(root->right) {
                        cur->next = root->right;
                        cur = cur->next;
                    }
                    root = root->next;
                }
                else if(cur==root->right) {
                    root = root->next;
                }
                else {  // cur is the child of the previous node of root
                    if(!root->left && !root->right) {
                        root = root->next;
                        continue;
                    }
                    cur->next = root->left ? root->left : root->right;
                    cur = cur->next;
                }
            }
        }
    }
};
