/*问题描述
　　给定一个序列 a[1], a[2], …, a[n] 和一个整数 k，请找出一个长度正好为 k 的区间，使得区间中所有数的和最大。
　　即要找到一个整数 p ，使得 1 <= p 且 p+k-1 <= n ，使得 a[p]+a[p+1]+...+a[p+k-1] 最大。
输入格式
　　输入的第一行包含两个整数 n , k。
　　第二行包含 n 个整数，相邻的整数之间使用一个空格分隔，表示给定的序列。
输出格式
　　输出一行包含一个整数，表示最大的区间和，你只需要输出和就行，不需要输出方案。
样例输入
6 3
2 3 9 1 9 5
样例输出
19
评测用例规模与约定
　　对于 30% 的评测用例，1 <= k <= n <= 30，1 <= a[i] <= 100。
　　对于 60% 的评测用例，1 <= k <= n <= 1000，1 <= a[i] <= 10000。
　　对于所有评测用例，1 <= k <= n <= 100000，1 <= a[i] <= 1000000。*/
#include<stdio.h>

int main(){
	int n,k; 
	int a[100000];
	scanf("%d %d",&n,&k);
	
	int i=0; 
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	int s=0;
	for(int i=0;i<n-k+1;i++){
		int all=0;
		for(int j=i;j<k+i;j++){
			all=all+a[j];
		}
		if(all>s){
			s=all;
		}
	}
	printf("%d",s);
	return 0;
}
