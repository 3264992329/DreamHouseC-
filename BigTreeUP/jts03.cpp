/*
����N���˵���(chinese)��(math)��(english)���Գɼ���������ܷ���͵�ѧ���͵�����͵�ѧ������ͬ�ĳɼ�ҲҪ���(����ԭ����˳��

���룺 һ������n��ʾn���˵Ŀ��Գɼ���1<n<=1000),�����n�У�ÿ�����������ѧ�������������ĳɼ�����ѧ�ɼ�������ɼ�������������
����� �������������͵��ˣ����Բ��У���Ȼ������ѧ��͵�, ������͵ģ��������ܷ���͵��ˣ����Բ��У������ʽ�ο��������

��������
5
tom    100  99  98
alice  100 100 100
peter  89   89 100
jerry  60  100 100
cat    60   50  50


�������
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
	printf("��������:\n");
	scanf("%d",&n);
	struct student students[n];
	printf("��������:\n");
	for(int i=0;i<n;i++){
		scanf("%s %d %d %d",&students[i].name,&students[i].chinese,&students[i].math,&students[i].english);
		students[i].score=students[i].chinese+students[i].math+students[i].english;
	}
	
	for(int i=0;i<n;i++){
		//���� 
		if(students[i].chinese<lc){
			lc=students[i].chinese;
			ct=i;
		}
		//��ѧ 
		if(students[i].math<lm){
			lm=students[i].math;
			mt=i;
		}
		//Ӣ�� 
		if(students[i].chinese<le){
			le=students[i].chinese;
			et=i;
		}
		//�ܷ�
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
