---
tags: ["leetcode","stack","depth-first search"]
created: "26/05/2019, 17:02:13"
difficulty: "medium"
---

# [0394-decode-string](https://leetcode.com/problems/decode-string/)

## Problem
<div><p><br>Given an encoded string, return it's decoded string.<br></p><br><p><br>The encoding rule is: <code>k[encoded_string]</code>, where the <i>encoded_string</i> inside the square brackets is being repeated exactly <i>k</i> times. Note that <i>k</i> is guaranteed to be a positive integer.</p><br><br><p><br>You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.</p><br><br><p>Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, <i>k</i>. For example, there won't be input like <code>3a</code> or <code>2[4]</code>.<br></p><br><br><p><b>Examples:</b><br></p><pre>s = "3[a]2[bc]", return "aaabcbc".<br>s = "3[a2[c]]", return "accaccacc".<br>s = "2[abc]3[cd]ef", return "abcabccdcdcdef".<br></pre><br><p></p></div>

## Solution

c++
```c++
            // if any digit encounters we need to get the number by traversing the string.
            if(s[i]>='1' && s[i]<='9'){
                int temp = i;
                while(s[temp]!='[') temp++;
                //number starts from i and goes till temp-1
                int repeat = getRepeat(s,i,temp);
                
                int start = temp+1;
                int end = hash[temp];
                string subStr = decodePart(s,start,end);
                /**
                * input: (2[ac2[d]],2,8)
                * output: "acddacdd"
                */
                
                while(repeat--){
                    res.append(subStr);
                }
                
                // Start i after closing square bracket
                i = hash[temp];
            }else{
                res+=s[i];
            }
        }
        return res;
    }
    
    
    /**
    returns integer fron string
    */
    int getRepeat(string &s,int start,int end){
        string left (s.begin()+start,s.begin()+end);
        return stoi(left);
    }
};
​
```
