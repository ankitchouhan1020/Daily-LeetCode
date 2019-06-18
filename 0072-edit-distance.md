---
tags: ["leetcode","string","dynamic programming"]
created: "17/06/2019, 15:06:17"
difficulty: "hard"
---

# [0072-edit-distance](https://leetcode.com/problems/edit-distance/)

## Problem
<div><p>Given two words <em>word1</em> and <em>word2</em>, find the minimum number of operations required to convert <em>word1</em> to <em>word2</em>.</p><br><br><p>You have the following 3 operations permitted on a word:</p><br><br><ol><br>	<li>Insert a character</li><br>	<li>Delete a character</li><br>	<li>Replace a character</li><br></ol><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> word1 = "horse", word2 = "ros"<br><strong>Output:</strong> 3<br><strong>Explanation:</strong> <br>horse -&gt; rorse (replace 'h' with 'r')<br>rorse -&gt; rose (remove 'r')<br>rose -&gt; ros (remove 'e')<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> word1 = "intention", word2 = "execution"<br><strong>Output:</strong> 5<br><strong>Explanation:</strong> <br>intention -&gt; inention (remove 't')<br>inention -&gt; enention (replace 'i' with 'e')<br>enention -&gt; exention (replace 'n' with 'x')<br>exention -&gt; exection (replace 'n' with 'c')<br>exection -&gt; execution (insert 'u')<br></pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    int minDistance(string w1, string w2) {
        
        int m = w1.size(),n = w2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++) dp[i][0] = i;
        for(int j=1;j<=n;j++) dp[0][j] = j;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(w1[i-1] == w2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
​
/*
Let's say we have 2 words "abcde" and "fghij", and we already know the min distance from "abcd" to "fgh".
​
a b c d
f g h
Now we would like to go a step further and convert "abcde" to "fghi".
​
a b c d e
f g h i
There're 3 ways to accomplish it:
​
Replace "e" by "i".
a b c d        a b c d e 
          ->                           ->  dp[i-1][j-1] + 1 (for replacement)
f g h          f g h i
If we know the min distance from "abcd" to "fghi", then for "abcde", we just need to delete "e".
a b c d        a b c d e(delete)
          ->                           ->  dp[i-1][j] + 1 (for deletion)
f g h i        f g h i
If we know the min distance from "abcde" to "fgh", then we need to add an "i" to "abcde"
a b c d e      a b c d e (add an "i")
          ->                           ->  dp[i][j-1] + 1 (for insertion)
f g h          f g h i
​
*/
​
```
