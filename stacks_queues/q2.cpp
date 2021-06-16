//implementation of circular queue
#include<bits/stdc++.h>

using namespace std;

class Queue
{
    int size,front,rear,cnt;
    int *q;
    public:
        Queue(int s)
        {
            front = rear = 0;
            cnt = 0;
            size = s;
            q = new int[s];
        }

        void enqueue(int data)
        {
            if(cnt < size)
            {
                q[rear] = data;
                rear = (rear + 1)%size;
                cnt++;
                cout << "Done" <<endl;
            }
            else
            {
                cout << "Queue is full" << endl;
            }
        }

        void dequeue()
        {
            if(cnt > 0)
            {
                front = (front + 1)%size;
                cnt--;
                cout << "Done" <<endl;
            }
            else{
                cout << "Queue is empty" << endl;
            }
        }

        int top()
        {
            if(front != rear)
            {
                return q[front];
            }
            else
            {
                cout << "Queue is empty" << endl;
                return 0;
            }
        }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();q.dequeue();


}