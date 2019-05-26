---
tags: ["leetcode","heap","design"]
created: "26/05/2019, 17:35:55"
difficulty: "hard"
---

# [0295-find-median-from-data-stream](https://leetcode.com/problems/find-median-from-data-stream/)

## Problem
<div><p>Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.</p><br>For example,<br><br><p><code>[2,3,4]</code>, the median is <code>3</code></p><br><br><p><code>[2,3]</code>, the median is <code>(2 + 3) / 2 = 2.5</code></p><br><br><p>Design a data structure that supports the following two operations:</p><br><br><ul><br>	<li>void addNum(int num) - Add a integer number from the data stream to the data structure.</li><br>	<li>double findMedian() - Return the median of all elements so far.</li><br></ul><br><br><p>&nbsp;</p><br><br><p><strong>Example:</strong></p><br><br><pre>addNum(1)<br>addNum(2)<br>findMedian() -&gt; 1.5<br>addNum(3) <br>findMedian() -&gt; 2<br></pre><br><br><p>&nbsp;</p><br><br><p><strong>Follow up:</strong></p><br><br><ol><br>	<li>If all integer numbers from the stream are between 0&nbsp;and 100, how would you optimize it?</li><br>	<li>If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?</li><br></ol><br></div>

## Solution

c++
```c++
// Two heap solution
class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        
        if(max_heap.size() < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
         }
    }
    
    double findMedian() {        
        if(max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top())/2.0;
        return max_heap.top();
    }
};
​
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
​
```
