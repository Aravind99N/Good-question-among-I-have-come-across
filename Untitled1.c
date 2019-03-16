#include <stdio.h>
int max(int a, int b) { return (a > b)? a : b; }

int array(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
  return K[n][W];
}
int main()
{
	int W,N;
	scanf("%d",&N);
	scanf("%d",&W);
    int val[N];
    int wt[N];
    int x=0;
    while(x<N)
	{
	 //printf("Enter value array number %d \n", (x+1));
	 scanf("%d", &wt[x]);
	 x++;
	}
    int y=0;
    while(y<N)
	{
	 //printf("Enter weight array number %d \n", (y+1));
	 scanf("%d", &val[y]);
	 y++;
	}
    int n = sizeof(val)/sizeof(val[0]);
    printf("\nValue = %d", array(W, wt, val, n));
    return 0;
}

