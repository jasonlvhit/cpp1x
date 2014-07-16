/*
* Reference£º
* http://msdn.microsoft.com/en-us/library/dd293608.aspx
* 
*/

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
	for_each(v.begin(), v.end(), [&count](int value){
		if (value % 2) count++;
	});
}

//basic assign lambda expression to the function object
void assign(){
	auto f = [](int x, int y){ return x + y; };
	cout << f(1, 3) << endl;
}

//nested lambda expression
void nest(){
	auto nested = [](int x){ return [](int y) { return y * 2; }(x)+3;  };
	cout << nested(5) << endl;
}

//catch exception
void execption(){
	vector<int> elem(3);
	vector<int> index(3);
	index[0] = 0;
	index[1] = -1;
	index[2] = 2;
	try{
		for_each(index.begin(), index.end(), [&](int index_){
			elem.at(index_) = index_;
		});
	}catch (const out_of_range& e){
		cerr << "Caught '" << e.what() << "'." << endl;
	}
}

//template
template<typename T>
void templates_negate(vector<T> &v)
{
	for_each(v.begin(), v.end(), [](T& t){ t = -t; });
}

void negate()
{
	vector<int> v(3, 2);
	for_each(v.begin(), v.end(), [](int i){cout << i << endl; });
	templates_negate(v);
	for_each(v.begin(), v.end(), [](int i){cout << i << endl; });
}





