---
tags: ["leetcode","string","backtracking"]
created: "26/05/2019, 16:20:13"
difficulty: "medium"
---

# [0017-letter-combinations-of-a-phone-number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

## Problem
<div><p>Given a string containing digits from <code>2-9</code> inclusive, return all possible letter combinations that the number could represent.</p><br><br><p>A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.</p><br><br><p><img src="http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png"></p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input: </strong>"23"<br><strong>Output:</strong> ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].<br></pre><br><br><p><strong>Note:</strong></p><br><br><p>Although the above answer is in lexicographical order, your answer could be in any order you want.</p><br></div>

## Solution

c++
```c++
class Solution {
    private:
    vector<string> result;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;
        unordered_map<int,string> hash = {{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},                                          {6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        addCombination(digits,hash,0,"");
        return result;
    }
    
    void addCombination(string digits,unordered_map<int,string>&hash,int i,string tempString){
        if( i == digits.size()){
            result.push_back(tempString);
            return ;
        }
        string letters = hash[digits[i]-'0'];
        for(char letter:letters){
            addCombination(digits,hash,i+1,tempString + letter);            
        }
        return;        
    }
};
​
```
