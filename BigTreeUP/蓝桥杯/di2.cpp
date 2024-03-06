#include<stdio.h>
#include<stdbool.h>

//����������� 
bool dfs(int N,int count,int time,int ti[],int di[],int li[],bool vs[]){
	if(count==N){
		return true;//�ɻ�������� 
	}else{
		for(int i=0;i<N;i++){
			if(ti[i]+di[i]>=time&&!vs[i]){
				vs[i]=true;//��ǰ�ɻ��ѽ��� 
				time = (time>=ti[i]?time:ti[i])+li[i];
				if(dfs(N,count+1,time,ti,di,li,vs)) {
					return true; 
				}
				vs[i]=false;	
			}
			
		}
		
	}
	return false;
} 

int main(){
	int T,N;
	// ������������������� T
	scanf("%d",&T); 
	for(int i=0;i<T;i++){
	//���� N,���������N��	
		scanf("%d",&N); 
		int ti[N],di[N],li[N];
		bool vs[N];
		for(int j=0;j<N;j++){
	//����ÿ������Ti(��i�ܷɻ�Tiʱ�̵�������Ͽ�),Di(������ʱ��),Li(������Ҫʱ��)
	    scanf("%d %d %d",&ti[j],&di[j],&li[j]);
	    vs[j]=false;
	    }
	   if(dfs(N,0,0,ti,di,li,vs)){
	   	printf("YES\n"); 
	   }else{
	   	printf("NO\n");
	   }
		
	}
	return 0; 
}
