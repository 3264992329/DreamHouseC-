#include<stdio.h>
#define max_n 100
#define max_w 1000
int wt[max_n];
int ve[max_n];
int dp[max_n][max_w];
//�Ƚϴ�С,a>b�����a�������b 
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
	printf("��������:");
    scanf("%d",&W) ;
    
    printf("������Ʒ����:");
	scanf("%d",&n); 
    
    for(int i=0;i<n;i++){
    	printf("����ÿһ����Ʒ����:");
    	scanf("%d",&wt[i]);
	}
    
    for(int j=0;j<n;j++){
    	printf("����ÿһ����Ʒ��ֵ:");
    	scanf("%d",&ve[j]);
	}
	int max_value=bag(n,W,wt,ve);
	printf("�����п��Ի�õ�����ֵΪ��%d\n",max_value);
	return 0;
}
