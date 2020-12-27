#include<stdio.h>
#include<math.h>
int main()
{
	double n,temp,sign,sum;
	sum = 0;
	n = sign = 1;
	do
	{
		temp = sign / n;
		sum = sum + temp;
		sign = -sign;
		n++;
	} while ((fabs(temp))>0.0001);
	printf("%lf,%lf,%lf", sum,temp,n);
	return 0;
}