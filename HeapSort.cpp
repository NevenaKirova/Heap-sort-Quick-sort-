#include <iostream>
using namespace std;

void maxHeap(int heap[], int n , int size){

    int largest=n;
    int left=2*n;
    int right=2*n+1;

    if (left<=size && heap[n]< heap[left]){

        largest=left;
    }

    if(right<=size && heap[largest]<heap[right]){

        largest=right;
    }

    if(largest!=n){

        int temp=heap[largest];
        heap[largest]=heap[n];
        heap[n]=temp;
        maxHeap(heap,largest,size);

    }


 }

 void buildHeap(int heap[],int size ) {

    for(int i=size/2;i>=1;i--){

        maxHeap(heap,i,size);

    }


}


int main(){

    int size;

    cout<<"How many elements do you want to sort?"<<endl;
    cin>>size;

    int heap[size+1];

    cout<<"Enter elements"<<endl;

    for(int i=1;i<=size;i++){

        cin>>heap[i];

    }

    buildHeap(heap,size);

    int heapSize=size;

    for(int i=size;i>=2;i--){

        int temp=heap[1];
        heap[1]=heap[i];
        heap[i]=temp;
        --heapSize;
        maxHeap(heap,1,heapSize);
    }

    cout<<"Sorted elements: " <<endl;

    for(int i=1;i<=size;i++){

        cout<<heap[i]<<" ";
    }


    return 0;


}
