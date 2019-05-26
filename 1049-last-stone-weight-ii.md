---
tags: ["leetcode","dynamic programming"]
created: "26/05/2019, 17:18:15"
difficulty: "medium"
---

# [1049-last-stone-weight-ii](https://leetcode.com/problems/last-stone-weight-ii/)

## Problem
<div><p>We have a collection of rocks, each rock has a positive integer weight.</p><br><br><p>Each turn, we choose <strong>any two rocks</strong>&nbsp;and smash them together.&nbsp; Suppose the stones have weights <code>x</code> and <code>y</code> with <code>x &lt;= y</code>.&nbsp; The result of this smash is:</p><br><br><ul><br>	<li>If <code>x == y</code>, both stones are totally destroyed;</li><br>	<li>If <code>x != y</code>, the stone of weight <code>x</code> is totally destroyed, and the stone of weight <code>y</code> has new weight <code>y-x</code>.</li><br></ul><br><br><p>At the end, there is at most 1 stone left.&nbsp; Return the <strong>smallest possible</strong> weight of this stone (the weight is&nbsp;0 if there are no stones left.)</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>[2,7,4,1,8,1]<br><strong>Output: </strong>1<br><strong>Explanation: </strong><br>We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,<br>we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,<br>we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,<br>we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= stones.length &lt;= 30</code></li><br>	<li><code>1 &lt;= stones[i] &lt;= 100</code></li><br></ol></div>

## Solution

c++
```c++
class Solution {
    private:
    int sumStone;
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 0) return 0;
        if(stones.size()==1) return stones[0];
        sumStone = accumulate(stones.begin(),stones.end(),0);    
        vector<vector<int>> dp(sumStone,vector<int>(stones.size(),-1));
        return minRock(stones,dp,0,0);
    }
    
    int minRock(vector<int>& stones,vector<vector<int>>& dp,int cost,int ptr){
        if(ptr == stones.size())    return abs(sumStone-2*cost);
        if(dp[cost][ptr] != -1) return dp[cost][ptr];
        return dp[cost][ptr] = min(minRock(stones,dp,cost+stones[ptr],ptr+1),minRock(stones,dp,cost,ptr+1));
    }
};
​
```
