---
tags: ["leetcode","array"]
created: "05/06/2019, 12:04:00"
difficulty: "medium"
---

# [0054-spiral-matrix](https://leetcode.com/problems/spiral-matrix/)

## Problem
<div><p>Given a matrix of <em>m</em> x <em>n</em> elements (<em>m</em> rows, <em>n</em> columns), return all elements of the matrix in spiral order.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong><br>[<br> [ 1, 2, 3 ],<br> [ 4, 5, 6 ],<br> [ 7, 8, 9 ]<br>]<br><strong>Output:</strong> [1,2,3,6,9,8,7,4,5]<br></pre><br><br><p><strong>Example 2:</strong></p><br><pre><strong>Input:</strong><br>[<br>  [1, 2, 3, 4],<br>  [5, 6, 7, 8],<br>  [9,10,11,12]<br>]<br><strong>Output:</strong> [1,2,3,4,8,12,11,10,9,5,6,7]<br></pre></div>

## Solution

c++
```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return vector<int>();
        int cs=0,rs=0,ce=matrix[0].size()-1,re=matrix.size()-1;
        vector<int> ans;
        
        while(cs <= ce && rs <= re){
            
            for(int i=cs;i<=ce;i++){
                ans.push_back(matrix[rs][i]);
            }
            if( cs > ce) break;
            rs++;
            
            for(int i=rs;i<=re;i++){
                ans.push_back(matrix[i][ce]);
            }
            if( rs > re) break;
            ce--;
            
            for(int i=ce;i>=cs;i--){
                ans.push_back(matrix[re][i]);
            }
            if( cs > ce) break;
            re--;
            
            for(int i=re;i>=rs;i--){
                ans.push_back(matrix[i][cs]);
            }
            if( rs > re) break;
            cs++;
        }
        return ans;
    }
};
​
```
