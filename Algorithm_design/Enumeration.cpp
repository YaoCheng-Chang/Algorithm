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

//枚舉法
//找二維陣列的數字
bool find_number(int n){
    vector<vector<int>> arr={
        {3, 6, 9, -8, 1},
		{2, 4, 6, 8, 10},
		{11, 7, 5, 3, 2}};

    for (int i=0;i<arr.size();i++){
        for (int j=0;j<arr[i].size();j++){
            if(arr[i][j]==n)
                return true;
        }
    return false;
    }
}


//字串搜尋
void string_searching(){
    string text = "It's a pencil.";
	string pattern = "a pen";
    
    for (int i=0; i<(text.size()-pattern.size()+1);i++){
        bool check=true;
        for(int j=0;j<pattern.size();j++){
            if (text[i+j]!=pattern[j]){
                check=false;
                break;
            }
        }
        if (check){
            cout<<"the index="<<i<<endl;
        }
    }
}


//find minimum and sort
vector<int> sort(vector<int> arr){
    vector<int> sort_arr;
    map<int,int> count;
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }
    int index=0;
    for(auto i: count){
        for(int j=0;j<i.second;j++){
            sort_arr.push_back(i.first);
            index++;
        }
    }
    return sort_arr;
}


int main(){
    // int num;
    // cin>>num;
    // cout<<find_number(num)<<endl;
    // string_searching();
    vector<int> arr={1,2,4,5,2,35,5,2,1,2424,6};
    vector<int> sort_arr=sort(arr);
    for (int i=0;i<arr.size();i++)
        cout<<sort_arr[i]<<' ';
    cout<<endl;
    return 0;
}