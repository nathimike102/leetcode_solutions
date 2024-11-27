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
    void preorder(TreeNode* node, string &hash){
        if(node == NULL){
            hash += 'N';
            return;
        }
        hash += "," + to_string(node->val);
        preorder(node->left, hash);
        preorder(node->right, hash);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str1, str2;
        preorder(root, str1);
        preorder(subRoot, str2);
        return str1.find(str2) != string::npos;
    }
};