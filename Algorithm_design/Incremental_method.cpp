//Selection sort
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */

using namespace std;


void Selection_sort(int array[],int n){
    // int n = sizeof(&array);不能用 因為此時array是指標的形式，因此長度是int的空間長度4 bytes
    // int n=6;
    // cout<<n<<endl;
    for(int i=0; i<n;i++){
        int minvalue=array[i];
        int minindex=i;
        for(int j=i+1;j<n;j++ ){
           if (array[j]<minvalue){
                minvalue=array[j];
                minindex=j;
           }
           else; 
        }
        swap(array[i],array[minindex]);

    }
}

void draw_triangle(const int* n){
    for (int i=0;i<*n;i++){
        for (int j=0;j<(*n-i);j++){
            cout<<"@ ";
        }
        cout<<endl;
    }
}

//maxguest and maxguest in what time
const int num=6;
struct Guest{int arrival, leave;};

bool cmp(int i, int j){
    return abs(i)<abs(j); 
}

void cnt_maxguest(Guest g[]){
    vector<int> time;
    for (int i=0;i<num;i++){
        time.push_back(+g[i].arrival);
        time.push_back(-g[i].leave);
    }
    sort(time.begin(),time.end(),cmp);
    
    int n=(time[0]>0), maximum=0,max_time=0;
    for(int i=1;i<time.size();i++){
        
        if ((abs(time[i])!=abs(time[i-1]))&&(n>maximum)){
            cout<<max_time<<endl;
            maximum=n;
            max_time=abs(time[i-1]);}

        if (time[i]>=0) n++;
        else n--;
        
    }
    cout<<"The maximum number: "<<maximum<<endl;
    cout<<"The time has maximum people: "<<max_time<<endl;
}



int main(){
    //
    /*int arr[]={3,2,4,1,5,6};
    Selection_sort(arr,sizeof(arr)/sizeof(int));
    cout<<"pass"<<endl;
    for (int i=0;i<sizeof(arr)/sizeof(int);i++)
        cout<<arr[i];
    */
    // draw triangle
    /*const int k=6;
    draw_triangle(&k);
    */
    //find maximum 人潮
    srand(time(NULL));
    Guest g[num];
    for (int i=0;i<num;i++){
        g[i].arrival=(rand()%5+1);
        do{
            g[i].leave=rand()%6+1;
        }while(g[i].leave<=g[i].arrival);
        cout<<g[i].arrival<<"||"<<g[i].leave<<endl;
    }
    cnt_maxguest(g);

}