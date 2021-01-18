/*
	声明两个栈，插入时直接插入到s1栈上，删除时，如果s2不为空，则直接弹出s2的栈顶元素,
	否则先将s1中所有元素入栈s2中，然后再弹出栈顶元素。
*/

class CQueue {
public:
    stack<int> s1, s2;
    CQueue() {
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(!s1.size() && !s2.size()) return -1;
        if(!s2.size()) {
            while(s1.size()) {
                s2.push(s1.top()); s1.pop();
            }
        }
        
        int res = s2.top();
        s2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */