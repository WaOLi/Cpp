#include "../tester/std_lib_facilities.h"


int main()
{
	ifstream ifs{ "f1.txt" };
	if (!ifs)
	{
		cerr << "couldn't open file";
	}

	string word, line;
	cout << "enter word to search: ";
	cin >> word;

	if (word.size() < 1)
	{
		cerr << "word too short";
	}
	int counter{};
	while (getline(ifs, line))
	{
		counter++;
		if (line.find(word) != std::string::npos)
		{
			cout << line << ':' << " line number " << counter << endl;
		}
	}
}