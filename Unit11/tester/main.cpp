#include "std_lib_facilities.h"

int main()
{
	//I
	/*std::fstream fs{ "f1.txt", std::ios_base::in | std::ios_base::out };

	std::ofstream ofs{ "f2.txt", std::ios_base::out };

	if (!fs || !ofs)
	{
		std::cout << "couldn't open file";
	}
	ofs << showbase << hex;
	for (unsigned int i{}; fs.read(as_bytes(i), sizeof(int)); )
	{
		ofs << i << '\n';
	}*/


	//II
	/*stringstream ss{};
	string s;
	if (ss >> s)
	{
		cout << "success";
	}
	else
	{
		cout << "unsuccess\n";
		if (ss.bad())
		{
			cout << "ss is bad";
		}
		else if(ss.fail())
		{
			cout << "ss is fail";
		}
		else if (ss.eof())
		{
			cout << "end of file";
		}
	}
	s = "hello";
	ss.str(s);
	string temp;
	if (ss.fail())
		ss.clear();
	if (ss >> s)
	{
		cout << s;
	}
	else
	{
		
		cout << "can't print";
	}*/

	//III
	/*int birth_year{ 1994 };

	std::cout << showbase << "dec:\t" << dec << setw(5) << birth_year << endl
		<< "hex:\t" << hex << birth_year << endl
		<< "oct:\t" << oct << birth_year << endl;*/

	//IV
	double d{ 1234567.89 };
	cout << d;
}