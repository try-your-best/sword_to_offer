#include<iostream>
#include <stack>
//#include <exception>
#include <stdexcept>

using namespace std;

template <typename T> class CQueue{
public:
    CQueue(){};
    ~CQueue(){};    
    // 在队列末尾添加一个结点
    void appendTail(const T& node);
    // 删除队列的头结点
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> void CQueue<T> :: appendTail(const T& node){
    stack1.push(node);
}

template <typename T> T CQueue<T> :: deleteHead(){
    if(stack2.empty()){
        while(stack1.size() > 0){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if(stack2.empty()){
        runtime_error("queue is empty");
        //throw new exception("queue is empty");
        cout <<"queue is empty"<<endl; 
        return 0;
    }
    T head = stack2.top();
    stack2.pop();
    return head;
}


int main(){
    CQueue<int> q1;
    q1.appendTail(1);
    q1.appendTail(2);
    q1.appendTail(3);
    for(int i = 0; i < 3; i++){
        cout << q1.deleteHead() << endl;
    }
    return 0; 
}
