#include<stdio.h>
#include<stdbool.h>

//深度优先搜索 
bool dfs(int N,int count,int time,int ti[],int di[],int li[],bool vs[]){
	if(count==N){
		return true;//飞机降落完毕 
	}else{
		for(int i=0;i<N;i++){
			if(ti[i]+di[i]>=time&&!vs[i]){
				vs[i]=true;//当前飞机已降落 
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
	// 输入整数代表测试组数 T
	scanf("%d",&T); 
	for(int i=0;i<T;i++){
	//输入 N,代表该组有N行	
		scanf("%d",&N); 
		int ti[N],di[N],li[N];
		bool vs[N];
		for(int j=0;j<N;j++){
	//输入每组数据Ti(第i架飞机Ti时刻到达机场上空),Di(可盘旋时间),Li(降落需要时间)
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
