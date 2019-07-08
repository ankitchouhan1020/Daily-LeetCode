---
tags: ["leetcode","dynamic programming"]
created: "08/07/2019, 13:28:10"
difficulty: "medium"
---

# [1105-filling-bookcase-shelves](https://leetcode.com/problems/filling-bookcase-shelves/)

## Problem
<div><p>We have a sequence of <code>books</code>: the <code>i</code>-th book has thickness <code>books[i][0]</code> and height <code>books[i][1]</code>.</p><br><br><p>We want to place these books <strong>in order</strong>&nbsp;onto bookcase shelves that have total width <code>shelf_width</code>.</p><br><br><p>We choose&nbsp;some of the books to place on this shelf (such that the sum of their thickness is <code>&lt;= shelf_width</code>), then build another level of shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down.&nbsp; We repeat this process until there are no more books to place.</p><br><br><p>Note again that at each step of the above&nbsp;process, <u>the order of the books we place is the same order as the given sequence of books</u>.&nbsp; For example, if we have an ordered list of 5&nbsp;books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.</p><br><br><p>Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.</p><br><br><p>&nbsp;</p><br><p><strong>Example 1:</strong></p><br><img alt="" src="https://assets.leetcode.com/uploads/2019/06/24/shelves.png" style="width: 250px; height: 370px;"><br><pre><strong>Input:</strong> books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4<br><strong>Output:</strong> 6<br><strong>Explanation:</strong><br>The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.<br>Notice that book number 2 does not have to be on the first shelf.<br></pre><br><br><p>&nbsp;</p><br><p><strong>Constraints:</strong></p><br><br><ul><br>	<li><code>1 &lt;= books.length &lt;= 1000</code></li><br>	<li><code>1 &lt;= books[i][0] &lt;= shelf_width &lt;= 1000</code></li><br>	<li><code>1 &lt;= books[i][1] &lt;= 1000</code></li><br></ul></div>

## Solution

c++
```c++
// dp[i] --> minimum height after placing shelf from i to n-1
​
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size(),INT_MAX);
        return perfectShelf(books,shelf_width,0,dp);
    }
    int perfectShelf(vector<vector<int>>&books,int limit,int start,vector<int> &dp){
        int n = books.size();
        if(start == n) return 0;
        if(dp[start] != INT_MAX) return dp[start];
        int prefix = 0;
        int height = 0;
        int mini = INT_MAX;
        
        for(int i = start; i<n; i++){
            prefix += books[i][0];
            height = max(height, books[i][1]);
            if(prefix <= limit){
                mini = min(mini, height + perfectShelf(books,limit,i+1,dp));
                continue;
            }
            break;
        }
        return dp[start] = mini;
    }
};
​
```
