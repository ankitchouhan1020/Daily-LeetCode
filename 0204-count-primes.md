---
tags: ["leetcode","hash table","math"]
created: "12/06/2019, 23:09:30"
difficulty: "easy"
---

# [0204-count-primes](https://leetcode.com/problems/count-primes/)

## Problem
<div><p>Count the number of prime numbers less than a non-negative number, <b><i>n</i></b>.</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> 10<br><strong>Output:</strong> 4<br><strong>Explanation:</strong> There are 4 prime numbers less than 10, they are 2, 3, 5, 7.<br></pre><br></div>

## Solution

c++
```c++
class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<int> seive(n,1);
        generateSeive(seive);
        int count=0;
        for(int i=2;i<n;i++){
            if(seive[i]==1) count++;
        }
        
        return count;
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
    
};
​
```
