#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void main()
{

	char str[50];
	scanf("%s", &str);
	int sum = 0;
	char *p = &str;
	while (*p!='\0')
	{
		char temp = *p;
		if (temp >= '0'&&temp <= '9')
		{
			int int_temp;
			int_temp = temp-'0';

			sum += int_temp;
		}
		p++;
	}
