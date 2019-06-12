---
tags: ["leetcode","math"]
created: "12/06/2019, 23:36:05"
difficulty: "easy"
---

# [0263-ugly-number](https://leetcode.com/problems/ugly-number/)

## Problem
<div><p>Write a program to check whether a given number is an ugly number.</p><br><br><p>Ugly numbers are <strong>positive numbers</strong> whose prime factors only include <code>2, 3, 5</code>.</p><br><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input:</strong> 6<br><strong>Output:</strong> true<br><strong>Explanation: </strong>6 = 2 ×&nbsp;3</pre><br><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input:</strong> 8<br><strong>Output:</strong> true<br><strong>Explanation: </strong>8 = 2 × 2 ×&nbsp;2<br></pre><br><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input:</strong> 14<br><strong>Output:</strong> false <br><strong>Explanation: </strong><code>14</code> is not ugly since it includes another prime factor <code>7</code>.<br></pre><br><br><p><strong>Note:</strong></p><br><br><ol><br>	<li><code>1</code> is typically treated as an ugly number.</li><br>	<li>Input is within the 32-bit signed integer range:&nbsp;[−2<sup>31</sup>,&nbsp; 2<sup>31&nbsp;</sup>− 1].</li><br></ol></div>

## Solution

c++
```c++
class Solution {
public:
    bool isUgly(int num) {
        if(num>0){
            while(num%2==0) num/=2;
            while(num%3==0) num/=3;
            while(num%5==0) num/=5;
            return num==1;
        }
        return false;
    }
};
/*
    bool isUgly(int n) {
        if(n<=0) return false;
        if(n==1 || n==2 || n==3 || n==5) return true;
        vector<int>seive(n+1,1);
        generateSeive(seive);
        if(seive[n] == 1) return false;
        
        for(int i=2;i<n;i++){
            if(seive[i]==1 && n%i == 0){
                int j = n/i;
                if((i==2 || i==3 || i==5) && (seive[j]==-1||j==2 || j==3 || j==5)) continue;
                return false;
            }
        }
        return true;
    }
    
    void generateSeive(vector<int> &seive){
        int n = seive.size()-1;
        for(int i=4;i<=n;i+=2) seive[i]=-1;
        for(int i=3;i*i<=n;i+=2){
            if(seive[i] != -1){
                for(int j=i*2;j<=n;j+=i){
                    seive[j] = -1;
                }
            }
        }
    }
*/
​
```
