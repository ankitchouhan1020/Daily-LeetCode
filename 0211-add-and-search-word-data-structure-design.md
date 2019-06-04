---
tags: ["leetcode","backtracking","design","trie"]
created: "04/06/2019, 11:51:44"
difficulty: "medium"
---

# [0211-add-and-search-word-data-structure-design](https://leetcode.com/problems/add-and-search-word-data-structure-design/)

## Problem
<div><p>Design a data structure that supports the following two operations:</p><br><br><pre>void addWord(word)<br>bool search(word)<br></pre><br><br><p>search(word) can search a literal word or a regular expression string containing only letters <code>a-z</code> or <code>.</code>. A <code>.</code> means it can represent any one letter.</p><br><br><p><strong>Example:</strong></p><br><br><pre>addWord("bad")<br>addWord("dad")<br>addWord("mad")<br>search("pad") -&gt; false<br>search("bad") -&gt; true<br>search(".ad") -&gt; true<br>search("b..") -&gt; true<br></pre><br><br><p><b>Note:</b><br><br>You may assume that all words are consist of lowercase letters <code>a-z</code>.</p><br></div>

## Solution

c++
```c++
// Inspired from @jianchao-li
​
class TrieNode{
    public:
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(): isTerminal(false){
        memset(children, NULL, sizeof(TrieNode*)*26);
    }
};
​
​
class WordDictionary {
public:
    TrieNode* root = new TrieNode();
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int pos = word[i] - 'a';
            if(node->children[pos] == nullptr){
                node->children[pos] = new TrieNode();
            }
            node = node->children[pos];
        }
        node->isTerminal = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searching(word,root);
    }
    
​
```
