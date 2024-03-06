#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<math.h> 

//ȫ�ֶ���
#define N 30
#define Max 2*N-1

//�ṹ�� 
typedef struct {
	 double weight;/*�ڵ�Ȩֵ*/
	 char s;/*��������ַ�,����:�������������е�m,c,n*/ 
	 int parent,lc,rc;//����,����,�Һ��� 
}HTNode,huffmantree[Max+1];//Ĭ�Ϲ���������MAX+1����� 
 
 
/*��������*/
void select(huffmantree ht,int x,int *m1,int *m2){//��ɭ�ּ������Ҹ�Ȩֵ��С������  
double min1=999999999;
double min2=999999999;
for(int j=1;j<=x;j++){
	if(ht[j].weight<min1&&ht[j].parent==0){
		min1=ht[j].weight;
		*m1=j;
	}
}
/*���Ѿ����ҵ�����С����min1��ǰ���²��Ҳ�����min1����С��min2*/
int k;
for(k=1;k<=x;k++){
	if(ht[k].weight<min2&&ht[k].parent==0){
		min2=ht[k].weight;
		*m2=k;
	}
} 
}

/*������������*/
void creathuffmantree (huffmantree ht,int n){/*nΪ�û�����������������ַ�����,��Ϊ���湹������������Ҷ�ӽ�����*/
	int i;
	for(i=n+1;i<=2*n-1;i++){/*i��n+1��ʼ,������n+1�����,ÿִ��һ��ѭ������һ���µĸ��ڵ�,ֱ����ɭ�ֱ�Ϊһ����������*/ 
		int m1,m2;
		select(ht,i-1,&m1,&m2);//����select,�ҳ���С���������ڵ� 
		 ht[i].weight=ht[m1].weight+ht[m2].weight;
		 ht[i].lr=m1;
		 ht[i].rc=m2;
		 ht[i].parent=0;//�½�㸸��Ϊ0 
		 ht[m1].parent=i;
		 ht[m2].parent=i;
	} 
}

/*����������*/
 void huffmancoding(huffmantree ht,char **hc,int n){/* **�ش�˫��ָ�� */
 	char * cd=(char * )malloc(n*sizeof(char));//cd��ʱ��Ź���������
	 cd[n-1]='\0'; //���ڵ����Ϊ�� 
	 int now=1;//���ڱ���Ľ�� 
	 int p=0;//���ڱ���Ľ��ĸ��׽�� 
	 int start;//��ʱ�����ŵ�λ�� 
	 int i=0;
	 
	 /*���ѭ�����ڳ�ʼ��,������Ҫ����Ľ��*/
	 while(i<n){
	 	start=n-1;//������Զ������ָ��λ�ÿ�ʼ��� 
		 now=i+1;//����whileѭ�����ƽ�,��������Ҳ�ڸ��� 
		 p=ht[now].parent;//���׽���ʼ��Ϊnow���ĸ���λ�� 
	 	/*�ڲ�ѭ�����ڻ�ȡָ�����ı���*/
	 	while(p!=0){
	 		start--;
			 if(ht[p].lc==now){//���Ϊ���׽�����Ӹ�0,�Һ��Ӹ�1 
			 	cd[start]='0';
			 }
			 else{
			 	cd[start]='1';
			 } 
			 now=p;//��ʱ�Ľ��Ϊԭ���ĸ��׽�� 
			 p=ht[now].parent;//���¸��׽�� 
		 } 
		 hc[i+1]=(char*)malloc((n-start)*sizeof(char));//���ٴ�ű���������ڴ� 
		 strcpy(hc[i+1],&cd[start]);//��ָ�븴�Ʊ��� 
		 i++; 
	 } 
	  
 }
 /*�����ӡ*/
void printhuffmancode(huffmantree ht,char **hc,ht index){
	if(index>=1){
		if(ht[index].lc==0&&ht[index].rc==0){
			printf("%c:%s\n",ht[index].s,hc[index]);
			return ;
		}
		printhuffmancode(hc,hc,ht[index].lc);//�ݹ� 
		printhuffmancode(hc,hc,ht[index].rc);
		
	}
}

/*�����ɵĹ��������в���Ŀ��*/
void huffmandecoding(huffmantree ht,int n,char *pwd){
	printf("original:");
	int len=strlen(pwd);//��ȡ�û�����ı���ĳ��� 
	int i=0;
	int node=2*n-1;//��ʼ��Ϊ���ڵ���� 
	while(i<len){
		if(pwd[i]=='0'){//��0,����ָ�� 
			node=ht[node].lc;//���µ�ǰ��� 
			i++;
			if(ht[node].lc==0&&ht[mode].rc==0){//�������Ҷ�ӽ��,���Ҷ�ӽ����ַ� 
				printf("%c",ht[node].s);
				node=2*n-1;//���´Ӹ��ڵ����,�������� 
			}
		}
		if(pwd[i]=='1'){//��1,����ָ�� 
			node=ht[node].lc;
			i++;
			if(ht[node].lc==0&&ht[mode].rc==0){
				printf("%c",ht[node].s);
				node=2*n-1;
			} 
	}
} 

main(void){
	huffmantree ht;
	int n;//�����ַ�����
	for(i=1;i<=n;i++){//ѭ����ȡÿһ���ַ��Ͷ�Ӧ��Ƶ�� 
		scanf("%c%lf",&ht[i].s,&ht[i].weight);//�����ַ���Ƶ�� 
		getchar();
		//��ʼ�����ϵ,��Ϊ0 
		ht[i].lc=0;
		ht[i].rc=0;
		ht[i].parent=0;
	} 
	char pwd[9999];//��Ҫ������ַ��� 
	scanf("%s",pwd);//��ȡ�ַ��� 
	//���������� 
	creathuffmantree(ht,n);
	//���� 
	huffmancoding(ht,hc,n);
	//ǰ����� 
	printhuffmancode(ht,hc,2*n-1);
	//���� 
	huffmandecoding(ht,n,pwd); 
} 



