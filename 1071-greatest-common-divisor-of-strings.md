---
tags: ["leetcode","string"]
created: "04/06/2019, 11:50:47"
difficulty: "easy"
---

# [1071-greatest-common-divisor-of-strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

## Problem
<div><p>For strings <code>S</code> and <code>T</code>, we say "<code>T</code> divides <code>S</code>" if and only if <code>S = T + ... + T</code>&nbsp; (<code>T</code> concatenated with itself 1 or more times)</p><br><br><p>Return the largest string <code>X</code> such that <code>X</code> divides <font face="monospace">str1</font>&nbsp;and <code>X</code> divides <font face="monospace">str2</font>.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong>str1 = <span id="example-input-1-1">"ABCABC"</span>, str2 = <span id="example-input-1-2">"ABC"</span><br><strong>Output: </strong><span id="example-output-1">"ABC"</span><br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong>str1 = <span id="example-input-2-1">"ABABAB"</span>, str2 = <span id="example-input-2-2">"ABAB"</span><br><strong>Output: </strong><span id="example-output-2">"AB"</span><br></pre><br><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong>str1 = <span id="example-input-3-1">"LEET"</span>, str2 = <span id="example-input-3-2">"CODE"</span><br><strong>Output: </strong><span id="example-output-3">""</span><br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1 &lt;= str1.length &lt;= 1000</code></li><br>	<li><code>1 &lt;= str2.length &lt;= 1000</code></li><br>	<li><code>str1[i]</code> and <code>str2[i]</code> are English uppercase letters.</li><br></ol></div>

## Solution

c++
```c++
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if (str2.empty()) return str1;
        if (str1.substr(0, str2.size()) != str2) return "";
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};
​
// Discuss Solution
// Modulo approach is wrong here
​
```
