#include<stdio.h>
#include<string.h> 

struct xx{
	char username[50];
	char passname[50];
	char number[50];
};

int main(){
	char number[50];
	int n;
	printf("输入手机号:");
	scanf("%s",number);
	printf("一共泄露多少天信息:");
	scanf("%d",&n);
	
	struct xx xxs[100];
	for(int i=0;i<n;i++){
		scanf("%s %s %s",xxs[i].username,xxs[i].passname,xxs[i].number);
	}
	
	for(int i=0;i<n;i++){
		if(strcmp(number,xxs[i].number)==0){
			int j=0;
			while(xxs[i].passname[j]){
				if(xxs[i].passname[j]>='A'&&xxs[i].passname[j]<='Z'){
				   xxs[i].passname[j]=xxs[i].passname[j]+32;		
				   
				}
				else if(xxs[i].passname[j]>='a'&&xxs[i].passname[j]<='z'){
					xxs[i].passname[j]=xxs[i].passname[j]-32;
				}
				j++;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		printf("%s %s %s\n",xxs[i].username,xxs[i].passname,xxs[i].number);
	}
	return 0;
} 
