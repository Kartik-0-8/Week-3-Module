#include<iostream>
#include<vector>
using namespace std;

//function for heapify
void heapify(vector<int> &arr,int n,int i){
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;

    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }

    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=i){
        int t;
        t=arr[i];
        arr[i]=arr[largest];
        arr[largest]=t;
        heapify(arr,n,largest);
    }
}

//function for heap sort
void heap_sort(vector<int> &arr,int n){

    //building max heap
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }

    //sorting the heap
    for(int i=n-1;i>0;i--){
        int t;
        t=arr[0];
        arr[0]=arr[i];
        arr[i]=t;
        heapify(arr,i,0);
    }
}

int main(){
    //input for total number of response times
    int n;
    cout<<"Enter the total number of response times: ";
    cin>>n;

    //vector for storing response times
    vector<int> arr;
    cout<<"Enter the response times: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    //calling heap sort
    heap_sort(arr,n);
    //printing sorted response times
    cout<<"Sorted Response Times -> ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nFastest: "<<arr[0];
    cout<<"\nSlowest: "<<arr[n-1];

    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }

    float avg=(float)sum/n;
    cout<<"\nAverage: "<<avg;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]<avg){
            count++;
        }
    }

    cout<<"\nCases Faster Than Average: "<<count;
    float per=((float)count/n)*100;
    cout<<"\nPercentage: "<<per<<"%";
    return 0;
}