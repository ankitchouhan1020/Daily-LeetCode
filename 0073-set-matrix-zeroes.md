---
tags: ["leetcode","array"]
created: "04/06/2019, 18:42:10"
difficulty: "medium"
---

# [0073-set-matrix-zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

## Problem
<div><p>Given a <em>m</em> x <em>n</em> matrix, if an element is 0, set its entire row and column to 0. Do it <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a>.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> <br>[<br>&nbsp; [1,1,1],<br>&nbsp; [1,0,1],<br>&nbsp; [1,1,1]<br>]<br><strong>Output:</strong> <br>[<br>&nbsp; [1,0,1],<br>&nbsp; [0,0,0],<br>&nbsp; [1,0,1]<br>]<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> <br>[<br>&nbsp; [0,1,2,0],<br>&nbsp; [3,4,5,2],<br>&nbsp; [1,3,1,5]<br>]<br><strong>Output:</strong> <br>[<br>&nbsp; [0,0,0,0],<br>&nbsp; [0,4,5,0],<br>&nbsp; [0,3,1,0]<br>]<br></pre><br><br><p><strong>Follow up:</strong></p><br><br><ul><br>	<li>A straight forward solution using O(<em>m</em><em>n</em>) space is probably a bad idea.</li><br>	<li>A simple improvement uses O(<em>m</em> + <em>n</em>) space, but still not the best solution.</li><br>	<li>Could you devise a constant space solution?</li><br></ul><br></div>

## Solution

c++
```c++

//Constant space solution
//First time done by simulting row and then col with -1 if 0 is found
// But it didn't work if matrix has -1 or INT_MIN
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m =  matrix.size();
        int n =  matrix[0].size();
        bool row = false,col = false;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    if(i==0) row = true;
                    if(j==0) col = true;
                    
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j] == 0 || matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(row) for(int j=0;j<n;j++) matrix[0][j]=0;
        if(col) for(int i=0;i<m;i++) matrix[i][0]=0;
    }
​
```
