#include<stdio.h> 
#include<stdlib.h>

#define v 5
int minkey(int key[],bool set[]){//minkey 来查找当前顶点集合到其余顶点的最小距离
	int min=99999999,min_index;
	for(int i=0;i<v;i++){
		if(key[i]<min&&set[i]==false){
			min=key[i];
			min_index=i;
		}
	}
	return min_index; 
}

void printmst(int ph[v][v],int parent[]){
	printf("边\t\t权值\n");
	for(int i=1;i<v;i++){
		printf("%d-%d\t\t%d",parent[i],i,ph[i][parent[i]]);
	}
}
void primmst(int ph[v][v]){
	int parent[v];
	int key[v];// key[i] 存储顶点i到已经包含在最小生成树中的顶点的最小边权值
	bool set[v];// 判断结点是否被包含于最小生成树中
	
	//初始化key数组 
	for(int i=0;i<v;i++){
		set[i]=false;
		key[i]=99999999;
	}
	parent[0]=-1;
	key[0]=0;
	
	for(int count=0;count<v-1;count++){
		int u=minkey(key,set);//u是 
		set[u]=true;
		for(int j=0;j<v;j++){
			if(ph[u][j]&&set[u]==false&&key[j]>ph[u][j]){
				key[j]=ph[u][j];
				parent[j]=u;
			}
		}
	}
	printmst(ph,parent);
}

int main(){
	int ph[v][v] = { {0, 2, 0, 6, 0},
                    {2, 0, 3, 8, 5},
                    {0, 3, 0, 0, 7},
                    {6, 8, 0, 0, 9},
                    {0, 5, 7, 9, 0} };
    primmst(ph);
    return 0;
}
