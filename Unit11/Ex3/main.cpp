#include <fstream>
#include <string>
#include <iostream>

bool check_if_vowel(char c);

int main()
{
	std::fstream fs( "f1.txt", std::ios::in| std::ios::out);
	if (!fs)
	{
		std::cerr << "couldn't open file";
	}
	//std::string s;
	char temp;

	//fs.seekp(0, fs.end);
	std::string st;
	std::getline(fs, st);
	unsigned int ind = st.size();
	//fs.seekp(0, fs.beg);

	for (unsigned int i{}; i < ind; ++i)
	{
		fs.seekg(i);
		fs >> temp;
		if (check_if_vowel(temp))
		{
			fs.seekp(i);
			fs.write("", 1);
		}
		else
		{
			fs.putback(temp);
		}
	}
	std::string s;
	fs.seekg(0);
	std::getline(fs, s);
	std::cout << s;
}

bool check_if_vowel(char c)
{
	switch (c)
	{
	case 'o':case 'O':case 'E':case 'e':case 'a':case 'A':
	case 'I':case 'i':case 'u':case 'U':case 'y':case 'Y':
	{
		return true;
	}
	default:
		return false;
	}
}