#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

class Person {
	public:
	  void ChangeFirstName(int year, const string& first_name)
	  {
		  if (sortedFNames.count(year) == 0)
				flnames.lName = "";
		  flnames.fName = first_name;
		  sortedFNames[year] = flnames;
			  // добавить факт изменения имени на first_name в год year
	  }

	  void ChangeLastName(int year, const string& last_name)
	  {
		  if (sortedFNames.count(year) == 0)
			  flnames.fName = "";
		  flnames.lName = last_name;
		  sortedFNames[year] = flnames;
		  // добавить факт изменения фамилии на last_name в год year
	  }

	  string GetFullName(int year)
	  {
			string s1, s2 = "";

			for (auto i = sortedFNames.rbegin(); i != sortedFNames.rend(); i++)
			{
				if (i->first <= year){
					if (s1 == "" && i->second.fName.size() > 0)
						s1 = i->second.fName;
					if (s2 == "" && i->second.lName.size() > 0)
						s2 = i->second.lName;
					if (s1 > "" && s2 > "")
						return (s1 + " " + s2);
					}
			// получить имя и фамилию по состоянию на конец года year
			}
			  if (s1 > "" && s2 == "")
				  return (s1 + " with unknown last name");
			  if (s2 == "" && s1 > "")
				  return (s2 + " with unknown first name");
			  return ("Incognito");
	  }

	private:
		struct Fullname {
	  		string 	fName;
	  		string	lName;
	  };
	Fullname flnames;
	map <int, Fullname> sortedFNames;
	// приватные поля
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
