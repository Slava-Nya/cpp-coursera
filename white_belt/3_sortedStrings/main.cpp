#include <iostream>
#include <vector>

using namespace std;

class SortedStrings
{
	public:
		void AddString(const string& s) {
			strs.push_back(s);
			// добавить строку s в набор
		}
		vector<string> GetSortedStrings() {
			sort(strs.begin(), strs.end());
			return (strs);
			// получить набор из всех добавленных строк в отсортированном порядке
		}
	private:
		vector <string> strs;
		// приватные поля
};

//void PrintSortedStrings(SortedStrings& strings) {
//	for (const string& s : strings.GetSortedStrings()) {
//		cout << s << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	SortedStrings strings;
//
//	strings.AddString("first");
//	strings.AddString("third");
//	strings.AddString("second");
//	PrintSortedStrings(strings);
//
//	strings.AddString("second");
//	PrintSortedStrings(strings);
//
//	return 0;
//}

