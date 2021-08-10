// Implementing heap basic operations

#include<bits/stdc++.h>
using namespace std;

class Max_Heap{
    int *arr;
    int max_size;
    int heap_size;

    public:
        int parent(int i){
            return (i-1)/2;
        }
        int left_child(int i){
            return 2*i + 1;
        }
        int right_child(int i){
            return 2*i + 2;
        }

        void swap(int *x,int *y)
        {
            int temp = *x;
            *x = *y;
            *y = temp; 
        }
        
        Max_Heap(int max_size)
        {
            heap_size = 0;
            max_size = max_size;
            arr = new int[max_size];
        }

        void insert_key(int k)
        {
            if(max_size == heap_size){
                cout << "Heap already full\n";
                return;
            }
            heap_size++;
            int i(heap_size-1);
            arr[i] = k;

            while(i>0 && (arr[i] > arr[parent(i)])){
                swap(&arr[i],&arr[parent(i)]);
                i = parent(i);
            }

        }

        int delete_key() // this function always deletes the root node of heap
        {
            if(heap_size == 0){
                cout << "Heap is already  empty\n";
                return -1;
            }
            if(heap_size == 1){
                heap_size--;
                return arr[0];
            }

            int max = arr[0];
            int x(arr[heap_size-1]);
            arr[0] = x;
            arr[heap_size-1] = max;
            int i(0),j(left_child(i));
            heap_size--;

            while (j <= heap_size-1)
            {
                if(j < heap_size-1)
                {
                    if(arr[j] < arr[j+1])
                    j = j+1;
                }
                
                if(arr[i] < arr[j])
                {
                    swap(&arr[i],&arr[j]);
                    i = j;
                    j = left_child(i);
                }
                else
                    break;
            }

            return max;
        }

        void display_heap_array_form()
        {
            for(int i=0;i<heap_size;i++)
                cout << arr[i] << " ";
        }
};

int main()
{
    Max_Heap heap(10);
    heap.insert_key(20);
    heap.insert_key(9);
    heap.insert_key(10);
    heap.insert_key(4);
    heap.insert_key(6);
    heap.insert_key(5);
    heap.insert_key(8);
    heap.insert_key(25);

    cout << "The max element is " << heap.delete_key() << "\n";

    heap.display_heap_array_form();

}