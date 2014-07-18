#include <iostream>
#include "miscellaneous.h"

int main()
{
	using namespace std;
	/*trailing-return-type*/
	char a = '1';
	int b = 1;
	auto c = adding_func(a, b);
	cout << c << endl;
	getchar();
	return 0;
}