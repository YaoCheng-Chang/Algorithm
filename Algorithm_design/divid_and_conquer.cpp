#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */

using namespace std;

//merge sort
void merge(vector<int> &arr,int left,int right,int mid){
    
    int ln=right-left+1;
    vector<int> x;
    int i=left, j=mid+1;
    for (int k=0;k<ln;k++){
        if(i>mid)
            x.push_back(arr[j++]);
        else if (j>right)
            x.push_back(arr[i++]);
        else if(arr[i]<arr[j]){
            x.push_back(arr[i]);
            i++;
        }
        else{
            x.push_back(arr[j]);
            j++;
        }
    }
    for (int k=0;k<ln;k++){
        arr[left+k]=x[k];
        
    }
    x.clear();
    // cout<<endl;
}
void dac(vector<int> &arr, int left,int right){
    if (left>=right){
        
        return;
    } 
    int mid=left+(right-left)/2;
    dac(arr, left, mid);
    dac(arr, mid+1, right);
    
    merge(arr,left,right,mid);
    
    

}
void merge_sort(vector<int> &arr){
    int n=arr.size();

    dac(arr, 0, n-1);
    cout<<"pass";
}


//quick sort
//交換的方式很重要，由小排到大，如果比pilot大，那原本的位置就要讓出給比較小的，使的小的與大的可以分堆
int partition(vector<int> &arr,int left,int right){
    int pilot=arr[right];
    int i=left;
    
    for(int j=left;j<right;++j){
        // cout<<"i:"<<i<<"j"<<j<<endl;
        if(arr[j]>pilot){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[i],arr[right]);

    return i;
}



void quicksort(vector<int> &arr, int left, int right){
    
    if(left>=right) return;
    //divid
    int k=partition(arr,left,right);
    //conquer
    quicksort(arr,left,k-1);
    quicksort(arr,k+1,right);

    //combine(X)
}
void quicksort(vector<int> &arr){
    quicksort(arr,0,arr.size()-1);
}

int main(){
    
    vector<int> arr={1,6,3,2,46,7,5};

    quicksort(arr); 
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;     
    
    return 0;
}