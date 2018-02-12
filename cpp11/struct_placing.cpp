#include <iostream>

//#pragma pack(1) // disable padding

struct mystruct {
	char a;		// 0x0
	char b;		// 0x1
	double f;	// 0x8
	int c;		// 0x10
	char d;		// 0x14
}; // size: 24 bytes

int main(void) {
	std::cout << sizeof(mystruct) << std::endl;

	mystruct st = {0};
	std::cout << static_cast<void *>(&st.a) << std::endl;
	std::cout << static_cast<void *>(&st.b) << std::endl;
	std::cout << static_cast<void *>(&st.f) << std::endl;
	std::cout << static_cast<void *>(&st.c) << std::endl;
	std::cout << static_cast<void *>(&st.d) << std::endl;
	return 0;
}
