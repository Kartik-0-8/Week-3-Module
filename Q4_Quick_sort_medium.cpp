#include<iostream>
#include<vector>
using namespace std;

//function for partition
int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){

        while(arr[i]>=pivot && i<high){
            i++;
        }

        while(arr[j]<pivot && j>low){
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
    //input for total number of trade values
    int n;
    cout<<"Enter the total number of trade values: ";
    cin>>n;

    //vector for storing trade values
    vector<int> arr;
    cout<<"Enter the trade values: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    //calling quick sort
    quick_sort(arr,0,n-1);
    //printing sorted trade values
    cout<<"Sorted Trade Values -> ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<"\nTop 5 Values -> ";
    int sum=0;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
        sum=sum+arr[i];
    }

    float avg_top5=(float)sum/5;
    cout<<"\nAverage of Top 5: "<<avg_top5;
    int total=0;
    for(int i=0;i<n;i++){
        total=total+arr[i];
    }

    float overall_avg=(float)total/n;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>overall_avg){
            count++;
        }
    }
    cout<<"\nValues Above Overall Average: "<<count;
    return 0;
}