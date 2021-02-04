#include <iostream>
#include <sstream>

using namespace std;

void EnsureEqual(const string& left, const string& right)
{
	stringstream s;

	if (left != right)
	{
		s << left << " != " << right;
		throw runtime_error(s.str());
	}
}

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}