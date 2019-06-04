---
tags: ["leetcode","backtracking","trie"]
created: "04/06/2019, 11:51:48"
difficulty: "hard"
---

# [0212-word-search-ii](https://leetcode.com/problems/word-search-ii/)

## Problem
<div><p>Given a 2D board and a list of words from the dictionary, find all words in the board.</p><br><br><p>Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.</p><br><br><p>&nbsp;</p><br><br><p><strong>Example:</strong></p><br><br><pre><strong>Input:</strong> <br><b>board </b>= [<br>  ['<span style="color:#d70">o</span>','<span style="color:#d70">a</span>','a','n'],<br>  ['e','<span style="color:#d30">t</span>','<span style="color:#d00">a</span>','<span style="color:#d00">e</span>'],<br>  ['i','<span style="color:#d70">h</span>','k','r'],<br>  ['i','f','l','v']<br>]<br><b>words</b> = <code>["oath","pea","eat","rain"]</code><br><br><strong>Output:&nbsp;</strong><code>["eat","oath"]</code><br></pre><br><br><p>&nbsp;</p><br><br><p><b>Note:</b></p><br><br><ol><br>	<li>All inputs are consist of lowercase letters <code>a-z</code>.</li><br>	<li>The values of&nbsp;<code>words</code> are distinct.</li><br></ol><br></div>

## Solution

c++
```c++
// Need to be optimize
class TrieNode {
public:
    bool word;
    TrieNode* children[26];
    TrieNode() {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};
​
class WordDictionary {
public:
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node -> children[c - 'a']) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> word = true;
    }
    
    bool isSubstring(string word){
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            if(node -> children[word[i] - 'a'])
                node = node -> children[word[i] - 'a'];
            else return false;
        }
        return true;
    }
    
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word.c_str(), root);
    }
​
```
