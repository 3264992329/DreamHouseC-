#include<stdio.h>
#include<stdbool.h> 
bool ok(int t,int a[][4],int x[]){//�ж��Ƿ���� 
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
	int m=3;//��ʾ3����ɫ 
	int n=4;//��ʾ4��ͼ 
	int a[][4]={{0,1,1,1},{1,0,1,0},{1,1,0,0},{1,0,0,0}};//Ϊ1��ʾ����;
	int t=1;//��ʾ��1��ͼ
	int s=backtrack(t,n,m,a);
	printf("һ����%d������",s); 
	return 0;
} 
