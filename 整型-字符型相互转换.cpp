int main()

{

	//const char* str[] = { "2","1","+","3","*" };

	//int value = ReversePolishNotation(str, sizeof(str) / sizeof(const char*));

	//cout << value << endl;



	//把整型变成string类型

	int a = 10;

	string b = to_string(a);

	cout << "转换后的值b = " << b << endl;



	//把string变成整型

	int c = 0;

	c = atoi(b.c_str());

	

	cout << "转换之后的值c = " << c << endl;



	//把string 转换成char*

	char *d= new char;

	_itoa(atoi(b.c_str()),d,10);



	const char *d1 = b.c_str();

	cout << d << endl;

	//把char*转换成string

	string e = d;





	//int -> char*

	char *f = new char;

	_itoa(a, f, 8);

	cout <<"f = "<< f << endl;

	system("pause");

	return 0;

}
