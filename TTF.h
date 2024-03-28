#ifndef TTF_H
#define TTF_H

#include <vector>
#include <string>
#include "TTE.h"
using namespace std;
void printTimetable(const std::vector<TimetableEntry> &timetable);
vector<TimetableEntry> getTimetableForDay(const std::vector<TimetableEntry> &timetable, const std::string &day);
vector<TimetableEntry> getTimetableForTime(const std::vector<TimetableEntry> &timetable, const std::string &day, const std::string &time);
vector<TimetableEntry> getTimetableForTeacher(const std::vector<TimetableEntry>& timetable, const std::string& teacher);
vector<TimetableEntry> getTimetableForSection(const std::vector<TimetableEntry> &timetable, const std::string &section);
vector<TimetableEntry> getTimetableForRoom(const std::vector<TimetableEntry> &timetable, const std::string &room);
vector<TimetableEntry> getTimetableForStudent(const std::vector<TimetableEntry> &timetable, const std::string &student);

#endif
