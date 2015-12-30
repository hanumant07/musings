/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/


/**
 * @constructor
 */
var Queue = function() {
    this.stack1 = [];
    this.stack2 = [];
};

/**
 * @param {number} x
 * @returns {void}
 */
Queue.prototype.push = function(x) {
    this.stack1.push(x);
};

/**
 * @returns {void}
 */
Queue.prototype.pop = function() {
    while(this.stack1.length > 0)
        this.stack2.push(this.stack1.pop());
    this.stack2.pop();
    while(this.stack2.length > 0)
        this.stack1.push(this.stack2.pop());
};

/**
 * @returns {number}
 */
Queue.prototype.peek = function() {
    while(this.stack1.length > 0)
        this.stack2.push(this.stack1.pop());
    var res = this.stack2[this.stack2.length -1];
    while(this.stack2.length > 0)
        this.stack1.push(this.stack2.pop());
    return res;
};

/**
 * @returns {boolean}
 */
Queue.prototype.empty = function() {
    if (this.stack1.length <= 0)
        return true;
    else 
        return false;
};

var q = new Queue();
q.push(1);
q.push(2);
console.log('peek is ' + q.peek());
