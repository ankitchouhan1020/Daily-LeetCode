---
tags: ["leetcode","array","hash table","design"]
created: "30/05/2019, 22:43:20"
difficulty: "medium"
---

# [0380-insert-delete-getrandom-o1](https://leetcode.com/problems/insert-delete-getrandom-o1/)

## Problem
<div><p>Design a data structure that supports all following operations in <i>average</i> <b>O(1)</b> time.</p><br><br><p><br></p><ol><br><li><code>insert(val)</code>: Inserts an item val to the set if not already present.</li><br><li><code>remove(val)</code>: Removes an item val from the set if present.</li><br><li><code>getRandom</code>: Returns a random element from current set of elements. Each element must have the <b>same probability</b> of being returned.</li><br></ol><br><p></p><br><br><p><b>Example:</b><br></p><pre>// Init an empty set.<br>RandomizedSet randomSet = new RandomizedSet();<br><br>// Inserts 1 to the set. Returns true as 1 was inserted successfully.<br>randomSet.insert(1);<br><br>// Returns false as 2 does not exist in the set.<br>randomSet.remove(2);<br><br>// Inserts 2 to the set, returns true. Set now contains [1,2].<br>randomSet.insert(2);<br><br>// getRandom should return either 1 or 2 randomly.<br>randomSet.getRandom();<br><br>// Removes 1 from the set, returns true. Set now contains [2].<br>randomSet.remove(1);<br><br>// 2 was already in the set, so return false.<br>randomSet.insert(2);<br><br>// Since 2 is the only number in the set, getRandom always return 2.<br>randomSet.getRandom();<br></pre><br><p></p></div>

## Solution

c++
```c++

class RandomizedSet {
    unordered_map<int,int> m;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val)==1) return false;
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.count(val)==0) return false;
        int i = m[val];
        swap(v[i],v[v.size()-1]);
        m[v[i]] = i;
        m.erase(val);
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size = m.size();
        if(size == 0) return -1;
        int idx = rand()%size;
        return v[idx];
    }
};
​
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
​
```
