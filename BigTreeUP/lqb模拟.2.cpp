#include<stdio.h>

int main(){
	int a=1;
	for(int i=0;i<2023;i++){
		a*=2;
		if(a>=1000){
			a=a%1000;
		}
	}
	printf("%d",a);
}
