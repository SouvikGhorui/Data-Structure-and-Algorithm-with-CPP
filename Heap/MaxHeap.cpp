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

    void deletefromHeap(){
        arr[1] = arr[size];
        size--;

        // take the value to its correct location
        int i = 1;
        while(i<size){
            int Leftsize = 2*i;
            int Rightsize = 2*i+1;
            if(arr[Leftsize]>arr[i] && Leftsize <size){
                swap(arr[i], arr[Leftsize]);
                i = Leftsize;
            }
            else if( arr[Rightsize] > arr[i] && Rightsize < size){
                swap(arr[i], arr[Rightsize]);
                i = Rightsize;
            }
            else{
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
