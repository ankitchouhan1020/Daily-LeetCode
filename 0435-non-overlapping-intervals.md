---
tags: ["leetcode","greedy"]
created: "30/05/2019, 22:44:34"
difficulty: "medium"
---

# [0435-non-overlapping-intervals](https://leetcode.com/problems/non-overlapping-intervals/)

## Problem
<div><p>Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.</p><br><br><p><b>Note:</b></p><br><br><ol><br>	<li>You may assume the interval's end point is always bigger than its start point.</li><br>	<li>Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.</li><br></ol><br><br><p>&nbsp;</p><br><br><p><b>Example 1:</b></p><br><br><pre><b>Input:</b> [ [1,2], [2,3], [3,4], [1,3] ]<br><br><b>Output:</b> 1<br><br><b>Explanation:</b> [1,3] can be removed and the rest of intervals are non-overlapping.<br></pre><br><br><p>&nbsp;</p><br><br><p><b>Example 2:</b></p><br><br><pre><b>Input:</b> [ [1,2], [1,2], [1,2] ]<br><br><b>Output:</b> 2<br><br><b>Explanation:</b> You need to remove two [1,2] to make the rest of intervals non-overlapping.<br></pre><br><br><p>&nbsp;</p><br><br><p><b>Example 3:</b></p><br><br><pre><b>Input:</b> [ [1,2], [2,3] ]<br><br><b>Output:</b> 0<br><br><b>Explanation:</b> You don't need to remove any of the intervals since they're already non-overlapping.<br></pre><br><br><p><strong>NOTE:</strong>&nbsp;input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.</p><br></div>

## Solution

c++
```c++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ins) {
        if(ins.empty()) return 0;
        
        sort(ins.begin(),ins.end());
        vector<vector<int>> res;
        res.push_back(ins[0]);
        
        for(int i=0;i<ins.size();i++){
            int last = res.back()[1];
            if(last > ins[i][0]){
                res.back()[1] = min(last,ins[i][1]);
            }else{
                res.push_back(ins[i]);
            }
        }
        
        return ins.size()-res.size();
    }
};
//Can be done without res.
​
```
