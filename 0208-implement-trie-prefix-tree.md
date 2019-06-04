---
tags: ["leetcode","design","trie"]
created: "04/06/2019, 11:51:41"
difficulty: "medium"
---

# [0208-implement-trie-prefix-tree](https://leetcode.com/problems/implement-trie-prefix-tree/)

## Problem
<div><p>Implement a trie with <code>insert</code>, <code>search</code>, and <code>startsWith</code> methods.</p><br><br><p><b>Example:</b></p><br><br><pre>Trie trie = new Trie();<br><br>trie.insert("apple");<br>trie.search("apple");   // returns true<br>trie.search("app");     // returns false<br>trie.startsWith("app"); // returns true<br>trie.insert("app");   <br>trie.search("app");     // returns true<br></pre><br><br><p><b>Note:</b></p><br><br><ul><br>	<li>You may assume that all inputs are consist of lowercase letters <code>a-z</code>.</li><br>	<li>All inputs are guaranteed to be non-empty strings.</li><br></ul><br></div>

## Solution

c++
```c++
class Trie {
    struct Node{
        int isTerminal;
        vector<Node*> v;
        Node(){
            isTerminal = false;
            v = vector<Node*>(26,nullptr);
        }
    };
    Node* nodes;
public:
    /** Initialize your data structure here. */
    Trie() {
        nodes = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertion(nodes,word,0);
    }
    
    void insertion(Node* node,string word, int idx){
        if(idx == word.size()){
            node->isTerminal = true;
            return ;
        }            
        int i = word[idx]-'a';
        if(!node->v[i]) node->v[i] = new Node();
        insertion(node->v[i],word,idx+1);        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searching(nodes,word,0);
    }
    
    bool searching(Node* node, string word,int idx){
        if(idx == word.size()){
            return node->isTerminal;
​
```
