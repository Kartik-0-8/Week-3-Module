#include<iostream>
#include<vector>
using namespace std;

//function for merging
void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high){

        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }

        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

//function for merge sort
void merge_sort(vector<int> &arr,int low,int high){
    if(low>=high){
        return;
    }

    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);

    merge(arr,low,mid,high);
}

int main(){
    //input for total number of processing times
    int n;
    cout<<"Enter the total number of processing times: ";
    cin>>n;

    //vector for storing processing times
    vector<int> arr;
    cout<<"Enter the processing times: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    //calling merge sort
    merge_sort(arr,0,n-1);

    //printing sorted processing times
    cout<<"Sorted Processing Times -> ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    //finding median
    int median;
    if(n%2==0){
        median=(arr[n/2]+arr[(n/2)-1])/2;
    }
    else{
        median=arr[n/2];
    }

    cout<<"Median: "<<median<<endl;
    //counting orders greater than median
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>median){
            count++;
        }
    }
    cout<<"Orders Above Median: "<<count<<endl;

    //difference between maximum and minimum
    int diff=arr[n-1]-arr[0];
    cout<<"Difference: "<<diff;
    return 0;
}