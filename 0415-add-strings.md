---
tags: ["leetcode","string"]
created: "06/07/2019, 00:52:08"
difficulty: "easy"
---

# [0415-add-strings](https://leetcode.com/problems/add-strings/)

## Problem
<div><p>Given two non-negative integers <code>num1</code> and <code>num2</code> represented as string, return the sum of <code>num1</code> and <code>num2</code>.</p><br><br><p><b>Note:</b><br></p><ol><br><li>The length of both <code>num1</code> and <code>num2</code> is &lt; 5100.</li><br><li>Both <code>num1</code> and <code>num2</code> contains only digits <code>0-9</code>.</li><br><li>Both <code>num1</code> and <code>num2</code> does not contain any leading zero.</li><br><li>You <b>must not use any built-in BigInteger library</b> or <b>convert the inputs to integer</b> directly.</li><br></ol><br><p></p></div>

## Solution

c++
```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.empty() || num2.empty()){
            return num1.empty() ? num2 : num1;
        }
        string ans = "";
        int carry = 0;
        int i = num1.size()-1;
        int j = num2.size()-1;
        
        while(i>=0 && j>=0){
            int a = num1[i]-'0';
            int b = num2[j]-'0';
            a = a+b+carry;
            carry = 0;
            if(a < 10) ans.push_back(a + '0');
            else{
                carry = 1;
                a = a%10;
                ans.push_back(a + '0');
            }
            i--;j--;
        }
                
        while(i >= 0){
            int a = num1[i] - '0';
            a += carry;
            if(a < 10){
                ans.push_back(a + '0');
                carry = 0;
            }
            else{
                carry = 1;
                a = a%10;
                ans.push_back(a + '0');
            }
            i--;
        }
        while(j >= 0){
            int a = num2[j] - '0';
            a += carry;
            if(a < 10){
                ans.push_back(a + '0');
                carry = 0;
            }
            else{
                carry = 1;
                a = a%10;
                ans.push_back(a + '0');
            } 
            j--;
        }
        if(carry){
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
​
```
