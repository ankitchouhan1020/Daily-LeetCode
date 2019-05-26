---
tags: ["leetcode","depth-first search","breadth-first search","union find"]
created: "26/05/2019, 16:48:56"
difficulty: "medium"
---

# [0200-number-of-islands](https://leetcode.com/problems/number-of-islands/)

## Problem
<div><p>Given a 2d grid map of <code>'1'</code>s (land) and <code>'0'</code>s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.</p><br><br><p><b>Example 1:</b></p><br><br><pre><strong>Input:</strong><br>11110<br>11010<br>11000<br>00000<br><br><strong>Output:</strong>&nbsp;1<br></pre><br><br><p><b>Example 2:</b></p><br><br><pre><strong>Input:</strong><br>11000<br>11000<br>00100<br>00011<br><br><strong>Output: </strong>3<br></pre></div>

## Solution

c++
```c++

class Solution {
    private:
    int rows,cols;
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,0));        
        int result = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    visited[i][j] = 1;
                    toVisit(grid,visited,i,j);
                    result++;                    
                }
            }
        }
        return result;
    }
    
    
    void toVisit(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        vector<int> rowMove = {-1,0,0,1};
        vector<int> colMove = {0,-1,1,0};
        for(int k=0;k<4;k++){
            if(isSafe(grid,visited,i+rowMove[k],j+colMove[k])){
                visited[i+rowMove[k]][j+colMove[k]]=1;
                toVisit(grid,visited,i+rowMove[k],j+colMove[k]);
            }
        }
        return;
    }
    
    bool isSafe(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        return (i>=0 && i<rows && j>=0 && j<cols && !visited[i][j] && grid[i][j]=='1');
    }
};
​
```
