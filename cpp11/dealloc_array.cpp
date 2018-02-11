#include <iostream>
#include <iomanip>

class myclass {
	int a;
public:
	myclass() : a(7) {
		std::cout << "ctor: " << this << std::endl;
	}
	~myclass() {
			std::cout << "dtor: " << this << std::endl;
	}
	void trace() const {
		std::cout << a << std::endl;
	}
};

static int my_static_func() {
	std::cout << "inside some function\n";
	return 1;
}

static const int aaa = my_static_func();

myclass myobj;

using voidptr = void *;
int main(void) {
	std::cout << "Enter main\n";

	std::cout << "Word size: " << sizeof(voidptr) << std::endl;

	/*voidptr *arr = new voidptr[7];
	std::cout << "Arr ptr: " << arr << std::endl;

	arr[0] = new int(6);
	arr[1] = new int(8);
	arr[2] = new int(9);
	arr[3] = new int(11);
	arr[4] = new int(11);
	arr[5] = new int(11);
	arr[6] = new int(11);

	void *addr = (void *)arr;
	char *trace_addr = (char *)addr;

	std::cout << "Array prebytes: \n";
	for (size_t i = 0; i < sizeof(voidptr); i++) {
		void *cur_ptr = trace_addr - i;
		unsigned char uc = *((unsigned char *)(cur_ptr));
		std::cout << cur_ptr << " " << std::hex << int(uc) << std::endl;
	}

	std::cout << "Array bytes: \n";
	for (size_t i = 0; i < (7 * sizeof(voidptr)); i++) {
		void *cur_ptr = trace_addr + i;
		unsigned char uc = *((unsigned char *)(cur_ptr));
		std::cout << cur_ptr << " " << int(uc) << std::endl;
	}


	delete [] arr;*/


	myclass *obj_arr = new myclass[5];

	for (int i = 0; i < 5; i++)
		obj_arr[i].trace();

	delete [] obj_arr;

	std::cout << "Leave main\n";

	return 0;
}
