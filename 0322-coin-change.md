---
tags: ["leetcode","dynamic programming"]
created: "26/05/2019, 16:58:28"
difficulty: "medium"
---

# [0322-coin-change](https://leetcode.com/problems/coin-change/)

## Problem
<div><p>You are given coins of different denominations and a total amount of money <i>amount</i>. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return <code>-1</code>.</p><br><br><p><b>Example 1:</b></p><br><br><pre><strong>Input: </strong>coins = <code>[1, 2, 5]</code>, amount = <code>11</code><br><strong>Output: </strong><code>3</code> <br><strong>Explanation:</strong> 11 = 5 + 5 + 1</pre><br><br><p><b>Example 2:</b></p><br><br><pre><strong>Input: </strong>coins = <code>[2]</code>, amount = <code>3</code><br><strong>Output: </strong>-1<br></pre><br><br><p><b>Note</b>:<br><br>You may assume that you have an infinite number of each kind of coin.</p><br></div>

## Solution

c++
```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1 ) return 0;
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int coin: coins){
                if(coin <= i){
                    dp[i] = min(--dp[i],dp[i-coin]) + 1;
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
​
​
```
