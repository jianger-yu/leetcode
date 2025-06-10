#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans;
    void dfs(TreeNode* root, int u){
        if(root -> left != NULL) dfs(root->left,u+1);
        if(root -> right != NULL) dfs(root->right,u+1);
        if(root -> left == NULL && root -> right == NULL)
            ans = max(ans,u);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return ans;
        dfs(root,1);
        return ans;
    }
};