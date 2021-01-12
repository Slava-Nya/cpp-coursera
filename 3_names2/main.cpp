#include <iostream>
#include <set>
#include <map>
#include <vector>

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
			string retFName = "";
			string retLName = "";

			for (auto i = sortedFNames.rbegin(); i != sortedFNames.rend(); i++)
			{
				if (i->first <= year){
					if (retFName == "" && i->second.fName.size() > 0)
						retFName = i->second.fName;
					if (retLName == "" && i->second.lName.size() > 0)
						retLName = i->second.lName;
					if (retFName > "" && retLName > "")
						return (retFName + " " + retLName);
					}
			// получить имя и фамилию по состоянию на конец года year
			}
			  if (retFName > "" && retLName == "")
				  return (retFName + " with unknown last name");
			  if (retFName == "" && retLName > "")
				  return (retLName + " with unknown first name");
			  return ("Incognito");
	  }

	string GetFullStr(vector<string>& strs)
	{
		string ret = " (";
		int size;

		for (int i = 1; i < strs.size(); i++)
			while (strs[i] == strs[i - 1])
				strs.erase(strs.begin() + (i - 1));
		size = strs.size();
		if (size == 0)
			return ("");
		if (size == 1)
			return (strs[0]);
		for (int it = 1; it < size; it++)
		{
			if (it == size - 1)
			{
				ret += strs[it];
				ret += ")";
				break;
			}
			ret += strs[it];
			ret += ", ";
		}
		return (strs[0] + ret);
	}

	string GetFullNameWithHistory(int year)
	{
		vector <string> retFName;
		vector <string> retLName;
		string 			s1;
		string			s2;

		for (auto i = sortedFNames.rbegin(); i != sortedFNames.rend(); i++)
		{
			if (i->first <= year){
				if (i->second.fName.size() > 0)
					retFName.push_back(i->second.fName);
				if (i->second.lName.size() > 0)
					retLName.push_back(i->second.lName);
			}
		}

		s1 = GetFullStr(retFName);
		s2 = GetFullStr(retLName);
		if (s1 > "" && s2 == "")
			return (s1 + " with unknown last name");
		if (s1 == "" && s2 > "")
			return (s2 + " with unknown first name");
		if (s1 > "" && s2 > "")
			return (s1 + " " + s2);
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

//int main()
//{
//	Person person;
//
//	person.ChangeFirstName(1900, "Eugene");
//	person.ChangeLastName(1900, "Sokolov");
//	person.ChangeLastName(1910, "Sokolov");
//	person.ChangeFirstName(1920, "Evgeny");
//	person.ChangeLastName(1930, "Sokolov");
//	cout << person.GetFullNameWithHistory(1940) << endl;
//
//	return 0;
//}
