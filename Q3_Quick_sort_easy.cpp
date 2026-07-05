#include<iostream>
#include<vector>
using namespace std;

//function for partition
int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }

        while(arr[j]>pivot && j>low){
            j--;
        }

        if(i<j){
            int t;
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }

    int t;
    t=arr[low];
    arr[low]=arr[j];
    arr[j]=t;
    return j;
}

//function for quick sort
void quick_sort(vector<int> &arr,int low,int high){
    if(low<high){

        int p=partition(arr,low,high);
        quick_sort(arr,low,p-1);
        quick_sort(arr,p+1,high);
    }
}

int main(){
    //input for total number of servers
    int n;
    cout<<"Enter the total number of servers: ";
    cin>>n;

    //vector for storing response time
    vector<int> arr;
    cout<<"Enter the response times: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    //calling quick sort
    quick_sort(arr,0,n-1);
    //printing sorted response times
    cout<<"Sorted Response Times -> ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}