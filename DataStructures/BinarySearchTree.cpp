using namespace std;

struct TreeNode{
  TreeNode(int x){
    val = x;
    left=NULL;
    right=NULL;
  }
  int val;
  TreeNode* left;
  TreeNode* right;
};

class BinarySearchTree{
public:
  BinarySearchTree(){
    root = NULL;
  }
  void insert(int x){
    if(!root)
      root = new TreeNode(x);
    else{
      TreeNode* curr = root;
      while(curr){

	if(x <= curr->val){
	  if(curr->left){
	    curr = curr->left;
	  }
	  else{
	    curr->left = new TreeNode(x);
	    break;
	  }
	}
	else{
	  if(curr->right){
	    curr = curr->right;
	  }
	  else{
	    curr->right = new TreeNode(x);
	    break;
	  }
	}
      }
    }
  }

  void levelOrderTraverse(){
    int lastlevel = 1;
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 1));

    while (!q.empty()) {
      pair<TreeNode* , int> temp = q.front();
      q.pop();
      if(temp.second!= lastlevel){
	cout << endl;
	lastlevel = temp.second;
      }
      cout << temp.first->val << " ";
      if(temp.first->left)
	q.push(make_pair(temp.first->left, temp.second+1));
      if(temp.first->right)
	q.push(make_pair(temp.first->right, temp.second+1));
    }
  }

  void remove(int key){

  }

  void findPredecessor(int key){

  }

private:
  TreeNode* root;
};
