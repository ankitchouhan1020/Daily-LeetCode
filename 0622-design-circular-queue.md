---
tags: ["leetcode","design","queue"]
created: "26/05/2019, 17:10:46"
difficulty: "medium"
---

# [0622-design-circular-queue](https://leetcode.com/problems/design-circular-queue/)

## Problem
<div><p>Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".</p><br><br><p>One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.</p><br><br><p>Your implementation should support following operations:</p><br><br><ul><br>	<li><code>MyCircularQueue(k)</code>: Constructor, set the size of the queue to be k.</li><br>	<li><code>Front</code>: Get the front item from the queue. If the queue is empty, return -1.</li><br>	<li><code>Rear</code>: Get the last item from the queue. If the queue is empty, return -1.</li><br>	<li><code>enQueue(value)</code>: Insert an element into the circular queue. Return true if the operation is successful.</li><br>	<li><code>deQueue()</code>: Delete an element from the circular queue. Return true if the operation is successful.</li><br>	<li><code>isEmpty()</code>: Checks whether the circular queue is empty or not.</li><br>	<li><code>isFull()</code>: Checks whether the circular queue is full or not.</li><br></ul><br><br><p>&nbsp;</p><br><br><p><strong>Example:</strong></p><br><br><pre>MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3<br>circularQueue.enQueue(1); &nbsp;// return true<br>circularQueue.enQueue(2); &nbsp;// return true<br>circularQueue.enQueue(3); &nbsp;// return true<br>circularQueue.enQueue(4); &nbsp;// return false, the queue is full<br>circularQueue.Rear(); &nbsp;// return 3<br>circularQueue.isFull(); &nbsp;// return true<br>circularQueue.deQueue(); &nbsp;// return true<br>circularQueue.enQueue(4); &nbsp;// return true<br>circularQueue.Rear(); &nbsp;// return 4<br></pre><br>&nbsp;<br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>All values will be in the range of [0, 1000].</li><br>	<li>The number of operations will be in the range of&nbsp;[1, 1000].</li><br>	<li>Please do not use the built-in Queue library.</li><br></ul><br></div>

## Solution

c++
```c++

class MyCircularQueue {
    private:
        vector<int> data;
        int front,rear,qSize;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        qSize = k;
        for(int i=0;i<k;i++) data.push_back(0);
        front=rear=-1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        if(rear==-1) front=0;
        rear = (rear+1)%qSize;
        data[rear] = value;
        return true;        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        if(front==rear){
            front=rear=-1;
            return true;
        }
        front = (front+1)%qSize;
        return true;      
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return data[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return data[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front==-1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (front==(rear+1)%qSize);
    }
};
​
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
​
```
