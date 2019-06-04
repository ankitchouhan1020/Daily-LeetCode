---
tags: ["leetcode","hash table"]
created: "04/06/2019, 11:50:53"
difficulty: "medium"
---

# [1072-flip-columns-for-maximum-number-of-equal-rows](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/)

## Problem
<div><p>Given a <code>matrix</code> consisting of 0s and 1s, we may choose any number of columns in the matrix and flip <strong>every</strong>&nbsp;cell in that column.&nbsp; Flipping a cell changes the value of that cell from 0 to 1 or from 1 to 0.</p><br><br><p>Return the maximum number of rows that have all values equal after some number of flips.</p><br><br><p>&nbsp;</p><br><br><ol><br></ol><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">[[0,1],[1,1]]</span><br><strong>Output: </strong><span id="example-output-1">1</span><br><strong>Explanation: </strong>After flipping no values, 1 row has all values equal.<br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-2-1">[[0,1],[1,0]]</span><br><strong>Output: </strong><span id="example-output-2">2</span><br><strong>Explanation: </strong>After flipping values in the first column, both rows have equal values.<br></pre><br><br><div><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-3-1">[[0,0,0],[0,0,1],[1,1,0]]</span><br><strong>Output: </strong><span id="example-output-3">2</span><br><strong>Explanation: </strong>After flipping values in the first two columns, the last two rows have equal values.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= matrix.length &lt;= 300</code></li><br>	<li><code>1 &lt;= matrix[i].length &lt;= 300</code></li><br>	<li>All <code>matrix[i].length</code>'s are equal</li><br>	<li><code>matrix[i][j]</code> is&nbsp;<code>0</code> or <code>1</code></li><br></ol><br></div><br></div><br></div></div>

## Solution

c++
```c++
//Must Redo Again
​
// Concept find max no. of rows that can be toogled together.
​
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& m) {
        if(m.size() == 0) return 0;
        int ans = 1;
        while(m.size() > 0){
            int cnt = 1;
            for(int j=1;j<m.size();j++){
                int eq = 1, xoreq = 1;
                for(int k=0;k<m[0].size();k++){
                    eq &= m[0][k]==m[j][k];
                    xoreq &= m[0][k]!=m[j][k];
                }
                if(eq || xoreq){
                    cnt++;
                    swap(m[j--],m[m.size()-1]);
                    m.pop_back();
                }
            }
            ans = max(ans,cnt);
            swap(m[0],m[m.size()-1]);
            m.pop_back();
        }
        return ans;
    }
};
​
```
