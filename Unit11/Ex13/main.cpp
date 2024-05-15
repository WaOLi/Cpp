#include "std_lib_facilities.h"


int main()
{
	string file_name{ "f1.txt" }, full, temp_s;
	char temp;

	ifstream ifs{file_name};
	ifs >> noskipws;

	while (ifs >> temp)
	{
		full += temp;
	}
	vector<string> words;
	istringstream iss{ full };

	ofstream ofs{"f2.txt"};
	while (iss >> temp_s)
	{
		words.push_back(temp_s);
	}
	for (int ind{}; ind < words.size(); ind++)
	{
		ofs << words[words.size() - 1 - ind];
		ofs << ' ';
	}
}
