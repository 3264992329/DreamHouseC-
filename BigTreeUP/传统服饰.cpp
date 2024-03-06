#include <stdio.h>
#include <string.h>


// 请在这里补充代码，完成本关任务
/********** Begin *********/
/*结构体*/
struct TraditionalClothing {
    char name[50];
    int size;
};
/*函数*/
void sortTraditionalClothing(TraditionalClothing arr[], int size, int sortOption){
    /*冒泡排序*/
        if(sortOption==1){
            for(int i=0;i<size;i++){
            for(int j=0;j<size-i-1;j++){

            if(arr[i].size>arr[i+1].size){
            struct TraditionalClothing temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
        }}}
        }

        else if(sortOption==2){
            for(int i=0;i<size;i++){
            for(int j=0;j<size-i-1;j++){
            if(arr[i].size<arr[i+1].size){
                struct TraditionalClothing temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }}}

        else if(sortOption==3){
            for(int i=0;i<size;i++){
            for(int j=0;j<size-i-1;j++){
            if(strcmp(arr[j].name, arr[j + 1].name)>0){
                struct TraditionalClothing temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }}}
        
}


int main(){
int n;
int sortOption;
struct TraditionalClothing p[50];
printf("请输入传统服饰数量:");
scanf("%d",&n);
/*输入商品信息*/
for(int i=0;i<n;i++){
    printf("输入商品名称:\n");
        scanf("名称:%s",&p[i].name);
    printf("输入商品价格:\n");   
        scanf("价格:%d",&p[i].size);
}
printf("请输入排序要求(1升序,2降序,3字典序升序):");
scanf("%d",&sortOption);
/*引用函数*/
sortTraditionalClothing (p,n,sortOption);
/*输出商品信息*/
for(int j=0;j<n;j++){
    scanf("名称:%s,价格:%d",&p[j].name,&p[j].size);
}
return 0;
}
