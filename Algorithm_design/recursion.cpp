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

//質因數分解
void prime_divid(int num){
    for (int i=2;i<=num/2;i++){
        if(num%i==0){
            cout<<i<<",";
            prime_divid(num/i);
            break;
        }
        else if(i==num/2){
            cout<<num<<endl;
        }
    }
}

//河內塔
int count_steps(int num){
    if(num==0) return 0;
    return count_steps(num-1)*2+1;
}
void show_move(int n,int s,int t){
    if(n==0) return;
    show_move(n-1,s,6-t-s);
    cout<<"from "<<s<<"to "<<t<<endl;
    show_move(n-1,6-s-t,t);
}
//帕斯卡三角形
int pascal(int n, int k) {
    if(k == 0 || n == k)
        return 1;
    return pascal(n-1, k-1) + pascal(n-1, k);
}


int main(){
    // prime_divid(145);
    
    // cout<<"honet tower steps:"<< count_steps(3)<<endl;
    // show_move(3,1,3);

    // int i, j, n = 16;
    // puts("Row  Column");
    // for(i = 0; i <= n; i++) {
    //     cout<<i+1;
    //     if(i+1 >= 10)   goto pspace;
    //     cout<<" ";
    //     pspace:
    //         cout<<"   ";
    //     for(j = 0; j <= i; j++)
    //         cout<<" "<<pascal(i, j);
    //     puts("");
    // }
    return 0;

}