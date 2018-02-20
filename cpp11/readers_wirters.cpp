#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
//#include <utility>
//#include <functional>
#include <atomic>
#include <mutex>
#include <shared_mutex>

/*
https://www.justsoftwaresolutions.co.uk/threading/locks-mutexes-semaphores.html
https://stackoverflow.com/questions/37667724/readers-writers-multithreading-in-c11

*/

static std::atomic_bool working{true};
static std::shared_timed_mutex m;
static std::mutex cout_mux;

int read[5] = {0};
int wrote[2] = {0};

void print_stats() {
	std::lock_guard<std::mutex> cout_guard(cout_mux);

	for (int i = 0; i < 60; ++i)
		std::cout << "=";
	std::cout << std::endl;

	for (int i = 0; i < 5; ++i) {
		std::cout << "r" << i << ":";
		for (int j = 0; j < read[i]; ++j)
			std::cout << "+";
		std::cout << std::endl;
	}

	for (int i = 0; i < 2; ++i) {
		std::cout << "w" << i << ":";
		for (int j = 0; j < wrote[i]; ++j)
			std::cout << "-";
		std::cout << std::endl;
	}
	std::cout << std::endl << std::flush;

	std::this_thread::sleep_for(std::chrono::milliseconds(00));
}


void reader(int n) {
	while (working) {
		{
			std::shared_lock<std::shared_timed_mutex> guard(m);
			std::cout << "Reader: " << n << std::endl;
			read[n]++;
			print_stats();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(230));
	}
}

void writer(int n) {
	while (working) {
		{
			std::lock_guard<std::shared_timed_mutex> guard(m);
			std::cout << "Writer: ***" << n << std::endl;
			wrote[n]++;
			print_stats();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(330));
	}
}


int main(void) {
	std::thread w0(writer, 0);
	std::thread w1(writer, 1);

	std::thread r0(reader, 0);
	std::thread r1(reader, 1);
	std::thread r2(reader, 2);
	std::thread r3(reader, 3);
	std::thread r4(reader, 4);


	std::this_thread::sleep_for(std::chrono::milliseconds(15 * 1000));
	std::cout << "\nHalt---------------------\n\n";
	working = false;

	r0.join();
	r1.join();
	r2.join();
	r3.join();
	r4.join();

	w0.join();
	w1.join();
	return 0;
}
