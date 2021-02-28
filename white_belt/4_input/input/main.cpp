#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	const string path = "output.txt";
	ofstream tmp(path);
	tmp.close();
	ofstream output(path, ios::app);
	ifstream input("input.txt");
	string line;

	if (input.is_open()){
		while (getline(input, line))
			output << line << endl;
	}
	return 0;
}
