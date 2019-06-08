---
tags: ["leetcode","array"]
created: "05/06/2019, 12:34:24"
difficulty: "medium"
---

# [0048-rotate-image](https://leetcode.com/problems/rotate-image/)

## Problem
<div><p>You are given an <em>n</em> x <em>n</em> 2D matrix representing an image.</p><br><br><p>Rotate the image by 90 degrees (clockwise).</p><br><br><p><strong>Note:</strong></p><br><br><p>You have to rotate the image <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a>, which means you have to modify the input 2D matrix directly. <strong>DO NOT</strong> allocate another 2D matrix and do the rotation.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre>Given <strong>input matrix</strong> = <br>[<br>  [1,2,3],<br>  [4,5,6],<br>  [7,8,9]<br>],<br><br>rotate the input matrix <strong>in-place</strong> such that it becomes:<br>[<br>  [7,4,1],<br>  [8,5,2],<br>  [9,6,3]<br>]<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre>Given <strong>input matrix</strong> =<br>[<br>  [ 5, 1, 9,11],<br>  [ 2, 4, 8,10],<br>  [13, 3, 6, 7],<br>  [15,14,12,16]<br>], <br><br>rotate the input matrix <strong>in-place</strong> such that it becomes:<br>[<br>  [15,13, 2, 5],<br>  [14, 3, 4, 1],<br>  [12, 6, 8, 9],<br>  [16, 7,10,11]<br>]<br></pre><br></div>

## Solution

c++
```c++
//General Method
// Clockwise Rotation : swap rows, swap symmetry
// Anticlock : swap cols, swap symmetry
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m;
        
        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
        for(int i=0;i<m-1;i++){
            int c = 1;
            for(int j=n-2;j>=0;j--){
                swap(matrix[i][j],matrix[i+c][j+c]);
                c++;
            }
            n--;            
        }
    }
};
​
```
