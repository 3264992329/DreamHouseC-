#include<stdio.h>
#include<stdbool.h> 
bool ok(int t,int a[][4],int x[]){//判断是否可行 
	for(int j=0;j<4;j++){
		if(a[t][j]&&(x[t]==x[j])){return false;
		}else{
			return true;
		}
	}
} 

int backtrack(int t,int n,int m,int a[][4]){
	int sum=0; 
	int x[n];
	if(t>n) {
		sum++;
	}
	else{
		for(int i=1;i<=m;i++){
			x[t]=i;
			if(ok(t,a,x)){
				sum+=backtrack(t+1,n,m,a);
			}
		}
	}
	return sum;
}


int main(){
	int m=3;//表示3种颜色 
	int n=4;//表示4个图 
	int a[][4]={{0,1,1,1},{1,0,1,0},{1,1,0,0},{1,0,0,0}};//为1表示相邻;
	int t=1;//表示第1个图
	int s=backtrack(t,n,m,a);
	printf("一共有%d个方案",s); 
	return 0;
} 
