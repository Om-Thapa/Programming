#include<stdio.h>
void main(){
    int a[5]={22,11,20,22},i,j;
    printf("Array :%d, %d, %d, %d\n",a[0],a[1],a[2],a[3]);    
    //Using loop
    for(i=4;i>1;i--){
        a[i]=a[i-1];
    }
    a[i+1]=20;
    printf("After Insertion : %d, %d, %d, %d, %d\n",a[0],a[1],a[2],a[3],a[4]);
    for(i=1;i<4;i++){
        a[i]=a[i+1];
    }
    printf("After Deletion : %d, %d, %d, %d\n",a[0],a[1],a[2],a[3]);
    //Reversing the array
    for(i=0;i<2;i++){
        int t=a[i];
        a[i]=a[3-i];
        a[3-i]=t;
    }
    printf("After Reversing : %d, %d, %d, %d\n",a[0],a[1],a[2],a[3]);
    //Checking if array is pallindromic
    int v=1;
    if(a[0]!=a[3])
    v=0;
    if(a[1]!=a[2])
    v=0;
    if(v==1)
    printf("Array is pallindromic");
    else
    printf("Array is not pallindromic");
}