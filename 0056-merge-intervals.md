---
tags: ["leetcode","array","sort"]
created: "30/05/2019, 22:43:36"
difficulty: "medium"
---

# [0056-merge-intervals](https://leetcode.com/problems/merge-intervals/)

## Problem
<div><p>Given a collection of intervals, merge all overlapping intervals.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> [[1,3],[2,6],[8,10],[15,18]]<br><strong>Output:</strong> [[1,6],[8,10],[15,18]]<br><strong>Explanation:</strong> Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> [[1,4],[4,5]]<br><strong>Output:</strong> [[1,5]]<br><strong>Explanation:</strong> Intervals [1,4] and [4,5] are considered overlapping.</pre><br><br><p><strong>NOTE:</strong>&nbsp;input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.</p><br></div>

## Solution

c++
```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return intervals;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        for(int i=0;i<n;){
            int mini = intervals[i][0];
            int maxi = intervals[i][1];
            i++;
            while(i<n && intervals[i][0] <= maxi){
                maxi = max(maxi,intervals[i][1]);
                i++;
            }
            res.push_back({mini,maxi});
        }
        return res;
    }
};
​
```
