#include<stdio.h> 
#include<stdlib.h>

#define v 5
int minkey(int key[],bool set[]){//minkey �����ҵ�ǰ���㼯�ϵ����ඥ�����С����
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
	printf("��\t\tȨֵ\n");
	for(int i=1;i<v;i++){
		printf("%d-%d\t\t%d",parent[i],i,ph[i][parent[i]]);
	}
}
void primmst(int ph[v][v]){
	int parent[v];
	int key[v];// key[i] �洢����i���Ѿ���������С�������еĶ������С��Ȩֵ
	bool set[v];// �жϽ���Ƿ񱻰�������С��������
	
	//��ʼ��key���� 
	for(int i=0;i<v;i++){
		set[i]=false;
		key[i]=99999999;
	}
	parent[0]=-1;
	key[0]=0;
	
	for(int count=0;count<v-1;count++){
		int u=minkey(key,set);//u�� 
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
