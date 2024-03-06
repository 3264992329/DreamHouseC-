//11
//#include<stdio.h>
//double abc(int a){	
//    double s=0.0;
//    int sign=1;
//	for(int j=1;j<=a;j++){
//		s+=(1.0/j)*sign;
//		sign=-sign;
//	}
//	return s;
//}
//int main(){
//	int m;
//	int a;
//	while(scanf("%d\n",&m)==1){
//		/*动态分配内存空间大小*/
//		for(int i=0;i<m;i++){
//			scanf("%d",&a);
//			double s=abc(a);
//			printf("%.2lf\n",s);
//		}
//		
//	}
//} 12
//#include<stdio.h>
//#include<stdbool.h> 
//#include<math.h>
//bool abc(int num){
//	if(num<=1){
//		return false;
//	}
//	for(int i=2;i<sqrt(num);i++){
//		if(num%i==0){
//			return false;
//		}	
//	}
//	return true;
//}
//int main(){
//	int x,y;
//	int s;
//	while(scanf("%d %d",&x,&y)==2&&-39<=x&&x<y&&y<=50){
//		if (x==0&&y==0){
//			break;
//		}
//		bool f=true;
//		for(int n=x;n<=y;n++){
//			s=n*n+n+41;
//			if (!abc(s)){
//				f=false;
//				break;
//			} 
//		}
//			if(f){
//				printf("OK\n");
//			}
//			else
//			{
//				printf("Sorry\n");
//			}
//			
//	}
//	return 0; 
//} 13
//#include<stdio.h>
//int main(){
//	int n;
//	int s=1;
//	while(scanf("%d",&n)==1&&1<n&&n<30){
//		for(int i=n-1;i>=1;i--){
//		    s=(s+1)*2;
//		}
//		printf("%d\n",s);
//		s=1;
//	}
//	return 0;
//}14
//#include<stdio.h>
//#include<stdlib.h>
//int main(){
//	double s=0.0;
//	int n;
//	int i;
//	double max,mix;
//	while(scanf("%d",&n)==1&&2<n&&n<=100){
//		s=0;
//		double *p=(double *)malloc(n*sizeof(double));
//		for(i=0;i<n;i++){
//			scanf("%lf",&p[i]);
//		    s=s+p[i];
//		  if(i==0){
//		  	max=p[i];
//		  	mix=p[i];
//		  }
//		  else{
//		  	if(max<p[i]){
//		  		max=p[i];
//			  }
//			if(mix>p[i]){
//				mix=p[i];
//			}
//		  }
//		}
//		 s=(s-max-mix)/(n-2);
//         printf("%.2lf\n",s);
//	}
//  return 0;
//}15
//#include<stdio.h>
//
//int main() {
//    int n, m;
//    while(scanf("%d %d", &n,&m) == 2) {
//    	int num[100];
//    	for(int i=2;i<=n*2;i+=2){
//    		num[(i/2)-1]=i;
//		}
//		int avg[100];
////		avgcount和count不一样 
//		int avgcount=0;
//		for(int i=0;i<n;i+=m){
//			int s=0;
//			int count=0;
//			for(int j=i;j<m+i&&j<n;j++){
//				s+=num[j];
//				count++;
//			}
//			avg[avgcount++]=s/count; 
//		}
//			for(int i=0;i<avgcount;i++){
//				printf("%d ",avg[i]);
//			}
//		 printf("\n");
//    }
//    return 0;
//}16
//#include<stdio.h>
//int main(){
//	int n;
//	while(scanf("%d",&n)==1&&n!=0){
//			int a[100];
//			for(int i=0;i<n;i++){
//				scanf("%d",&a[i]);
//			}
//			int min=0;
//			for(int j=1;j<n;j++){
//				if(a[j]<a[min]){
//					min=j;
//				}
//			int teap=a[min];
//			a[min]=a[0];
//			a[0]=teap;
//			}
//			for(int i=0;i<n;i++){
//				printf("%d ",a[i]);
//			}
//			printf("\n");
//		}
//	return 0;	
//}
//}17
//#include <stdio.h>
//int main ()
//{
//    int n;
//    scanf ("%d\n", &n);
//    while (n --)
//    {
//        char a[800] = {'\0'};
//        int s = 0;
//        gets(a);
//        for (int i = 0; a[i] != '\0'; i ++)
//            if (a[i] >= '0' && a[i] <= '9') s ++;
//        printf("%d\n", s);
//    }
//    return 0;
//}18
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1&&n!=0&&n!=55){
		int s=1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=i+3;j++){
				s=s+j;
			}
		}
		printf("%d",s);
	}
	printf("\n");
}


