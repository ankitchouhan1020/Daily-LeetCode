---
tags: ["leetcode","dynamic programming"]
created: "21/06/2019, 11:40:13"
difficulty: "hard"
---

# [1000-minimum-cost-to-merge-stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/)

## Problem
<div><p>There are <code>N</code> piles of stones arranged in a row.&nbsp; The <code>i</code>-th pile has <code>stones[i]</code> stones.</p><br><br><p>A <em>move</em> consists of merging <strong>exactly&nbsp;<code>K</code>&nbsp;consecutive</strong> piles into one pile, and the cost of this move is equal to the total number of stones in these <code>K</code> piles.</p><br><br><p>Find the minimum cost to merge all piles of stones into one pile.&nbsp; If it is impossible, return <code>-1</code>.</p><br><br><p>&nbsp;</p><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>stones = <span id="example-input-1-1">[3,2,4,1]</span>, K = <span id="example-input-1-2">2</span><br><strong>Output: </strong><span id="example-output-1">20</span><br><strong>Explanation: </strong><br>We start with [3, 2, 4, 1].<br>We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].<br>We merge [4, 1] for a cost of 5, and we are left with [5, 5].<br>We merge [5, 5] for a cost of 10, and we are left with [10].<br>The total cost was 20, and this is the minimum possible.<br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>stones = <span id="example-input-2-1">[3,2,4,1]</span>, K = <span id="example-input-2-2">3</span><br><strong>Output: </strong><span id="example-output-2">-1</span><br><strong>Explanation: </strong>After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.<br></pre><br><br><div><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong>stones = <span id="example-input-3-1">[3,5,1,2,6]</span>, K = <span id="example-input-3-2">3</span><br><strong>Output: </strong><span id="example-output-3">25</span><br><strong>Explanation: </strong><br>We start with [3, 5, 1, 2, 6].<br>We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].<br>We merge [3, 8, 6] for a cost of 17, and we are left with [17].<br>The total cost was 25, and this is the minimum possible.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong><span>Note:</span></strong></p><br><br><ul><br>	<li><code><span>1 &lt;= stones.length &lt;= 30</span></code></li><br>	<li><code><span>2 &lt;= K &lt;= 30</span></code></li><br>	<li><code><span>1 &lt;= stones[i] &lt;= 100</span></code></li><br></ul><br></div><br></div><br></div></div>

## Solution

c++
```c++
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        // any case in which piles cannot merged will be handled here.
        if((n-1)%(K-1)) return -1;
        vector<vector<int>> dp(n,vector<int>(n));
        
        vector<int> prefix(n+1);
        prefix[0] = 0;
        for(int i=1;i<=n;i++)    prefix[i] = prefix[i-1] + stones[i-1];
        
        for(int l=2; l<=n; l++){
            for(int i=0; i<=(n-l); i++){
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                
                // dp[i][j] -> minimum cost to merge from i to j
                // break at every part in between for possible solution
                for(int mid=i; mid<j; mid+=K-1){
                    dp[i][j] = min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
                }
                
                // If some i..j cannot be merge because of lower than K. Then don't add their merging cost
                if((j-i)%(K-1) == 0){
                    dp[i][j] += prefix[j+1] - prefix[i];
                }
            }
        }
        // for(auto i: dp){
        //     for(int j:i)
        //         cout<<j<<" ";
        //     cout<<"\n";
        // }
        return dp[0][n-1];
    }
};
​
/*
Each step merges K piles into 1, which takes away K piles and puts back 1 in their place. This reduces the stones by K-1. If Ni is the number of stones after i merges, then we have:
N0 = N = length of stones array
N1 = N - K + 1 = N - (K-1)
N2 = N - K + 1 - K + 1 = N - (K-1)*2
Ni = N - (K - 1)*i
We eventually need some Ni to equal 1 (to represent the 1 remaining pile on success), so we have:
N - (K-1) * i == 1
N - 1 == (K-1) * i
So, N-1 is a multiple of K-1, or:
(N-1) % (K-1) == 0.
*/
​
```
