#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

void 	outputTable(map <int, vector <int >> &data)
{
	map <int, vector <int >> :: iterator it = data.begin();

	for (int i = 0; it != data.end(); it++, i++)
	{
		for (int j = 0 ; j < it->second.size(); j++)
		{
			if (j != 0)
				cout << ' ';
			cout << setw(10) << it->second[j];
		}
		if ((i + 1) != data.size())
			cout << endl;
	}
}

int main()
{
	ifstream input("input.txt");
	int n, m;
	map <int, vector <int >> data;
	int tmp;

	if (input)
	{
		input >> n;
		input.ignore(1);
		input >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				input >> tmp;
				input.ignore(1);
				data[i].push_back(tmp);
			}
		}
	}
	outputTable(data);

	return 0;
}
