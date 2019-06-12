---
tags: ["leetcode","union find","graph"]
created: "12/06/2019, 17:19:27"
difficulty: "medium"
---

# [0399-evaluate-division](https://leetcode.com/problems/evaluate-division/)

## Problem
<div><p>Equations are given in the format <code>A / B = k</code>, where <code>A</code> and <code>B</code> are variables represented as strings, and <code>k</code> is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return <code>-1.0</code>.</p><br><br><p><b>Example:</b><br><br>Given <code> a / b = 2.0, b / c = 3.0.</code><br><br>queries are: <code> a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .</code><br><br>return <code> [6.0, 0.5, -1.0, 1.0, -1.0 ].</code></p><br><br><p>The input is: <code> vector&lt;pair&lt;string, string&gt;&gt; equations, vector&lt;double&gt;&amp; values, vector&lt;pair&lt;string, string&gt;&gt; queries </code>, where <code>equations.size() == values.size()</code>, and the values are positive. This represents the equations. Return <code> vector&lt;double&gt;</code>.</p><br><br><p>According to the example above:</p><br><br><pre>equations = [ ["a", "b"], ["b", "c"] ],<br>values = [2.0, 3.0],<br>queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. </pre><br><br><p>&nbsp;</p><br><br><p>The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.</p><br></div>

## Solution

c++
```c++
typedef unordered_map<string,double> innerMap;
typedef unordered_map<string,bool> searchMap;
typedef unordered_map<string,innerMap> upperMap;
​
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& values, vector<vector<string>>& q) {
        upperMap list;
        vector<double>ans(q.size());
        for(int i=0;i<e.size();i++){
            if(list.count(e[i][0])==0){
                list.insert({e[i][0],innerMap()});
            }
            list[e[i][0]].insert({e[i][1],values[i]});
            if(list.count(e[i][1])==0){
                list.insert({e[i][0],innerMap()});
            }
            list[e[i][1]].insert({e[i][0],1.0/values[i]});
        }
        
        for(int i=0;i<q.size();i++){
            string up = q[i][0];
            string down = q[i][1];
            if(list.count(up)==0 || list.count(down)==0){
                ans[i] = -1.0;
            }
            else if(up==down){
                ans[i] = 1.0;
            }
            else if(list[up].find(down) != list[up].end()){
                ans[i] = list[up][down];
            }
            else if(list[down].find(up) != list[down].end()){
                ans[i] = 1.0/list[up][down];
            }
            else{
                unordered_set<string> s;
                ans[i] = solveQuery(list,up,down,s);
                if(ans[i] == 0) ans[i]=-1.0;
            }
        }
        return ans;
    }
    
    double solveQuery(upperMap &list,string up,string down,unordered_set<string> &s){
        if(list[up].find(down) != list[up].end()) return list[up][down];
        
        for(auto i: list[up]){
            if(s.find(i.first) == s.end()){
                s.insert(i.first);
                
                double tmp = solveQuery(list,i.first,down,s);
​
```
