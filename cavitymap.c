#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    char arr[102][102];
    for(int i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }
    printf("%s\n",arr[0]);
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if((int)arr[i][j]>(int)arr[i][j-1] && (int) arr[i][j+1]<(int)arr[i][j] && (int)arr[i][j]>(int)arr[i-1][j] && (int)arr[i][j]>(int)arr[i+1][j])
            {
                arr[i][j]='X';
            }
        }
        printf("%s\n",arr[i]);
    }
    if(n!=1)
      printf("%s",arr[n-1]);
    return 0;
}
