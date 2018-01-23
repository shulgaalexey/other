#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

int main() {
	std::string from;
	std::string to;

	// Get source and target file names
	//std::cin >> from >> to;
	//from = "README.md";
	from = "std_algorithms.cpp";
	to = "res.dat";

	std::ifstream is {from};
	std::istream_iterator<std::string> ii {is};
	std::istream_iterator<std::string> eos {};

	std::ofstream os {to};
	std::ostream_iterator<std::string> oo {os, "\n"};

	std::vector<std::string> b {ii, eos};

	std::sort(b.begin(), b.end());

	std::unique_copy(b.begin(), b.end(), oo);

	return !is.eof() || !os;
}
