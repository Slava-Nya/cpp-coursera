#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

struct Student
{
	string name;
	string date;
};

static vector <string> getTokens(const string& inp)
{
	vector <string> tokens;
	string tmp;

	for (auto &i : inp)
	{
		if (i == ' ')
		{
			tokens.push_back(tmp);
			tmp = "";
		}
		else
			tmp += i;
	}
	tokens.push_back(tmp);
	return (tokens);
}

static Student	parseElement(const vector <string>& tokens)
{
	Student elem;

	elem.name = tokens[0] + " " + tokens[1];
	elem.date = tokens[2] + "." + tokens[3] + "." + tokens[4];
	return (elem);
}

static void outputData(const vector <Student>& data)
{
	int cnt;
	string cmd;
	int num;

	cin >> cnt;
	while (--cnt >= 0)
	{
		cin >> cmd;
		cin >> num;
		if ((cmd != "name" && cmd != "date") || (num > data.size() || num < 1))
			cout << "bad request" << endl;
		else if (cmd == "name")
			cout << data[num - 1].name << endl;
		else
			cout << data[num - 1].date << endl;
	}
}

int main()
{
	vector <Student> data;
	vector <string> tokens;
	string tmp;
	int cnt;

	cin >> cnt;
	cin.ignore(1);
	while (--cnt >= 0)
	{
		getline(cin, tmp, '\n');
		tokens = getTokens(tmp);
		data.push_back(parseElement(tokens));
	}
	outputData(data);
	return 0;
}
