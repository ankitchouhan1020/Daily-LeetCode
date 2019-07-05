---
tags: ["leetcode"]
created: "06/07/2019, 00:49:37"
difficulty: "easy"
---

# [0796-rotate-string](https://leetcode.com/problems/rotate-string/)

## Problem
<div><p>We are given two strings, <code>A</code> and <code>B</code>.</p><br><br><p>A <em>shift on <code>A</code></em> consists of taking string <code>A</code> and moving the leftmost character to the rightmost position. For example, if <code>A = 'abcde'</code>, then it will be <code>'bcdea'</code> after one shift on <code>A</code>. Return <code>True</code> if and only if <code>A</code> can become <code>B</code> after some number of shifts on <code>A</code>.</p><br><br><pre><strong>Example 1:</strong><br><strong>Input:</strong> A = 'abcde', B = 'cdeab'<br><strong>Output:</strong> true<br><br><strong>Example 2:</strong><br><strong>Input:</strong> A = 'abcde', B = 'abced'<br><strong>Output:</strong> false<br></pre><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li><code>A</code> and <code>B</code> will have length at most <code>100</code>.</li><br></ul><br></div>

## Solution

c++
```c++
//Okay I was lazy to solve it without regex
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A.empty()) return true;
        A = A + A;
        B = "(.*)" + B + "(.*)";
        return regex_match(A,regex(B));
    }
};
​
```
