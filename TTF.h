#ifndef TTF_H
#define TTF_H

#include <vector>
#include <string>
#include "TTE.h"

void printTimetable(const std::vector<TimetableEntry> &timetable);
std::vector<TimetableEntry> getTimetableForDay(const std::vector<TimetableEntry> &timetable, const std::string &day);
std::vector<TimetableEntry> getTimetableForTime(const std::vector<TimetableEntry> &timetable, const std::string &day, const std::string &time);
std::vector<TimetableEntry> getTimetableForTeacher(const std::vector<TimetableEntry>& timetable, const std::string& teacher);
std::vector<TimetableEntry> getTimetableForSection(const std::vector<TimetableEntry> &timetable, const std::string &section);
std::vector<TimetableEntry> getTimetableForRoom(const std::vector<TimetableEntry> &timetable, const std::string &room);


#endif
