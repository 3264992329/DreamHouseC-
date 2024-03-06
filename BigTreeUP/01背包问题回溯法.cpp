#include <stdio.h>

#define MAX_N 100  // 最大物品数量
#define MAX_W 1000 // 最大背包容量

int n, weight[MAX_N], value[MAX_N], mw; // n:物品数量，weight:物品重量，value:物品价值，mw:背包容量
int mv, cw, cv;   // mv: 最大价值，cw: 当前背包重量，cv: 当前背包价值
int x[MAX_N]; // x[i]为1表示第i个物品放入背包，为0表示不放入背包 

void dfs(int d) {
    if(d==n||cw==mw){
    	mv=((mv>cv)?mv:cv);
    	return; 
	} 
	
	if(cw+weight[d]<=mw&&d<n){
		x[d]=1;
		cw+=weight[d];
		cv+=value[d];
		dfs(d+1);
		x[d]=0;
		cw-=weight[d];
		cv-=value[d];
	}
	dfs(d+1); 
}

int main() {
    scanf("%d,%d", &n, &mw);
    for (int i = 0; i < n; i++) {
        scanf("%d,%d", &weight[i], &value[i]);
    }
    dfs(0);
    printf("Max value = %d\n", mv);
    return 0;
}
