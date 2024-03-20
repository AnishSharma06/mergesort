// implementing merge sort ->It uses divide and conquer property first it will divide it into further subparts and then after that it will sort them and after it join them so that the resulting component gives us the sorted array
#include<iostream>
#include<vector>
using namespace std;
void merging(int *arr,int start,int mid,int end){
    int i=start;
    int j=mid+1;
    int k=start;
    vector<int>ans;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        ans.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        ans.push_back(arr[j]);
        j++;
    }
 for (int x = 0; x < ans.size(); x++) {
        arr[start + x] = ans[x];
    }
}
void merge(int *arr,int start,int end){
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    merge(arr,start,mid);
    merge(arr,mid+1,end);
    merging(arr,start,mid,end);
}
int main(){
    int arr[]={12,11,10,9,8,7,6,5,4,3,2,1,5};
    merge(arr,0,12);
    for(auto a:arr){
        cout<<a<<" ";
    }
}
