 #include <stdio.h>
#define MAX 11
/*输入MAX-1个整型数字,找出不同数字的个数,并且给出出现次数最多的数字。*/
int *sel_sort(int n , int *a,int seq)/*选择排序 seq:0为由小到大，1为由大到小*/
{
    int i=0,j=0 ,min=0,tmp;
    for(i=0 ; i<n-1 ; i++)
    {
        min=i;
        for(j=i+1 ; j<n ; j++)
        {
            if(seq==0){
                if(a[j]<a[min])
                    min=j;
            }
            if(seq==1){
                if(a[j]>a[min])
                    min=j;
            }
        }
        tmp=a[i];
        a[i]=a[min];
        a[min]=tmp;
    }
    return a;
}

int main()
{
    int tmp,num,max,i=0,j=0,*p,**q;
    int a[MAX]={0},b[2][MAX]={0};
    printf("Please input:\n");
    for(i=0;i<MAX-1;i++)
    {
        scanf("%d",&a[i]);
    }
    p=sel_sort(MAX-1,a,0);
    num=1;
    b[0][0]=a[0];
    b[1][0]=1;
    tmp=1;
    for(i=0;i<MAX-2;i++)
    {
        if(p[i+1]!=p[i]){
            b[0][num]=p[i+1];
            b[1][num-1]=tmp;
            tmp=1;
            num+=1;
        }
        else{
            tmp+=1;
        }
    }
    b[1][num-1]=tmp;

    /*二维数组排序*/
    for(i=0 ; i<num-1 ; i++)
    {
        max=i;
        for(j=i+1 ; j<num ; j++)
        {
            if(b[1][j]>b[1][max])
                max=j;
        }
        tmp=b[1][i];
        b[1][i]=b[1][max];
        b[1][max]=tmp;
        tmp=b[0][i];
        b[0][i]=b[0][max];
        b[0][max]=tmp;

    }
/*完成二维数组排序*/

    printf("\nnum=%d\n",num);
    printf("NUM[0]=%d cnt=%d\n",b[0][0],b[1][0]);
    for(i=1;i<num;i++)
    {
        if(b[1][i-1]==b[1][i])
            printf("NUM[%d]=%d cnt=%d\n",i,b[0][i],b[1][i]);
        else
            break;
    }
    system("pause");

    return 0;
}