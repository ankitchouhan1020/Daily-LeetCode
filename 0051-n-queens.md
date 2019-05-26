---
tags: ["leetcode","backtracking"]
created: "26/05/2019, 17:27:45"
difficulty: "hard"
---

# [0051-n-queens](https://leetcode.com/problems/n-queens/)

## Problem
<div><p>The <em>n</em>-queens puzzle is the problem of placing <em>n</em> queens on an <em>n</em>×<em>n</em> chessboard such that no two queens attack each other.</p><br><br><p><img alt="" src="https://assets.leetcode.com/uploads/2018/10/12/8-queens.png" style="width: 258px; height: 276px;"></p><br><br><p>Given an integer <em>n</em>, return all distinct solutions to the <em>n</em>-queens puzzle.</p><br><br><p>Each solution contains a distinct board configuration of the <em>n</em>-queens' placement, where <code>'Q'</code> and <code>'.'</code> both indicate a queen and an empty space respectively.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> 4<br><strong>Output:</strong> [<br> [".Q..",  // Solution 1<br>  "...Q",<br>  "Q...",<br>  "..Q."],<br><br> ["..Q.",  // Solution 2<br>  "Q...",<br>  "...Q",<br>  ".Q.."]<br>]<br><strong>Explanation:</strong> There exist two distinct solutions to the 4-queens puzzle as shown above.<br></pre><br></div>

## Solution

c++
```c++

class Solution {
    vector<vector<string>> powerset;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solveQueen(board,0,n);
        return powerset;
    }
    
    void solveQueen(vector<string>& board,int row,int n){
        if(row==n) return;
        for(int i=0;i<n;i++){
            if(safeQueen(board,row,i,n)){
                board[row][i] = 'Q';
                if(row==n-1){
                    powerset.push_back(board);
                }
                solveQueen(board,row+1,n);
                board[row][i] = '.';
            }            
        }
    }
    
    
    bool safeQueen(vector<string>& board,int sr,int sc,int n){
        for(int j=0;j<n;j++){
            if(j!=sc && board[sr][j] == 'Q') return false;
        }
        
        for(int i=0;i<n;i++){
            if(i!=sr && board[i][sc] == 'Q') return false;
        }
        
        for(int i=1;i<n;i++){
            static int dirr[] = {-1,-1,1,1};
            static int dirc[] = {-1,1,-1,1};
            for(int k=0;k<4;k++){
                int nr = sr + i * dirr[k];
                int nc = sc + i * dirc[k];
                if(nr>=n || nr<0 || nc>=n || nc<0) continue;
                if(board[nr][nc] == 'Q') return false;
            }
        }
        return true;
    }
};
​
```
