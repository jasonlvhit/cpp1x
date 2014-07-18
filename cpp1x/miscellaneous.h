/*trailing-return-type*/

template <class Lhs, class Rhs>
auto adding_func(const Lhs & lhs, const Rhs & rhs) -> decltype(lhs + rhs) { return lhs + rhs; }

struct SomeStruct  {
	auto func_name(int x, int y) -> int;
};

auto SomeStruct::func_name(int x, int y) -> int {
	return x + y;
}