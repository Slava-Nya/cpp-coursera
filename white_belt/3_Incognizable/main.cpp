#include <iostream>
#include <vector>

using namespace std;

class Incognizable{
public:
	Incognizable()
	{
		data = {};
	}
	Incognizable(const int& input)
	{
		data.push_back(input);
	}
	Incognizable(const int& input1, const int& input2)
	{
		data.push_back(input1);
		data.push_back(input2);
	}

private:
	vector<int> data;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}