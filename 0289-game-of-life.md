---
tags: ["leetcode","array"]
created: "04/06/2019, 18:40:47"
difficulty: "medium"
---

# [0289-game-of-life](https://leetcode.com/problems/game-of-life/)

## Problem
<div><p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">According to the </font></font><a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life" target="_blank"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Wikipedia's article</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">: "The </font></font><b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Game of Life</font></font></b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">, also known simply as </font></font><b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Life</font></font></b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."</font></font></p><br><br><p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Given a </font></font><i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">board</font></font></i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> with </font></font><i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">m</font></font></i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> by </font></font><i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">n</font></font></i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> cells, each cell has an initial state </font></font><i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">live</font></font></i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> (1) or </font></font><i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">dead</font></font></i><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> (0). Each cell interacts with its </font></font><a href="https://en.wikipedia.org/wiki/Moore_neighborhood" target="_blank"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">eight neighbors</font></font></a><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):</font></font></p><br><br><ol><br>	<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Any live cell with fewer than two live neighbors dies, as if caused by under-population.</font></font></li><br>	<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Any live cell with two or three live neighbors lives on to the next generation.</font></font></li><br>	<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Any live cell with more than three live neighbors dies, as if by over-population..</font></font></li><br>	<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.</font></font></li><br></ol><br><br><p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Write a function to compute the next state (after one update) of the board given its current state.&nbsp;</font></font><span><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">The next state is created by applying the above rules simultaneously to every cell in the current state, where&nbsp;births and deaths occur simultaneously.</font></font></span></p><br><br><p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Example:</font></font></strong></p><br><br><pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Input: <br></font></font></strong><span id="example-input-1-1"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">[</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>&nbsp; [0,1,0],</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>&nbsp; [0,0,1],</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>&nbsp; [1,1,1],</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>&nbsp; [0,0,0]</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>]</font></font></span><br><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Output: <br></font></font></strong><span id="example-output-1"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">[</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>&nbsp; [0,0,0],</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>&nbsp; [1,0,1],</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>&nbsp; [0,1,1],</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>&nbsp; [0,1,0]</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"><br>]</font></font></span><br></pre><br><br><p><b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Follow up</font></font></b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">:</font></font></p><br><br><ol><br>	<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.</font></font></li><br>	<li><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?</font></font></li><br></ol><br></div>

## Solution

c++
```c++
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){              
                update(board,i,j);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){              
                if(board[i][j] == INT_MIN)
                    board[i][j] = 1;
                if(board[i][j] == INT_MAX)
                    board[i][j] = 0;
            }
        }
    }
    
    void update(vector<vector<int>>& board,int i,int j){
        int m = board.size();
        int n = board[0].size();
        int row[] = {-1,-1,-1,0,0,1,1,1};
        int col[] = {-1,0,1,-1,1,-1,0,1};
        
        int ones = 0, zeros = 0;
        for(int k=0;k<8;k++){
            int x = i+row[k];
            int y = j+col[k];
            if(x>=0 && x<m && y>=0 && y<n){
                if(board[x][y] == INT_MIN || board[x][y] == 0) zeros++;
                else  ones ++ ;
            }
        }
        
        if(board[i][j] == 0 && ones==3){
            board[i][j] = INT_MIN;
        }
        if(board[i][j] == 1){
​
```
