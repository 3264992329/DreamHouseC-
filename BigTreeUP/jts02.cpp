/*
写个一个程序统计从1到N这N个数中，以下三个条件都满足的数字x个数
1. x是一个素数（如2,3,5,7....)
2. x是一个对称的数 (如1,11,121,都是对称的数)
3. x的所有数字和恰好是7的倍数(如7,16,25,34,43,61,70,115,)

输入：一个整数N(1<=N<=10000)
输出: 满足这三个条件的个数

样例输入:
20
样例输出
1

样例解释：
从1~20中素数有2,3,5,7,11,13,17,19，再结合条件2可以看到对称的数只有
2 3 5 7 11，又因为条件3，所以只有7满足要求，所以输出个数为1
*/
#include<stdio.h>
#include <math.h>

int pd(int a) {
	int r=0,t=a;
	while(t>0){
		r=r*10+t%10;
		t=t/10;
	}
	return (r==a);
}

int ss(int f) {
	int count=0;
	for(int i=1;i < f;i++){
		if(f%i==0){
			count++;
		}
	}
	if(count==2){
		return 1;
	}
	else{
		return 0;
	} 
}

int main() {
	int n;
	int count=0; 
	scanf("%d", &n);
	for (int i = 1; i <=n; i++) {
		if (i % 7 == 0&&pd(i)&&ss(i)) {
					count++;
					printf("%d ",i);	
		}
	}
	printf("\n");
	printf("一共有%d个",count);
	return 0;
}
