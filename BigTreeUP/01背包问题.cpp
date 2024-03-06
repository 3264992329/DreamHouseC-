#include<stdio.h>
#define max_n 100
#define max_w 1000
int wt[max_n];
int ve[max_n];
int dp[max_n][max_w];
//比较大小,a>b就输出a否则输出b 
int max(int a,int b){
	return (a>b)?a:b;
}
int bag(int n,int W,int wt[],int ve[]){
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(i==0||W==0){
				dp[i][w]=0;
			}
			else if(wt[i]<=W){
				dp[i][w]=max(dp[i-1][w-wt[i]]+ve[i],dp[i-1][w]);
			}
			else{
				dp[i][w]=dp[i-1][w];
			}
		}
	}
	return dp[n][W];
}
int main(){
	int W,n; 
	printf("输入容量:");
    scanf("%d",&W) ;
    
    printf("输入物品数量:");
	scanf("%d",&n); 
    
    for(int i=0;i<n;i++){
    	printf("输入每一个物品重量:");
    	scanf("%d",&wt[i]);
	}
    
    for(int j=0;j<n;j++){
    	printf("输入每一个物品价值:");
    	scanf("%d",&ve[j]);
	}
	int max_value=bag(n,W,wt,ve);
	printf("背包中可以获得的最大价值为：%d\n",max_value);
	return 0;
}
