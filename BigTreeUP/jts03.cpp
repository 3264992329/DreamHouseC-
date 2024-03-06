/*
输入N个人的语(chinese)数(math)外(english)考试成绩，请输出总分最低的学生和单科最低的学生，相同的成绩也要输出(按照原来的顺序）

输入： 一个整数n表示n个人的考试成绩（1<n<=1000),随后有n行，每行依次是这个学生的姓名，语文成绩，数学成绩，外语成绩（都是整数）
输出： 首先输出语文最低的人（可以并列），然后是数学最低的, 外语最低的，最后输出总分最低的人（可以并列）具体格式参考输出样例

输入样例
5
tom    100  99  98
alice  100 100 100
peter  89   89 100
jerry  60  100 100
cat    60   50  50


输出样例
lower chinese:
jerry(60)
cat(60)

lower math:
cat(50)

lower english:
cat(50)

lower score:
cat(160)
*/
#include <stdio.h>

struct student{
	char name[20];
	int chinese;
	int math;
	int english;
	int score;
};

int main(){
	int n;
	int lc=999,lm=999,le=999,ls=999;
	int ct,mt,et,st;
	printf("输入数量:\n");
	scanf("%d",&n);
	struct student students[n];
	printf("输入数据:\n");
	for(int i=0;i<n;i++){
		scanf("%s %d %d %d",&students[i].name,&students[i].chinese,&students[i].math,&students[i].english);
		students[i].score=students[i].chinese+students[i].math+students[i].english;
	}
	
	for(int i=0;i<n;i++){
		//语文 
		if(students[i].chinese<lc){
			lc=students[i].chinese;
			ct=i;
		}
		//数学 
		if(students[i].math<lm){
			lm=students[i].math;
			mt=i;
		}
		//英语 
		if(students[i].chinese<le){
			le=students[i].chinese;
			et=i;
		}
		//总分
		if(students[i].score<ls){
			ls=students[i].score;
			st=i;
		}
	}
	
	printf("lower chinese:\n");
	for(int i=0;i<n;i++){
		if(students[i].chinese==students[ct].chinese){
			printf("%s(%d)\n",students[i].name,students[i].chinese);
		}
	}
	printf("\n");
	printf("lower math:\n");
	for(int i=0;i<n;i++){
		if(students[i].math==students[mt].math){
			printf("%s(%d)\n",students[i].name,students[i].math);
		}
	}
	printf("\n");
	printf("lower english:\n");
	for(int i=0;i<n;i++){
		if(students[i].english==students[et].english){
			printf("%s(%d)\n",students[i].name,students[i].english);
		}
	}
	printf("\n");
	printf("lower score:\n");
	for(int i=0;i<n;i++){
		if(students[i].score==students[st].score){
			printf("%s(%d)\n",students[i].name,students[i].score);
		}
	}
	
	return 0;
}
