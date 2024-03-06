#include <stdio.h>

#define MAX_N 100  // �����Ʒ����
#define MAX_W 1000 // ��󱳰�����

int n, weight[MAX_N], value[MAX_N], mw; // n:��Ʒ������weight:��Ʒ������value:��Ʒ��ֵ��mw:��������
int mv, cw, cv;   // mv: ����ֵ��cw: ��ǰ����������cv: ��ǰ������ֵ
int x[MAX_N]; // x[i]Ϊ1��ʾ��i����Ʒ���뱳����Ϊ0��ʾ�����뱳�� 

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
