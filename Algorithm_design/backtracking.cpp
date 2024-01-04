#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */

#include <queue>

using namespace std;

bool solution[5];	// 索引儲存

void backtrack(int n)
{
	cout<<"num: "<<n<<endl;
    // 製作了其中一個答案
	if (n == 5)
	{
		for (int i=0; i<5; i++)
			if (solution[i])
				cout << i << ' ';
		cout << endl;
		return;
	}

	// 選取數字n，然後繼續枚舉之後的位置。
	solution[n] = true;
	backtrack(n+1);

	// 不取數字n，然後繼續枚舉之後的位置。
	solution[n] = false;
	backtrack(n+1);
}

// void enumerate_combinations()
// {
// 	backtrack(0);
// }

//按順序枚舉數字
// int arrays[5] = {6, 7, 9, 4, 2};
// int subset[5];	// 循序儲存

// void print_solution(int arr[],int *n){
//     for(int i=0;i<*n;i++){
        
//         cout<<arr[i]<<' ';
//     }
//     cout<<endl;
// }

// void backtrack(int n, int size)	// size是子集合大小
// {
// 	print_solution(subset,&size);

// 	for (; n<5; ++n)
// 	{
// 		// 選取數字array[n]
// 		subset[size] = arrays[n];

// 		// 然後繼續枚舉剩下的數字
// 		backtrack(n+1, size+1);
// 	}
// }

// void enumerate_combinations()
// {
// 	sort(arrays, arrays+5);
// 	backtrack(0, 0);
// }


//enumeration subset sum
const int N = 5;
const int K = 6;
int arrays[N] = {2, 4, 6, 7, 9};

struct Pair {int n, num;};

bool operator<(Pair a, Pair b)
{
	return a.num > b.num;
}

void enumerate_subset_sums()
{
	cout << 0;

	// 預先補入一個數，稍後再扣除回來。
	priority_queue<Pair> pq;
	pq.push({0, arrays[0]});

	for (int k=1; k<K; k++)
	{
		if (pq.empty()) break;
		int n = pq.top().n;
		int num = pq.top().num;
		pq.pop();

		cout << num<<endl;

		if (n + 1 < N)
		{
			// 取
			pq.push({n+1, num + arrays[n+1]});
			// 不取
			pq.push({n+1, num - arrays[n] + arrays[n+1]});
		}
	}
}

int main(){
    // enumerate_combinations();
    enumerate_subset_sums();
    return 0;
}