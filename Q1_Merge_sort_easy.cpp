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

    //input for total number of placed students
    int n;
    cout<<"Enter the total number of placed students: ";
    cin>>n;

    //vector for storing package values
    vector<int> arr;

    cout<<"Enter the package values: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    //calling merge sort
    merge_sort(arr,0,n-1);

    cout<<"Sorted Package Values -> ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}