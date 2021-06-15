//implementation of stack using array
#include<bits/stdc++.h>
#define MAX 10000

using namespace std;

class Stack
{
    int top;
    public:
        int a[MAX];
        Stack(){
            top = -1;
        }
        bool push(int x)
        {
            if(top == MAX-1){
                cout << "Stack overflow" << endl;
                return false;
            }
            a[++top] = x;
            cout << x << " pushed into stack" << endl;
            return true;
        }
        int pop()
        {
            if(top < 0)
            {
                cout << "Stack underflow" << endl;
                return 0;
            }
            else
            {
                int x(a[top]);
                top--;
                return x;
            }
        }
        int peep()
        {
            if(top < 0)
            {
                cout << "Stack is empty" << endl;
                return 0;
            }
            int x = a[top];
            return x;
        }
        bool isEmpty()
        {
            return top<0;
        }
};

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    cout << "The top element is :" << s1.peep()  << endl;
    s1.pop();s1.pop();
    if(s1.isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Not empty" << endl;
}