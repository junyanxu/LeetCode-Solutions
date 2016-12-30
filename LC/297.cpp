class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        traverse(root, s);
        return s;
    }

    void traverse(TreeNode* root, string &s){
        if(!root){
            s.append("null ");
        }
        else{
            s.append(to_string(root->val)+" ");
            traverse(root->left, s);
            traverse(root->right, s);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        istringstream is(data);
        string temp;
        while(getline(is, temp, ' ')){
            v.push_back(temp);
        }
        int i=0;
        return build(v, i);
    }

    TreeNode * build(vector<string> &v, int &i){
        if(v[i] == "null"){
            i++;
            return NULL;
        }
        else{
            TreeNode* root = new TreeNode(stoi(v[i]));
            i++;
            root->left = build(v, i);
            root->right = build(v, i);
            return root;
        }
    }
};
