---
tags: ["leetcode","greedy"]
created: "15/06/2019, 16:46:56"
difficulty: "easy"
---

# [0860-lemonade-change](https://leetcode.com/problems/lemonade-change/)

## Problem
<div><p>At a lemonade stand, each lemonade costs <code>$5</code>.&nbsp;</p><br><br><p>Customers are standing in a queue to buy from you, and order one at a time (in the order specified by <code>bills</code>).</p><br><br><p>Each customer will only buy one lemonade and&nbsp;pay with either a <code>$5</code>, <code>$10</code>, or <code>$20</code> bill.&nbsp; You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.</p><br><br><p>Note that you don't have any change&nbsp;in hand at first.</p><br><br><p>Return <code>true</code>&nbsp;if and only if you can provide every customer with correct change.</p><br><br><p>&nbsp;</p><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">[5,5,5,10,20]</span><br><strong>Output: </strong><span id="example-output-1">true</span><br><strong>Explanation: </strong><br>From the first 3 customers, we collect three $5 bills in order.<br>From the fourth customer, we collect a $10 bill and give back a $5.<br>From the fifth customer, we give a $10 bill and a $5 bill.<br>Since all customers got correct change, we output true.<br></pre><br><br><div><br><p><strong>Example 2:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-2-1">[5,5,10]</span><br><strong>Output: </strong><span id="example-output-2">true</span><br></pre><br><br><div><br><p><strong>Example 3:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-3-1">[10,10]</span><br><strong>Output: </strong><span id="example-output-3">false</span><br></pre><br><br><div><br><p><strong>Example 4:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-4-1">[5,5,10,10,20]</span><br><strong>Output: </strong><span id="example-output-4">false</span><br><strong>Explanation: </strong><br>From the first two customers in order, we collect two $5 bills.<br>For the next two customers in order, we collect a $10 bill and give back a $5 bill.<br>For the last customer, we can't give change of $15 back because we only have two $10 bills.<br>Since not every customer received correct change, the answer is false.<br></pre><br><br><p>&nbsp;</p><br><br><p><strong><span>Note:</span></strong></p><br><br><ul><br>	<li><code>0 &lt;= bills.length &lt;= 10000</code></li><br>	<li><code>bills[i]</code>&nbsp;will be either&nbsp;<code>5</code>, <code>10</code>, or <code>20</code>.</li><br></ul><br></div><br></div><br></div><br></div><br></div>

## Solution

c++
```c++
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cFive = 0,cTen=0;
        
        for(int i: bills){
            if(i==5) cFive++;
            
            else if(i==10){
                if(cFive==0) return false;
                cFive--;
                cTen++;
            }
            
            else if(i==20){
                if(cFive >= 3 || (cTen>=1 && cFive>=1)){
                    if(cTen>=1){
                        cTen--;
                        cFive--;
                    }else{
                        cFive-=3;
                    }                    
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
​
```
