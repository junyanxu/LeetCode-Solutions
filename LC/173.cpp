/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        s = stack<TreeNode*> ();
        while(root){
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* curr = s.top();
        s.pop();
        TreeNode* tmp = curr->right;
        while(tmp){
            s.push(tmp);
            tmp =tmp->left;
        }
        return curr->val;
    }
private:
    stack<TreeNode*> s;
};
