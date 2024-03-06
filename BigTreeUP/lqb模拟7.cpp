/*
问题描述
　　输入一个仅包含小写英文字母的字符串，请问这个字符串中的最后一元音是什么。
　　在英文中，a, e, i, o, u 共 5 个字母是元音字母，其它字母不是元音字母。
输入格式
　　输入一行包含一个字符串，仅由小写英文字符组成，字符串中至少包含一个元音字母。
输出格式
　　输出一行包含一个字符，表示答案。
样例输入
lanqiao
样例输出
o
样例输入
cup
样例输出
u
评测用例规模与约定
　　对于所有评测用例，1 <= 字符数量 <= 10000 。
*/
#include<stdio.h>
#include<string.h>
int main(){
	char a[99999];
	char t[1];
	int dx;
	scanf("%s",&a);
	dx=strlen(a);
	
	int p=0,d=0;
	for(int i=0;i<dx;i++){
		if(a[i]>'z'||a[i]<'a'){
			p++;
		}
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
			d++;
		}
	}
	
	if(p==0&&d>0){
		for(int i=0;i<dx;i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
			t[0]=a[i];
		}
	}
	printf("%c",t[0]);
	}
	
	return 0;
}
