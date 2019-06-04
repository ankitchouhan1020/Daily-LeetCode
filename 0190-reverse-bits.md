---
tags: ["leetcode","bit manipulation"]
created: "04/06/2019, 11:51:52"
difficulty: "easy"
---

# [0190-reverse-bits](https://leetcode.com/problems/reverse-bits/)

## Problem
<div><p>Reverse bits of a given 32 bits unsigned integer.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> 00000010100101000001111010011100<br><strong>Output:</strong> 00111001011110000010100101000000<br><strong>Explanation: </strong>The input binary string <b>00000010100101000001111010011100</b> represents the unsigned integer 43261596, so return 964176192 which its binary representation is <b>00111001011110000010100101000000</b>.<br></pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> 11111111111111111111111111111101<br><strong>Output:</strong> 10111111111111111111111111111111<br><strong>Explanation: </strong>The input binary string <strong>11111111111111111111111111111101</strong> represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is <strong>10101111110010110010011101101001</strong>.</pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.</li><br>	<li>In Java,&nbsp;the compiler represents the signed integers using <a href="https://en.wikipedia.org/wiki/Two%27s_complement" target="_blank">2's complement notation</a>. Therefore, in <strong>Example 2</strong>&nbsp;above the input represents the signed integer <code>-3</code>&nbsp;and the output represents the signed integer <code>-1073741825</code>.</li><br></ul><br><br><p>&nbsp;</p><br><br><p><b>Follow up</b>:</p><br><br><p>If this function is called many times, how would you optimize it?</p><br></div>

## Solution

c++
```c++
//Just trying bitset
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        int start = 0,end = 31;
        while(start < end){
            bool temp = b[start];
            b[start] = b[end];
            b[end] = temp;
            start++;
            end--;
        }
        return b.to_ulong();
    }
};
​
```
