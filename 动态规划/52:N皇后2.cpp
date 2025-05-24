#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int path[12],N,ans;
    bool st[12];
    void dfs(int u){
        if(u == N){
            ans ++;
            return;
        }
        for(int i = 1;i <= N;i++){
            if(!st[i]){
                int a,b,key;
                key = 1;
                for(int j = 0; j < u; j++){
                    a = u - j;
                    b = i - path[j];
                    if(abs(a)==abs(b)) {
                        key = 0;
                        break;
                    }
                }
                if(key == 0) continue;
                st[i] = true;
                path[u] = i;
                dfs(u+1);
                st[i] = false;
            }
        }
    }
    int totalNQueens(int n) {
        N = n;
        dfs(0);
        return ans;
    }
};