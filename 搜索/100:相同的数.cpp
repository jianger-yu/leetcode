#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool key = true;
    void dfs(TreeNode* p, TreeNode* q){
        if(!key) return;
        if(p == q && p == NULL) return;
        if(p == NULL || q == NULL){
            key = false;
            return;
        }
        if(p->val != q->val){
            key = false;
            return;
        }
        else{
            dfs(p->left, q->left);
            dfs(p->right, q->right);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p,q);
        return key;
    }
};