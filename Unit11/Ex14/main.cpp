#include "std_lib_facilities.h"

int main()
{
	int spaces{}, alphas{}, digits{}, capital_alphas{}, lower_alphas{},
		alphanumericals{}, control_chracters{}, punctuations{}, printables{}, non_spaces{};

	std::string file_name{ "f1.txt" };
	ifstream ifs{ file_name };
	char temp;

	ifs >> noskipws;

	while (ifs >> temp)
	{
		if (isspace(temp))
		{
			spaces++;
		}
		if (isalpha(temp))
		{
			alphas++;
		}
		if (isdigit(temp))
		{
			digits++;
		}
		if (isupper(temp))
		{
			capital_alphas++;
		}
		if (islower(temp))
		{
			lower_alphas++;
		}
		if (isalnum(temp))
		{
			alphanumericals++;
		}
		if (iscntrl(temp))
		{
			control_chracters++;
		}
		if (ispunct(temp))
		{
			punctuations++;
		}
		if (isprint(temp))
		{
			printables++;
		}
		if (isgraph(temp))
		{
			non_spaces++;
		}
	}

	cout << spaces << " spaces" << endl
		<< alphas << " alphas" << endl
		<< digits << " digits" << endl
		<< capital_alphas << " capital alphas" << endl
		<< lower_alphas << " lower alphas" << endl
		<< alphanumericals << " alphanumericals" << endl
		<< control_chracters << " conrol characters" << endl
		<< punctuations << " punctuations" << endl
		<< printables << " printable" << endl
		<< non_spaces << " non space" << endl;
}