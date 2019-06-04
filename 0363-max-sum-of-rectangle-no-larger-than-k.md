---
tags: ["leetcode","binary search","dynamic programming","queue"]
created: "01/06/2019, 22:44:21"
difficulty: "hard"
---

# [0363-max-sum-of-rectangle-no-larger-than-k](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)

## Problem
<div><p>Given a non-empty 2D matrix <i>matrix</i> and an integer <i>k</i>, find the max sum of a rectangle in the <i>matrix</i> such that its sum is no larger than <i>k</i>.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input: </strong>matrix = <span id="example-input-1-1">[[1,0,1],[0,-2,3]]</span>, k = <span id="example-input-1-2">2</span><br><strong>Output: </strong><span id="example-output-1">2 <br><strong>Explanation:</strong></span>&nbsp;Because the sum of rectangle <code>[[0, 1], [-2, 3]]</code> is 2,<br>&nbsp;            and 2 is the max number no larger than k (k = 2).</pre><br><br><p><b>Note:</b></p><br><br><ol><br>	<li>The rectangle inside the matrix must have an area &gt; 0.</li><br>	<li>What if the number of rows is much larger than the number of columns?</li><br></ol></div>

## Solution

c++
```c++

// Two imp concept
// 1. 2D dp kadane's algo
// 2. Max sum subarray with constraint
class Solution {
    int res;
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        res = INT_MIN;
        std::vector<int> dp(m,0);
​
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                for (int k = 0; k < m; ++k)
                {
                    dp[k]+=matrix[k][j];
                }
                getSubArray(dp,k);
​
            }
            dp = std::vector<int>(m,0);
        }
        return res;
    }
​
    void getSubArray(std::vector<int> &dp,int k){
        set<int> cumSet;
        cumSet.insert(0);
        int cumSum = 0,n= dp.size();
        int best = INT_MIN;
        for (int i = 0;i < n; ++i)
        {
            cumSum+=dp[i];
            auto it = cumSet.lower_bound(cumSum-k);
            if(it != cumSet.end()){
                best = max(best,cumSum - *it);
            }
            cumSet.insert(cumSum);
        }
        res = max(res,best);
    }
};
​
```
