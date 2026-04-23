#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index >1){
            int parent = index/2;
            if(arr[parent] <arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }

    }

    void deletefromHeap() {
        if (size == 0) return; // Cannot delete from empty heap

        // 1. Replace root with last element
        arr[1] = arr[size];
        size--;

        // 2. Propagate the element down to its correct position
        int i = 1;
        while (true) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i;

            // Check if left child exists and is larger than current
            if (leftIndex <= size && arr[leftIndex] > arr[largest]) {
                largest = leftIndex;
            }

            // Check if right child exists and is larger than the largest so far
            if (rightIndex <= size && arr[rightIndex] > arr[largest]) {
                largest = rightIndex;
            }

            // If the largest is still i, the heap property is restored
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    void findMax(){
        cout<<arr[1]<<endl;
    }
    

    void print(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap H;
    H.insert(10);
    H.insert(14);
    H.insert(11);
    H.insert(20);
    H.insert(18);
    H.insert(17);
    H.insert(15);
    H.insert(13);
    H.insert(12);
    H.deletefromHeap();
    H.print();
}
