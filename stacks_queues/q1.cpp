//implementation of queue using arrays
#include<bits/stdc++.h>
using namespace std;

class Queue
{
    int front,rear,size;
    int *q;
    public:
        Queue(int n)
        {
            front = rear = -1;
            size = n;
            q = new int[n];
        }
        ~Queue()
        {
            delete [] q;
        }

        void enqueue(int data)
        {
            if(rear == size-1)
            {
                cout << "Queue is full" << endl;
                return;
            }
            q[++rear] = data;
            cout << data << " is inserted" << endl;
        }
        void dequeue()
        {
            if(front == rear)
            {
                cout << "Queue is empty" << endl;
                return;
            }
            front++;
        }
        int top()
        {
            if(front == rear)
            {
                cout << "Queue is empty" << endl;
                return 0;
            } 
            return q[front+1];
        }
};

int main()
{
    Queue q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();



}