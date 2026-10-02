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
 void createMapping(vector<int> &inorder,map<int,int>& nodeToIndex,int n){
      for(int i=0;i<n;i++){
          nodeToIndex[inorder[i]]=i;
      }
  }
  TreeNode* solve(vector<int> &inorder, vector<int> &preorder,int &index,int s,int e,int n,map<int,int>&nodeToIndex){
      //base case:index out of bounds or invalid range
      if(index>=n||s>e){
          return NULL;
      }
      // get current root value from preorder traversal
      int element=preorder[index++];
      TreeNode* root= new TreeNode(element);
      
      
      //finding index of this element in inorder traversal
      
      int position=nodeToIndex[element];
      
      //recursive call for left and right subtree
      root->left=solve(inorder,preorder,index,s,position-1,n,nodeToIndex);
      root->right=solve(inorder,preorder,index,position+1,e,n,nodeToIndex);
      
      return root;
      
      
  }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      //create mapping from inorder 
       map<int,int> nodeToIndex;
       int preOrderIndex=0;
       int n=inorder.size();
       createMapping(inorder,nodeToIndex,n);
       
       TreeNode* ans=solve(inorder,preorder,preOrderIndex,0,n-1,n,nodeToIndex);
       return ans;
       
    }
};