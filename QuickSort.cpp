#include <iostream>
using namespace std;


int partition(int arr[],int start, int end){
    int i=start-1;
    int j=start;
    int pivot=arr[end];
    for(; j<end;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[end];
    arr[end]=temp;

    return i+1;
}

void quickSort(int arr[],int start ,int end){
    if(start>=end){
        return;
    }


    int p = partition(arr,start,end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
}


int main() {

    int arr[]= { 2, 1 ,20 ,15, 22 ,41, 9, 52, 0};
    int n= sizeof(arr)/ sizeof(int);
    quickSort(arr,0,n-1);

    cout<<"Sorted elements:"<<endl;

    for(int i=0;i<n; i++){

        cout<<arr[i]<<" ";
    }




    return 0;
}