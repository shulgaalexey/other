#include <iostream>

class myclass {
	int a;
public:
	myclass(int a) : a{a} {
		std::cout << "ctor: " << this << std::endl;
	}
	virtual ~myclass() {
		std::cout << "dtor: " << this << std::endl;
	}
	int get() const { return a; }
};

int main(void) {

	const size_t n = 10;
	const size_t obj_size = sizeof(myclass);
	const size_t pull_size = obj_size * n;
	char pull[pull_size] = {0};

	std::cout << "Obj size: " << obj_size
		<< ", Pull size: " << pull_size << std::endl
		<< "======================" << std::endl;

	void *obj_arr[n] = {0};

	for (size_t i = 0; i < n; i++) {
		void *ptr = pull + obj_size * i;
		myclass *obj = new(ptr) myclass(i);
		obj_arr[i] = obj;
	}

	for (size_t i = 0; i < n; i++) {
		std::cout << static_cast<myclass *>(obj_arr[i])->get() << std::endl;
	}

	for (size_t i = 0; i < n; i++) {
		static_cast<myclass *>(obj_arr[i])->~myclass();
		//delete static_cast<myclass *>(obj_arr[i]); CANNOT DO THIS
	}

	return 0;
}
