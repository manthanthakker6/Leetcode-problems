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
 //first brute forcr solution
 /*
class Solution {
private:
int height(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}    
public:
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==NULL){
        return 0;
       }
       int op1=diameterOfBinaryTree(root->left);
       int op2=diameterOfBinaryTree(root->right);
       int op3=height(root->left)+height(root->right);
       int ans= max(op1,max(op2,op3));

       return ans;

    }
}; */
class Solution {
public:
    // returns pair<diameter, height>
    pair<int, int> diameterHelper(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        pair<int, int> left = diameterHelper(root->left);
        pair<int, int> right = diameterHelper(root->right);

        int op1 = left.first;                       // diameter in left subtree
        int op2 = right.first;                      // diameter in right subtree
        int op3 = left.second + right.second;       // path passing through root

        int currentDiameter = max({op1, op2, op3});
        int currentHeight = 1 + max(left.second, right.second);

        return {currentDiameter, currentHeight};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameterHelper(root).first;
    }
};