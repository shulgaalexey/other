// to save all temporary files during building, use following:
// g++ -std=c++1y -Wall -g -o test study_compiler.cpp --save-temps

template <typename T>
class myclass {
	T a;
public:
	myclass(T a) : a(a) {}
};

int main(void) {

	myclass<int> myobj1{1};
	myclass<double> myobj2{1.5};

	return 0;
}
