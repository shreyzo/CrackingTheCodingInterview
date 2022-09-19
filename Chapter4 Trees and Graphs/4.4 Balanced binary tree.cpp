//Solved on LeetCode
//https://leetcode.com/problems/balanced-binary-tree/
 
 
/* O(N^2) */ 
     int height(TreeNode* node) {
         if(node==NULL) return 0;
         return 1+max(height(node->left),height(node->right));
     }
    
     bool isBalanced(TreeNode* root) {
         if(root==NULL) return true;
         if(root->left==NULL && root->right==NULL) return true;
        
         if(abs(height(root->left)-height(root->right))>1) return false;
        
         return isBalanced(root->left) && isBalanced(root->right);
        
     }
     
/* O(N) */
    int depth(TreeNode* node) {
        if(node==NULL) return 0;
        
        int leftDepth = depth(node->left);
        if(leftDepth==-1) return -1;
        
        int rightDepth = depth(node->right);
        if(rightDepth==-1) return -1;
        
        if(abs(leftDepth-rightDepth)>1) return -1;
        return 1+max(leftDepth, rightDepth);
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL) return true;
        return depth(root)!= -1;
        
    }
