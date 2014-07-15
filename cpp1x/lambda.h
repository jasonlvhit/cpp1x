#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//basic lambda function
void basic(){
	auto f = [](){ std::cout << "Hello lambda" << endl; };
	f();
}

//init stl container
vector<int> initSTL(){
	vector<int> v(10);
	generate(v.begin(), v.end(), [](){ return rand() % 100; });
	return v;
}

//basic capture example
void capture(){
	size_t count = 0;
	vector<int> v = initSTL();
	for_each(v.begin(), v.end(), ][&count](int value){
		if (value % 2) count++;
	});
}



