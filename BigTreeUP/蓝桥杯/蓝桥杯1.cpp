#include<stdio.h>
int main(){
	int n;
	int A,B;
	int v[99999];
	int vi[99999];
	int max,min;
//	printf("����ұ����¼����ĿN:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
//		printf("�������O����ĿA,�������X����ĿB:");
	    scanf("%d %d",&A,&B);
	    v[i]=A/B;
	    vi[i]=A/(B+1)+1;
	}
	//�����ֵ 
	max=v[0];
	for(int j=0;j<n-1;j++){
	    	if(v[j+1]<max){
	    		max=v[j+1];
			}
		}
	//����Сֵ
	min=0;
	for(int i=0;i<n;i++){
		if(vi[i]>min){
			min=vi[i];
		}
	}
	
	printf("%d %d",min,max); 
}
