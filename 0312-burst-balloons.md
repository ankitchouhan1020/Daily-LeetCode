---
tags: ["leetcode","divide and conquer","dynamic programming"]
created: "19/06/2019, 13:39:18"
difficulty: "hard"
---

# [0312-burst-balloons](https://leetcode.com/problems/burst-balloons/)

## Problem
<div><p>Given <code>n</code> balloons, indexed from <code>0</code> to <code>n-1</code>. Each balloon is painted with a number on it represented by array <code>nums</code>. You are asked to burst all the balloons. If the you burst balloon <code>i</code> you will get <code>nums[left] * nums[i] * nums[right]</code> coins. Here <code>left</code> and <code>right</code> are adjacent indices of <code>i</code>. After the burst, the <code>left</code> and <code>right</code> then becomes adjacent.</p><br><br><p>Find the maximum coins you can collect by bursting the balloons wisely.</p><br><br><p><b>Note:</b></p><br><br><ul><br>	<li>You may imagine <code>nums[-1] = nums[n] = 1</code>. They are not real therefore you can not burst them.</li><br>	<li>0 ≤ <code>n</code> ≤ 500, 0 ≤ <code>nums[i]</code> ≤ 100</li><br></ul><br><br><p><b>Example:</b></p><br><br><pre><b>Input:</b> <code>[3,1,5,8]</code><br><b>Output:</b> <code>167 <br><strong>Explanation: </strong></code>nums = [3,1,5,8] --&gt; [3,5,8] --&gt;   [3,8]   --&gt;  [8]  --&gt; []<br>&nbsp;            coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167<br></pre></div>

## Solution

c++
```c++
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> num;
        num.push_back(1);
        num.insert(num.end(),nums.begin(),nums.end());
        num.push_back(1);
​
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));        
        
        return maxCoin(num,dp,0,n+1);
    }
    
    int maxCoin(vector<int>& num,vector<vector<int>>&dp,int left, int right){
        if(left+1 == right) return 0;
        
        if(dp[left][right] != -1) return dp[left][right];
        
        int maxiCoins = 0;
        for(int k=left+1;k < right;k++){
            int lpart = maxCoin(num,dp,left,k);
            int rpart = maxCoin(num,dp,k,right);
            int tmp = num[left]*num[k]*num[right] + lpart + rpart;
            maxiCoins = max(maxiCoins,tmp);
        }
        return dp[left][right] = maxiCoins;        
    }
};
​
```
