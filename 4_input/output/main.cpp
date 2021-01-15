#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("input.txt");
	string line;

	while (input.is_open() && getline(input, line))
		cout << line << endl;
	return 0;
}
