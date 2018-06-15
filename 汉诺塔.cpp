#include<iostream>
using namespace std;

void MoveOne(char from, char to)
{
	cout << from << " -> " << to << endl;
}
void Move(char from, char to, char aux, int n)
{
	if (n == 1)
	{
		MoveOne(from, to);
		return;
	}
	printf("#move(%c,%c,%c,%d)\n", from, aux, to, n - 1);
	Move(from, aux, to, n - 1);
	
	//MoveOne(from, to);
	cout << "root:" << from << " ->  "<<to << endl;

	printf("#move(%c,%c,%c,%d)\n", aux, to, from, n - 1);
	Move(aux, to, from, n - 1);
	
}

int main()
{
	int n = 3;
	Move('A', 'C', 'B', n);
	return 0;
	system("pause");
}

