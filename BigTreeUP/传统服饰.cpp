#include <stdio.h>
#include <string.h>


// �������ﲹ����룬��ɱ�������
/********** Begin *********/
/*�ṹ��*/
struct TraditionalClothing {
    char name[50];
    int size;
};
/*����*/
void sortTraditionalClothing(TraditionalClothing arr[], int size, int sortOption){
    /*ð������*/
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
printf("�����봫ͳ��������:");
scanf("%d",&n);
/*������Ʒ��Ϣ*/
for(int i=0;i<n;i++){
    printf("������Ʒ����:\n");
        scanf("����:%s",&p[i].name);
    printf("������Ʒ�۸�:\n");   
        scanf("�۸�:%d",&p[i].size);
}
printf("����������Ҫ��(1����,2����,3�ֵ�������):");
scanf("%d",&sortOption);
/*���ú���*/
sortTraditionalClothing (p,n,sortOption);
/*�����Ʒ��Ϣ*/
for(int j=0;j<n;j++){
    scanf("����:%s,�۸�:%d",&p[j].name,&p[j].size);
}
return 0;
}
