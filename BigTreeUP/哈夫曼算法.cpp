#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<math.h> 

//全局定义
#define N 30
#define Max 2*N-1

//结构体 
typedef struct {
	 double weight;/*节点权值*/
	 char s;/*所代表的字符,列如:程序输入样例中的m,c,n*/ 
	 int parent,lc,rc;//父亲,左孩子,右孩子 
}HTNode,huffmantree[Max+1];//默认哈夫曼数有MAX+1个结点 
 
 
/*函数声明*/
void select(huffmantree ht,int x,int *m1,int *m2){//在森林集合中找根权值最小的两个  
double min1=999999999;
double min2=999999999;
for(int j=1;j<=x;j++){
	if(ht[j].weight<min1&&ht[j].parent==0){
		min1=ht[j].weight;
		*m1=j;
	}
}
/*在已经查找到的最小的数min1的前提下查找不等于min1的最小数min2*/
int k;
for(k=1;k<=x;k++){
	if(ht[k].weight<min2&&ht[k].parent==0){
		min2=ht[k].weight;
		*m2=k;
	}
} 
}

/*构建哈夫曼树*/
void creathuffmantree (huffmantree ht,int n){/*n为用户在主函数中输入的字符个数,即为后面构建哈夫曼树的叶子结点个数*/
	int i;
	for(i=n+1;i<=2*n-1;i++){/*i从n+1开始,创建第n+1个结点,每执行一次循环创建一个新的父节点,直到将森林变为一个哈夫曼树*/ 
		int m1,m2;
		select(ht,i-1,&m1,&m2);//调用select,找出最小的两个根节点 
		 ht[i].weight=ht[m1].weight+ht[m2].weight;
		 ht[i].lr=m1;
		 ht[i].rc=m2;
		 ht[i].parent=0;//新结点父亲为0 
		 ht[m1].parent=i;
		 ht[m2].parent=i;
	} 
}

/*哈夫曼编码*/
 void huffmancoding(huffmantree ht,char **hc,int n){/* **贺从双重指针 */
 	char * cd=(char * )malloc(n*sizeof(char));//cd临时存放哈夫曼编码
	 cd[n-1]='\0'; //根节点编码为空 
	 int now=1;//正在编码的结点 
	 int p=0;//正在编码的结点的父亲结点 
	 int start;//此时编码存放的位置 
	 int i=0;
	 
	 /*外层循环用于初始化,更换需要编码的结点*/
	 while(i<n){
	 	start=n-1;//编码永远在数组指定位置开始存放 
		 now=i+1;//随着while循环的推进,编码的起点也在更换 
		 p=ht[now].parent;//父亲结点初始化为now结点的父亲位置 
	 	/*内层循环用于获取指定结点的编码*/
	 	while(p!=0){
	 		start--;
			 if(ht[p].lc==now){//结点为父亲结点左孩子赋0,右孩子赋1 
			 	cd[start]='0';
			 }
			 else{
			 	cd[start]='1';
			 } 
			 now=p;//此时的结点为原来的父亲结点 
			 p=ht[now].parent;//更新父亲结点 
		 } 
		 hc[i+1]=(char*)malloc((n-start)*sizeof(char));//开辟存放编码数组的内存 
		 strcpy(hc[i+1],&cd[start]);//传指针复制编码 
		 i++; 
	 } 
	  
 }
 /*先序打印*/
void printhuffmancode(huffmantree ht,char **hc,ht index){
	if(index>=1){
		if(ht[index].lc==0&&ht[index].rc==0){
			printf("%c:%s\n",ht[index].s,hc[index]);
			return ;
		}
		printhuffmancode(hc,hc,ht[index].lc);//递归 
		printhuffmancode(hc,hc,ht[index].rc);
		
	}
}

/*在生成的哈夫曼树中查找目标*/
void huffmandecoding(huffmantree ht,int n,char *pwd){
	printf("original:");
	int len=strlen(pwd);//获取用户输入的编码的长度 
	int i=0;
	int node=2*n-1;//初始化为根节点出发 
	while(i<len){
		if(pwd[i]=='0'){//是0,走左指数 
			node=ht[node].lc;//更新当前结点 
			i++;
			if(ht[node].lc==0&&ht[mode].rc==0){//如果这是叶子结点,输出叶子结点的字符 
				printf("%c",ht[node].s);
				node=2*n-1;//重新从根节点出发,继续编码 
			}
		}
		if(pwd[i]=='1'){//是1,走右指数 
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
	int n;//输入字符个数
	for(i=1;i<=n;i++){//循环获取每一个字符和对应的频率 
		scanf("%c%lf",&ht[i].s,&ht[i].weight);//输入字符和频率 
		getchar();
		//初始化其关系,均为0 
		ht[i].lc=0;
		ht[i].rc=0;
		ht[i].parent=0;
	} 
	char pwd[9999];//需要编译的字符串 
	scanf("%s",pwd);//获取字符串 
	//创建二叉树 
	creathuffmantree(ht,n);
	//编码 
	huffmancoding(ht,hc,n);
	//前序输出 
	printhuffmancode(ht,hc,2*n-1);
	//译码 
	huffmandecoding(ht,n,pwd); 
} 



