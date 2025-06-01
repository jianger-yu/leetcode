#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void bfs(int a, int b, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({a,b});
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            grid[x][y] = '0';
            q.pop();
            for(int i = 0; i < 4; i++){
                int ex = x + dx[i], ey = y + dy[i];
                if(ex >= 0 && ex < grid.size() && ey >= 0 && ey < grid[0].size() 
                    &&  grid[ex][ey] == '1'){
                    grid[ex][ey] = '0';
                    q.push({ex,ey});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    bfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};