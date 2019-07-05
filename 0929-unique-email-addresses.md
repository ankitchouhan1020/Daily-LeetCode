---
tags: ["leetcode","string"]
created: "06/07/2019, 00:47:23"
difficulty: "easy"
---

# [0929-unique-email-addresses](https://leetcode.com/problems/unique-email-addresses/)

## Problem
<div><p>Every email consists of a local name and a domain name, separated by the @ sign.</p><br><br><p>For example, in <code>alice@leetcode.com</code>,&nbsp;<code>alice</code> is the local name, and <code>leetcode.com</code> is the domain name.</p><br><br><p>Besides lowercase letters, these emails may contain <code>'.'</code>s or <code>'+'</code>s.</p><br><br><p>If you add periods (<code>'.'</code>) between some characters in the <strong>local name</strong> part of an email address, mail sent there will be forwarded to the same address without dots in the local name.&nbsp; For example, <code>"alice.z@leetcode.com"</code> and <code>"alicez@leetcode.com"</code> forward to the same email address.&nbsp; (Note that this rule does not apply for domain names.)</p><br><br><p>If you add a plus (<code>'+'</code>) in the <strong>local name</strong>, everything after the first plus sign will be&nbsp;<strong>ignored</strong>. This allows certain emails to be filtered, for example&nbsp;<code>m.y+name@email.com</code>&nbsp;will be forwarded to&nbsp;<code>my@email.com</code>.&nbsp; (Again, this rule does not apply for domain names.)</p><br><br><p>It is possible to use both of these rules at the same time.</p><br><br><p>Given a list of <code>emails</code>, we send one email to each address in the list.&nbsp;&nbsp;How many different addresses actually receive mails?&nbsp;</p><br><br><p>&nbsp;</p><br><br><div><br><p><strong>Example 1:</strong></p><br><br><pre><strong>Input: </strong><span id="example-input-1-1">["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]</span><br><strong>Output: </strong><span id="example-output-1">2</span><br><strong><span>Explanation:</span></strong><span>&nbsp;"</span><span id="example-input-1-1">testemail@leetcode.com" and "testemail@lee.tcode.com" </span>actually receive mails<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li><code>1 &lt;= emails[i].length&nbsp;&lt;= 100</code></li><br>	<li><code>1 &lt;= emails.length &lt;= 100</code></li><br>	<li>Each <code>emails[i]</code> contains exactly one <code>'@'</code> character.</li><br>	<li>All local and domain names are non-empty.</li><br>	<li>Local names do not start with a <code>'+'</code> character.</li><br></ul><br></div><br></div>

## Solution

c++
```c++
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        unordered_map<string,int> m;
        
        for(int i=0;i<n;i++){
            string &s = emails[i];
            m[purifyEmail(s)]++;
        }
        
        return m.size();        
    }
    
    string purifyEmail(string s){
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i] != '.' && s[i] != '+' && s[i]!='@') ans.push_back(s[i]);
            if(s[i] == '+'){
                while(i<s.size() && s[i]!='@')  i++;
                if(i == s.size()) break;
            }
            if(s[i] == '@'){
                ans += s.substr(i);
                break;
            }           
        }
        //cout<<ans<<endl;
        return ans;
    }
};
​
```
