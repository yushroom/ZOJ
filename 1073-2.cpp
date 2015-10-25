#include <stdio.h>
#include <string.h>


int main()
{
    char str[80];
    int a[80];
    while(scanf("%s",str)!=EOF)
    {
        int k,i,flag=0;
        k=strlen(str);
        a[k]=0;
        for(i=k-1;i>=0;i--)
        {
            int temp;
            temp=(k+1)*(str[i]-'0')+a[i+1];
            a[i]=temp/10;
            if(temp%10!=9)
            {
                flag=1;
                break;
            }
        }
        if(flag!=1)
            printf("%s is cyclic\n",str);
        else
            printf("%s is not cyclic\n",str);
        
    }
    return 0;
}