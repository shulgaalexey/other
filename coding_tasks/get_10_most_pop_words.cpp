//In a file there are 1 million words . Find 10 most frequent words in that file.
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;

bool my_sort(pair<int, string> i, pair<int, string> j) {
	return i.first > j.first;
}

vector<string> get_10_pop_words(const vector<string> &file) {

	map<string, int> m;

	for (size_t i = 0; i < file.size(); i++) {
		if (m.count(file[i]) > 0)
			m[file[i]]++;
		else
			m[file[i]] = 1;
	}

	cout << "Raw results: " << endl;
	vector<pair<int, string> > v(m.size());
	int idx = 0;
	for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it, ++idx) {
		v[idx] = pair<int, string>(it->second, it->first);
		cout << v[idx].second << ": " << v[idx].first << " times" << endl;
	}
	cout << endl;

	std::sort(v.begin(), v.end(), my_sort);

	cout << "Reduced raw results: " << endl;
	const int result_size = (v.size() < 10) ? v.size() : 10;
	vector<string> result(result_size);
	for (int i = 0; i < result_size; i++) {
		result[i] = v[i].second;
		cout << v[i].second << ": " << v[i].first << " times" << endl;
	}
	cout << endl;

	return result;
}

int main(void) {

	const string raw = "Maps are associative containers that store elements"
		"formed "
		"by a combination of a key value and a mapped value, following a "
		"specific order."
		"In a map, the key values are generally used to sort and uniquely "
		"identify the "
		"elements, while the mapped values store the content associated"
		"to this key. "
		"The types of key and mapped value may differ, and are grouped "
		"together in member "
		"Ttype value_type, which is a pair type combining both:"
		"Ttypedef pair<const Key, T> value_type;"
		"TInternally, the elements in a map are always sorted by its key "
		"following a specific "
		"Tstrict weak ordering criterion indicated by its internal "
		"comparison object (of type Compare)."
		"Tmap containers are generally slower than unordered_map "
		"containers to access "
		"Tindividual elements by their key, but they allow the direct "
		"iteration on subsets based on their order."
		"TThe mapped values in a map can be accessed directly by their "
		"corresponding key using the bracket operator ((operator[])."
		"TMaps are typically implemented as binary search trees.";

	vector<string> file;

	istringstream iss(raw);
	copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter(file));


	vector<string> top10 = get_10_pop_words(file);

	for (size_t i = 0; i < top10.size(); i++)
		cout << i << ". " << top10[i] << endl;

	return 0;
}
