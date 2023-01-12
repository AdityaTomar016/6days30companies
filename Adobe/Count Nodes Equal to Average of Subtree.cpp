class Solution {
public:
    int count=0;
    
    pair<int,int> solve(TreeNode* root){
        
        if(!root){
            return {0,0};
        }
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        int sum = left.first + right.first + root->val;
        int n = left.second + right.second + 1;
        
        if(sum/n == root->val)
        count ++;
        
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        
        solve(root);
        return count;
    }
};
