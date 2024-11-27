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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int level = 1, res = 1, max_sum = root->val, curr_sum = 0, size;
        while(!Q.empty()){
            size = Q.size();
            while(size--){
                auto node = Q.front();
                Q.pop();
                curr_sum += node->val;
                if(node->left){
                    Q.push(node->left);
                }
                if(node->right){
                    Q.push(node->right);
                }
            }
            if(curr_sum > max_sum){
                max_sum = curr_sum;
                res = level;
            }
            level += 1;
            curr_sum = 0;
        }
        return res;
    }
};