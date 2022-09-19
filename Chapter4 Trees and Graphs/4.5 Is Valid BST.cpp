//Solved on Leetcode
//https://leetcode.com/problems/validate-binary-search-tree/
bool isValidBSTHelper(TreeNode* node, long lower, long upper) {
        
        if(node==NULL) return true;
        //cout<<node->val<<" "<<lower<<" "<<upper<<endl;
        bool res=true;
        res&= isValidBSTHelper(node->left, lower, node->val);
        res&= isValidBSTHelper(node->right, node->val, upper);
        
        if(node->val<=lower || node->val>=upper) res=false;
        return res;
        
    }
    
    
bool isValidBST(TreeNode* root) {
   return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}
