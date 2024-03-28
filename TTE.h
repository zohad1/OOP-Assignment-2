#ifndef TTE_H
#define TTE_H

#include <string>
using namespace std;

class TimetableEntry {
public:
    string subject;
    string teacher;
    string room;
    string section;
    string student;
    string time;

    TimetableEntry(std::string sub, std::string tea, std::string rom, std::string sec, std::string stu, std::string tim);
};

#endif


