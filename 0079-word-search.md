---
tags: ["leetcode","array","backtracking"]
created: "31/05/2019, 22:30:10"
difficulty: "medium"
---

# [0079-word-search](https://leetcode.com/problems/word-search/)

## Problem
<div><p>Given a 2D board and a word, find if the word exists in the grid.</p><br><br><p>The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.</p><br><br><p><strong>Example:</strong></p><br><br><pre>board =<br>[<br>  ['A','B','C','E'],<br>  ['S','F','C','S'],<br>  ['A','D','E','E']<br>]<br><br>Given word = "<strong>ABCCED</strong>", return <strong>true</strong>.<br>Given word = "<strong>SEE</strong>", return <strong>true</strong>.<br>Given word = "<strong>ABCB</strong>", return <strong>false</strong>.<br></pre><br></div>

## Solution

c++
```c++
​
class Solution {
public:
bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        int row = board.size();
        int col = board[0].size();
        if(row*col < word.size()) return false;
        vector<vector<int>> visited(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = 1;
                    if(boggle(board,visited,word,1,i,j)) return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
    
bool boggle(vector<vector<char>>& board,vector<vector<int>>& visited ,string word, int start, int sr, int sc){
        int row = board.size();
        int col = board[0].size();
        if(start == word.size()) return true;
        if(sr<0 || sr>row-1 || sc<0 || sc>col-1) return false;
        //if(visited[sr][sc] == 1) return false;
        
        int nrow[] = {-1,0,0,1};
        int ncol[] = {0,-1,1,0};
        
        for(int k=0;k<4;k++){
            int x = sr + nrow[k];
            int y = sc + ncol[k];
            if(x<0 || x>row-1 || y<0 || y>col-1) continue;
            if(word[start]==board[x][y] && visited[x][y]==0){
                visited[x][y] = 1;
                if(boggle(board,visited,word,start+1,x,y)) return true;
​
```
