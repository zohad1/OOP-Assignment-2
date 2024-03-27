#include <iostream>
#include <vector>
#include "TTE.h"
#include "TTF.h"

using namespace std;
TimetableEntry::TimetableEntry(std::string sub, std::string tea, std::string rom, std::string sec, std::string stu, std::string tim)
    : subject(sub), teacher(tea), room(rom), section(sec), student(stu), time(tim) {}

void printTimetable(const std::vector<TimetableEntry>& timetable) {
    std::cout << "Timetable:\n";
    for (const auto& entry : timetable) {
        std::cout << "Subject: " << entry.subject << ", Teacher: " << entry.teacher
            << ", Room: " << entry.room << ", Section: " << entry.section
            << ", Student: " << entry.student << ", Time: " << entry.time << std::endl;
    }
}




std::vector<TimetableEntry> getTimetableForTime(const std::vector<TimetableEntry>& timetable, const std::string& day, const std::string& time) {
    std::vector<TimetableEntry> result;
    std::string target = day + " " + time;
    for (const auto& entry : timetable) {
        if (entry.time == target) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<TimetableEntry> getTimetableForTeacher(const std::vector<TimetableEntry>& timetable, const std::string& teacher) {
    std::vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.teacher == teacher) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<TimetableEntry> getTimetableForSection(const std::vector<TimetableEntry>& timetable, const std::string& section) {
    std::vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.section == section) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<TimetableEntry> getTimetableForRoom(const std::vector<TimetableEntry>& timetable, const std::string& room) {
    std::vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.room == room) {
            result.push_back(entry);
        }
    }
    return result;
}

std::vector<TimetableEntry> getTimetableForStudent(const std::vector<TimetableEntry>& timetable, const std::string& student) {
    std::vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.student == student) {
            result.push_back(entry);
        }
    }
    return result;
}

int main()
{
    // Sample timetable entries
    vector<TimetableEntry> timetable = {
        {"OOP", "Dr.Tamim", "417", "A", "Zohad", "Monday 9:00 AM"},
        {"CP", "Dr.Raja", "418", "B", "Armaghan", "Monday 10:30 AM"},
        {"ISLAMIYAT", "Dr.Raheem", "419", "C", "Sher", "Tuesday 1:00 PM"},
        {"QURANICSTUDIES", "Dr.RaheemUllah", "417", "D", "Sibain", "Tuesday 2:30 PM"},
        {"OOP", "Dr.Tamim", "418", "E", "Abdullah", "Wednesday 4:00 PM"},
        {"QURANICSTUDIES", "Dr.RaheemUllah", "417", "A", "Zohad", "Wednesday 9:00 AM"},
        {"ISLAMIYAT", "Dr.Tamim", "418", "B", "Armaghan", "Thursday 10:30 AM"},
        {"MATHS", "Mr.Zubair", "419", "C", "Sher", "Thursday 1:00 PM"},
        {"CP", "Dr.Raja", "417", "D", "Sibtain", "Friday 2:30 PM"},
        {"CP", "Dr.Raja", "418", "E", "Abdullah", "Friday 4:00 PM"}
        // Add more entries as needed
    };

    // Get user's choice
    char choice;
    cout << "Choose from the following options:\n";
    cout << "a. Section wise time table\n";
    cout << "b. Student wise time table\n";
    cout << "c. Room wise and Lab wise\n";
    cout << "d. Day wise\n";
    cout << "e. Day and Time wise\n";
    cout << "f. Teacher wise Timetable\n";
    cout << "g. Print whole TimeTable\n";
    cout << "Enter your choice (a, b, c, d, e, f): ";
    cin >> choice;

    // Handle user's choice
    switch (choice)
    {
    case 'a':
    {
        // Get input for section
        string section;
        cout << "Enter the section (A, B, C, D, E): ";
        cin >> section;

        // Get timetable for specific student section
        vector<TimetableEntry> timetableForSection = getTimetableForSection(timetable, section);
        cout << "\nTimetable for section " << section << ":\n";
        printTimetable(timetableForSection);
        break;
    }
    case 'b':
    {
        // Get input for student name
        string student;
        cout << "Enter the student name (Zohad, Armaghan, Sher, Sibtain, Abdullah): ";
        cin >> student;

        // Get timetable for specific student
        vector<TimetableEntry> timetableForStudent = getTimetableForStudent(timetable, student);
        cout << "\nStudents timetable " << student << ":\n";
        printTimetable(timetableForStudent);
        break;
    }

    case 'c':
    {
        // Get input for room
        string room;
        cout << "Enter the room (417, 418, 419, 401, 402): ";
        cin >> room;

        // Get timetable for specific room
        vector<TimetableEntry> timetableForRoom = getTimetableForRoom(timetable, room);
        cout << "\nTimetable for room " << room << ":\n";
        printTimetable(timetableForRoom);
        break;
    }
    case 'd':
    {
        // Get input for day
        string day;
        cout << "Enter the day (Monday, Tuesday, etc.): ";
        cin >> day;

        // Get timetable for specific day
        vector<TimetableEntry> timetableForDay = getTimetableForDay(timetable, day);
        cout << "\nTimetable for " << day << ":\n";
        printTimetable(timetableForDay);
        break;
    }
    case 'e':
    {
        string day, time;
        cout << "Enter the day (Monday, Tuesday, etc.): ";
        cin >> day;
        cout << "Enter the time (e.g., 9:00 AM, 10:30 AM, etc.): ";
        cin.ignore();
        getline(cin, time);
        vector<TimetableEntry> timetableForTime = getTimetableForTime(timetable, day, time);
        cout << "\nTimetable for " << day << " at " << time << ":\n";
        printTimetable(timetableForTime);
        break;
    }
    case 'f': {
            // Get input for teacher name
            string teacher;
            cout << "Enter the teacher name: ";
            cin >> teacher;

            // Get timetable for specific teacher
            vector<TimetableEntry> timetableForTeacher = getTimetableForTeacher(timetable, teacher);
            cout << "\nTimetable for teacher " << teacher << ":\n";
            printTimetable(timetableForTeacher);
            break;
        }

    case 'g':
        printTimetable(timetable);
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    return 0;
}

