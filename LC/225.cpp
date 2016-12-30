class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
        q2.push(x);
        if(q2.size() > 1){
            q2.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q1.size() == 0){

        }
        else if(q1.size() == 1){
            q1.pop();
            q2.pop();
        }
        else{
            for(int i=1; i<= q1.size()-2; i++){
                q1.push(q1.front());
                q1.pop();
            }
            q2.push(q1.front());
            q2.pop();
            q1.push(q1.front());
            q1.pop();
            q1.pop();
        }
    }

    // Get the top element.
    int top() {
        return q2.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return !q1.size();
    }

private:
queue<int> q1, q2;
};
