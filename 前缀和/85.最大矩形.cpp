#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int add[210][210];
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0, i, j, x, y, tmp;
        for(i = 0; i < matrix.size(); i++)
            for(j = 0; j < matrix[0].size(); j++)
                add[i+1][j+1] = add[i+1][j]+add[i][j+1]-add[i][j]+matrix[i][j]-'0';
        for(i = 1; i <= matrix.size() ; i++){
            for(j = 1; j <= matrix[0].size(); j++){
                for(x = i; x <= matrix.size() ; x++){
                    for(y = j; y <= matrix[0].size(); y++){
                        tmp = add[x][y]-add[x][j-1]-add[i-1][y]+add[i-1][j-1];
                        if(tmp == (x-i+1)*(y-j+1))
                            ans = max(ans, tmp);
                        else break;
                    }
                }
            }
        }
        return ans;
    }
};