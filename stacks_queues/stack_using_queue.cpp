//implementation of stack using 2 queues
#include<bits/stdc++.h>

using namespace std;

class Stack
{
    queue <int> q1,q2;
    int size;
    public:
        Stack()
        {
            size = 0;
        }
        void push(int data)
        {
            q2.push(data);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> temp = q2;
            q2 = q1;
            q1 = temp;
            size++;
        }
        void pop()
        {
            if(q1.empty())
                cout << "Stack is empty" << endl;
            else
            {
                q1.pop();
                size--;
            }
        }
        int top(){
            if(q1.empty())
                return -1;
            return q1.front();
        }
};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    cout << s1.top();
}