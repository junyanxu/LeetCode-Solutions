#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>

struct TreeNode{
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    int val;
    TreeNode* left;
    TreeNode* right;
};

using namespace std;

TreeNode* createBST(vector<int> nums, int l, int r){
    if(l <= r){
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createBST(nums, l, mid-1);
        root->right = createBST(nums, mid+1, r);
        return root;
    }
    else{
        return NULL;
    }
}

void LevelOrderTraversal(TreeNode* root){
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    int curr = 0;
    while (!q.empty()) {
        pair<TreeNode*, int> temp = q.front();
        q.pop();
        if(temp.second != curr){
            cout << endl;
            curr = temp.second;
        }
        cout << temp.first->val << " ";
        if(temp.first->left){
            q.push(make_pair(temp.first->left, temp.second+1));
        }
        if(temp.first->right){
            q.push(make_pair(temp.first->right, temp.second+1));
        }
    }
    cout << endl;
}




int main(){
    vector<int> tree = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    TreeNode* t = createBST(tree, 0, (int)tree.size()-1);
    LevelOrderTraversal(t);
}
