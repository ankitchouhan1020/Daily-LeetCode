---
tags: ["leetcode","math","dynamic programming"]
created: "11/06/2019, 13:59:13"
difficulty: "easy"
---

# [1025-divisor-game](https://leetcode.com/problems/divisor-game/)

## Problem
<div><p>Alice and Bob take turns playing a game, with Alice starting first.</p><br><br><p>Initially, there is a number <code>N</code>&nbsp;on the chalkboard.&nbsp; On each player's turn, that player makes a <em>move</em>&nbsp;consisting of:</p><br><br><ul><br>	<li>Choosing&nbsp;any <code>x</code> with <code>0 &lt; x &lt; N</code> and <code>N % x == 0</code>.</li><br>	<li>Replacing&nbsp;the number&nbsp;<code>N</code>&nbsp;on the chalkboard with <code>N - x</code>.</li><br></ul><br><br><p>Also, if a player cannot make a move, they lose the game.</p><br><br><p>Return <code>True</code> if and only if Alice wins the game, assuming both players play optimally.</p><br><br><p>&nbsp;</p><br><br><ol><br></ol><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">2</span><br><strong>Output: </strong><span id="example-output-1">true</span><br><strong>Explanation:</strong> Alice chooses 1, and Bob has no more moves.<br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-2-1">3</span><br><strong>Output: </strong><span id="example-output-2">false</span><br><strong>Explanation:</strong> Alice chooses 1, Bob chooses 1, and Alice has no more moves.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= N &lt;= 1000</code></li><br></ol><br></div><br></div></div>

## Solution

c++
```c++
class Solution {
public:
    bool divisorGame(int N) {
        return N%2==0;
        // If alice loose for N then she will surely win for N+1
        // If N is even alice will surely given bob an odd, because odd have only one choice.
        // If N is odd then alice is required to give bob an even since divisor of odd is odd
    }
};
​
```
