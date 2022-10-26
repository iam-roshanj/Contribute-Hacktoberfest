#include <stdio.h>
#include <math.h>

int main()
{
   int m,r=0;
   printf("Enter number of data bits here\n");
   scanf("%d",&m);

   while(pow(2,r) < (r+m+1))
        r++;
    int arr[r+m];
    printf("Enter the data here\n");
    for(int i=0;i<(r+m);i++)
    {
        if((int)pow(2,r) % (i+1) == 0)
            arr[i] = 0;
        else
            scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<r;i++)
    {
        int j= pow(2,i) - 1;
        int count = j+1;
        int b=count;
        int sum=0;

        while(j<=(r+m))
        {
            if(count!=0)
            {
                sum += arr[j];
                count--;
                j++;
            }
            else
            {   
                count = b;
                j = j + b;
            }
            
        }
        arr[b-1] = sum%2;
    }
    for(int i=0;i<(r+m);i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}