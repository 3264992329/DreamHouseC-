//#include<stdio.h>
//int main(){
//	int x,y;
//	float z;
//	scanf("%d %d %f",&x,&y,&z);
//	if(x>0&&y>0){
//		z=z/x;
//	} 
//	else if(x>1||z>1){
//		z=1+z;
//	}
//	z=y+z; 
//	printf("%.2f\n",z); 
//	return 0; 
//} 
//#include <stdio.h>
//int main()
//{  
//   int a = 1, b = -2;
//   for( ; a-- && b++; )
//      printf(¡°%d,%d,¡±, a, b);
//   printf(¡°%d,%d¡±, a, b);
//}
#include<stdio.h>
int main(){
	int k=2;
	string rs=n+"=";
	while(k<=0){
		if(k==n){
			rs=rs+n;
			break;
		}else{
			if(n%k==0){
				rs=rs+k+"*";
				n=n/k;
			}else{
				k++;
			}
		}
	}
	return rs;
} 
