#include<iostream>
#include<math.h>
using namespace std;

float Calc(float a)
{
	if (a < 1e-6)
	{
		return 0;
	}
	float x0 = a;
	float x = (x0 + a / x0) / 2;
	while (abs(x - x0) > 1e-6)
	{
		x0 = x;
		x = (x0 + a / x0) / 2;
	}
	return x;
}

void main()
{
	for (int i = 0;i <= 10;i++)
	{
		cout << i << "  " << Calc((float)i) << endl;
	}

	system("pause");
}
