---
tags: ["leetcode","hash table"]
created: "28/06/2019, 22:19:39"
difficulty: "medium"
---

# [0957-prison-cells-after-n-days](https://leetcode.com/problems/prison-cells-after-n-days/)

## Problem
<div><p>There are 8 prison cells in a row, and each cell is either occupied or vacant.</p><br><br><p>Each day, whether the cell is occupied or vacant changes according to the following rules:</p><br><br><ul><br>	<li>If a cell has two adjacent neighbors that are both occupied or both vacant,&nbsp;then the cell becomes occupied.</li><br>	<li>Otherwise, it becomes vacant.</li><br></ul><br><br><p>(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)</p><br><br><p>We describe the current state of the prison&nbsp;in the following way:&nbsp;<code>cells[i] == 1</code> if the <code>i</code>-th cell is occupied, else <code>cells[i] == 0</code>.</p><br><br><p>Given the initial state of the prison, return the state of the prison after <code>N</code> days (and <code>N</code> such changes described above.)</p><br><br><p>&nbsp;</p><br><br><div><br><ol><br></ol><br></div><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>cells = <span id="example-input-1-1">[0,1,0,1,1,0,0,1]</span>, N = <span id="example-input-1-2">7</span><br><strong>Output: </strong><span id="example-output-1">[0,0,1,1,0,0,0,0]</span><br><strong>Explanation: <br></strong><span id="example-output-1">The following table summarizes the state of the prison on each day:<br>Day 0: [0, 1, 0, 1, 1, 0, 0, 1]<br>Day 1: [0, 1, 1, 0, 0, 0, 0, 0]<br>Day 2: [0, 0, 0, 0, 1, 1, 1, 0]<br>Day 3: [0, 1, 1, 0, 0, 1, 0, 0]<br>Day 4: [0, 0, 0, 0, 0, 1, 0, 0]<br>Day 5: [0, 1, 1, 1, 0, 1, 0, 0]<br>Day 6: [0, 0, 1, 0, 1, 1, 0, 0]<br>Day 7: [0, 0, 1, 1, 0, 0, 0, 0]</span><br><br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>cells = <span id="example-input-2-1">[1,0,0,1,0,0,1,0]</span>, N = <span id="example-input-2-2">1000000000</span><br><strong>Output: </strong><span id="example-output-2">[0,0,1,1,1,1,1,0]</span><br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>cells.length == 8</code></li><br>	<li><code>cells[i]</code> is in <code>{0, 1}</code></li><br>	<li><code>1 &lt;= N &lt;= 10^9</code></li><br></ol><br></div><br></div><br></div>

## Solution

c++
```c++
//original :@ghazy solution
​
// I think we will do N%=cylce only once.
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int n = cells.size(),cycle = 0;
        vector<int> curr(n,0),direct;
        while(N--){
            for(int j=1;j<n-1;j++) curr[j] = cells[j-1] == cells[j+1];
            if(direct.empty()) direct = curr;
            else if(direct == curr) N%=cycle;
            cycle++;
            cells = curr;
        }
        return curr;
    }
};
​
```
