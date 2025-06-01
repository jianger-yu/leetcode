#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    void bfs(pair<int,int> srt, char c, vector<vector<char>>& board){
        if(board[srt.first][srt.second] != 'O')
            return;
        queue<pair<int,int>> q;
        if(board[srt.first][srt.second] == 'O'){
            board[srt.first][srt.second] = c;
            q.push(srt); 
        }
        while(q.size()){
            pair<int, int> t = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int x = t.first + dx[i], y = t.second + dy[i];
                if(x>=0 && y>=0 && x<board.size() && y<board[0].size() &&
                   board[x][y] == 'O'
                ){
                    q.push({x,y});
                    board[x][y] = c;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++)
            bfs({i,0}, '.', board), bfs({i,board[0].size()-1},'.',board);    
        for(int i = 0; i < board[0].size(); i++)
            bfs({0,i}, '.', board), bfs({board.size()-1,i},'.',board);    
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                bfs({i,j},'X',board);
         for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)    
                if(board[i][j] == '.') board[i][j] = 'O';
    }
};