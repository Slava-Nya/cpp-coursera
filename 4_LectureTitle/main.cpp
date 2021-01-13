#include <iostream>

using namespace std;

struct Specialization
{
	string val;

	explicit Specialization(string newVal)
	{
		val = newVal;
	}
};

struct Course
{
	string val;

	explicit Course(string newVal)
	{
		val = newVal;
	}
};

struct Week
{
	string val;

	explicit Week(string newVal)
	{
		val = newVal;
	}
};

struct LectureTitle
{
	string specialization;
	string course;
	string week;

	LectureTitle (Specialization newSpec, Course newCourse, Week newWeek)
	{
		specialization = newSpec.val;
		course = newCourse.val;
		week = newWeek.val;
	}
};

//int main()
//{
//	LectureTitle title(
//			Specialization("C++"),
//			Course("White belt"),
//			Week("4th")
//	);
//	return 0;
//}
