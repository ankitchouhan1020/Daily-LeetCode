---
tags: ["leetcode","design"]
created: "26/05/2019, 17:35:14"
difficulty: "hard"
---

# [0146-lru-cache](https://leetcode.com/problems/lru-cache/)

## Problem
<div><p>Design and implement a data structure for <a href="https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU" target="_blank">Least Recently Used (LRU) cache</a>. It should support the following operations: <code>get</code> and <code>put</code>.</p><br><br><p><code>get(key)</code> - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.<br><br><code>put(key, value)</code> - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.</p><br><br><p>The cache is initialized with a <strong>positive</strong> capacity.</p><br><br><p><b>Follow up:</b><br><br>Could you do both operations in <b>O(1)</b> time complexity?</p><br><br><p><b>Example:</b></p><br><br><pre>LRUCache cache = new LRUCache( 2 /* capacity */ );<br><br>cache.put(1, 1);<br>cache.put(2, 2);<br>cache.get(1);       // returns 1<br>cache.put(3, 3);    // evicts key 2<br>cache.get(2);       // returns -1 (not found)<br>cache.put(4, 4);    // evicts key 1<br>cache.get(1);       // returns -1 (not found)<br>cache.get(3);       // returns 3<br>cache.get(4);       // returns 4<br></pre><br><br><p>&nbsp;</p></div>

## Solution

c++
```c++

class LRUCache {
    private:
    typedef list<int> LI;   //Contains KEy
    typedef pair<int,list<int>::iterator> PII; // Contains value and iterator to key in list
    typedef unordered_map<int,PII> HMIP;    // maps key to pair
    
    LI chain;
    HMIP hash;
    int _capacity;
    
    void touch(HMIP::iterator it){
        // it is iterator to hash hold {key,{valuee,keyIterator}}
        chain.erase(it->second.second);    //Removing key Node  holding address iterator from chain
        chain.push_front(it->first);    //Pushing key in front of list
        it->second.second = chain.begin(); // Chaning 
    }
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = hash.find(key);
        if(it != hash.end()){
            touch(it);
            return it->second.first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if(it != hash.end()){   //If key exit in hash then change its value
            touch(it);
            it->second.first = value;
            return ;
        }
        if(chain.size() == _capacity){
            int toDel = chain.back();   
            hash.erase(hash.find(toDel)); //delete entry in hash
            chain.pop_back();
        }
        if(chain.size() < _capacity){
            chain.push_front(key);
            hash[key] = {value,chain.begin()};
        }
    }
};
​
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
​
```
