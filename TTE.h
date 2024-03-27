#ifndef TTE_H
#define TTE_H

#include <string>

class TimetableEntry {
public:
    std::string subject;
    std::string teacher;
    std::string room;
    std::string section;
    std::string student;
    std::string time;

    TimetableEntry(std::string sub, std::string tea, std::string rom, std::string sec, std::string stu, std::string tim);
};

#endif
