// MapReduce demo
// Counting words in a number of documents
// Build:
// g++ -std=c++1y -Wall -g -o test map_reduce.cpp -lpthread

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <iterator>
#include <mutex>
#include <algorithm>


static std::unordered_map<std::string, std::vector<int>> mapped_results;
static std::mutex mapped_results_mux;

static std::unordered_map<std::string, int> reduced_results;
static std::mutex reduced_results_mux;

//========================================================
//  USER DEFINED MAP AND REDUCE FUNCTIONS
//========================================================
std::pair<std::string, int> user_map_function(const std::string &file,
		const std::string &token) {
	return std::make_pair(token, 1); // EMIT(token, 1)
}

std::pair<std::string, int> user_reduce_function(const std::string &token,
		const std::vector<int> &counts) {
	int sum = 0;
	for (auto n: counts)
		sum += n;
	return std::make_pair(token, sum); // EMIT(token, sum)
}
//========================================================

std::vector<std::string> tokenize(const std::string &file) {
	std::ifstream is {file};
	std::vector<std::string> b {
		std::istream_iterator<std::string>{is},
		std::istream_iterator<std::string> {}};
	return b;
}

void mapper(const std::string &file, const std::vector<std::string> &tokens) {
	std::unordered_map<std::string, int> locally_mapped;
	for (auto token: tokens) {
		std::string no_punct_token;
		std::remove_copy_if(token.begin(), token.end(),
				std::back_inserter(no_punct_token),
				std::ptr_fun<int, int>(&std::ispunct));
		token = no_punct_token;

		auto emitted = user_map_function(file, token);
		if (locally_mapped.find(emitted.first) == locally_mapped.end())
			locally_mapped[emitted.first] = 1;
		else
			locally_mapped[emitted.first]++;
	}

	std::lock_guard<std::mutex> guard(mapped_results_mux);
	for (auto it = locally_mapped.begin(); it != locally_mapped.end(); ++it) {
		if (mapped_results.find(it->first) == mapped_results.end())
			mapped_results[it->first] = std::vector<int>();
		mapped_results[it->first].push_back(it->second);
	}
}

void reducer(const std::vector<std::pair<std::string, std::vector<int>>> &task) {
	for (auto &item: task) {
		auto emitted = user_reduce_function(item.first, item.second);

		std::lock_guard<std::mutex> guard(reduced_results_mux);
		if (reduced_results.find(emitted.first) != reduced_results.end()) {
			std::cout << "ERROR: dublication in emitted results!!!!***** "
				<< emitted.first << std::endl;
		}
		reduced_results[emitted.first] = emitted.second;
	}
}

void save_mapped_results() {
	std::lock_guard<std::mutex> guard(mapped_results_mux);
	std::ofstream mapped_file("mapped_results.dat");
	if (mapped_file.is_open()) {
		for (auto it = mapped_results.begin(); it != mapped_results.end(); ++it) {
			mapped_file << it->first << " : ";
			auto arr = it->second;
			for (auto n: arr)
				mapped_file << n << " ";
			mapped_file << std::endl;
		}
		mapped_file.close();
	}
}

void save_reduced_results() {
	std::lock_guard<std::mutex> guard(reduced_results_mux);
	std::ofstream reduced_file("reduced_results.dat");
	if (reduced_file.is_open()) {
		for (auto it = reduced_results.begin(); it != reduced_results.end(); ++it) {
			reduced_file << it->first << " : " << it->second << std::endl;
		}
		reduced_file.close();
	}
}

void process_files(const std::vector<std::string> &files) {
	// MAP phase
	// each file will be assigned to a dedicated mapper
	std::vector<std::thread> mappers;
	for (auto &file: files) {
		auto tokens = tokenize(file);

		mappers.push_back(std::thread(mapper, file, tokens));
	}

	for (auto &m: mappers)
		m.join();

	// Save intermediate results
	save_mapped_results();


	// REDUCE phase
	// total number of reducers is 7,
	// so the shuffled task will be split equally
	const size_t reducers_number = 7;
	const size_t words_number = mapped_results.size();
	const size_t words_per_reducer = words_number / (reducers_number - 1);
	std::vector<std::thread> reducers;
	std::vector<std::pair<std::string, std::vector<int>>> cur_reduce_task;
	for (auto it = mapped_results.begin(); it != mapped_results.end(); ++it) {
		cur_reduce_task.push_back(std::make_pair(it->first, it->second));
		if (cur_reduce_task.size() == words_per_reducer) {
			reducers.push_back(std::thread(reducer, cur_reduce_task));
			cur_reduce_task.clear();
		}
	}
	if (!cur_reduce_task.empty()) {
		reducers.push_back(std::thread(reducer, cur_reduce_task));
		cur_reduce_task.clear();
	}

	for (size_t i = 0; i < reducers.size(); ++i)
		reducers[i].join();

	// Save final results
	save_reduced_results();
}

int main(void) {

	/*process_files({
			"all_of_cpp",
			"bfs_dfs.cpp",
			"dining_philosopher.cpp",
			"find_path_in_field.cpp",
			"partition_list.cp"});*/

	process_files({
			"./ohenry/text01.txt",
			"./ohenry/text02.txt",
			"./ohenry/text03.txt",
			"./ohenry/text04.txt",
			"./ohenry/text05.txt"});

	return 0;
}
