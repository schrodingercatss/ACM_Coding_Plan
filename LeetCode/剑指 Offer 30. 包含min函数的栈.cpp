/*
	使用一个单调栈，记录一个非降序序列(可能最小值有多个），这样，如果插入的元素比栈顶元素小，则入栈，出栈时，因为后进先出，
	所以最小值一定在次小值之前出栈了。
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s, s1;
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(!s1.size() || s1.top() >= x) s1.push(x);
    }
    
    void pop() {
        if(s.top() == s1.top())
            s1.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return s1.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */