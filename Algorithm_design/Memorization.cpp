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

//預先建立記憶體，並填上記錄到記憶體裡for記憶體充足時
//stack
void stack_size(){
    stack<int> s;
    s.push(1);
    s.pop();
    cout<<s.size();
    
}
//hash table to count large range number string
void histogram(){
    vector<int> array={1,2,3,100045,2,5,21,1,1};

    map<int,int> c;
    for(int i=0;i<array.size();i++){
        c[array[i]]++;
    }
    for (auto i: c)
        cout<<i.first<<':'<<i.second<<'\n';

}

void counting_sort(){
    vector<int> array={1,224,500,100045,2,5,21,3,5,23,11,1};

    map<int,int> c;
    for(int i=0;i<array.size();i++){
        c[array[i]]++;
    }
    int index=0;
    for (auto i: c){
        for(int j=0;j<i.second;j++){
            array[index]=i.first;
            index++;
        }
    }
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    cout<<'\n';
}


int main(){
    cout<<"Hello"<<endl;
    counting_sort();
    return 0;
}
