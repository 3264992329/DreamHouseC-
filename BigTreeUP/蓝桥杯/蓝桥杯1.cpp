#include<stdio.h>
int main(){
	int n;
	int A,B;
	int v[99999];
	int vi[99999];
	int max,min;
//	printf("输入冶炼记录的数目N:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
//		printf("输入金属O的数目A,特殊金属X的数目B:");
	    scanf("%d %d",&A,&B);
	    v[i]=A/B;
	    vi[i]=A/(B+1)+1;
	}
	//求最大值 
	max=v[0];
	for(int j=0;j<n-1;j++){
	    	if(v[j+1]<max){
	    		max=v[j+1];
			}
		}
	//求最小值
	min=0;
	for(int i=0;i<n;i++){
		if(vi[i]>min){
			min=vi[i];
		}
	}
	
	printf("%d %d",min,max); 
}
