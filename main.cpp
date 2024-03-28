#include <iostream>
#include <vector>
#include <iomanip> // For std::setw
#include "TTE.h"
#include "TTF.h"

using namespace std;

TimetableEntry::TimetableEntry(std::string sub, std::string tea, std::string rom, std::string sec, std::string stu, std::string tim)
    : subject(sub), teacher(tea), room(rom), section(sec), student(stu), time(tim) {}

void printTimetable(const std::vector<TimetableEntry>& timetable) {
    // Print the table header
    std::cout << std::left << std::setw(12) << "Course" << std::setw(18) << "Instructor"
        << std::setw(8) << "Room" << std::setw(10) << "Student"
        << std::setw(12) << "Day" << "Time" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;

    // Print each timetable entry
    for (const auto& entry : timetable) {
        std::cout << std::left << std::setw(12) << entry.subject
            << std::setw(18) << entry.teacher
            << std::setw(8) << entry.room
            << std::setw(10) << entry.student
            << std::setw(12) << entry.time.substr(0, entry.time.find(' '))
            << entry.time.substr(entry.time.find(' ') + 1) << std::endl;
    }
}

vector<TimetableEntry> getTimetableForDay(const std::vector<TimetableEntry>& timetable, const std::string& day) {
    std::vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.time.find(day) != std::string::npos) {
            result.push_back(entry);
        }
    }
    return result;
}

vector<TimetableEntry> getTimetableForTime(const std::vector<TimetableEntry>& timetable, const std::string& day, const std::string& time) {
    std::vector<TimetableEntry> result;
    std::string target = day + " " + time;
    for (const auto& entry : timetable) {
        if (entry.time == target) {
            result.push_back(entry);
        }
    }
    return result;
}

vector<TimetableEntry> getTimetableForTeacher(const std::vector<TimetableEntry>& timetable, const std::string& teacher) {
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

vector<TimetableEntry> getTimetableForRoom(const std::vector<TimetableEntry>& timetable, const std::string& room) {
    std::vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.room == room) {
            result.push_back(entry);
        }
    }
    return result;
}

vector<TimetableEntry> getTimetableForStudent(const std::vector<TimetableEntry>& timetable, const std::string& student) {
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
        // Section A
        {"OOP", "Dr.Tamim", "417", "A", "Zohad", "Monday 9:00 AM"},
        {"OOP", "Dr.Tamim", "417", "A", "Armaghan", "Monday 9:00 AM"},
        {"Maths", "Mr. Zubair", "418", "A", "Armaghan", "Monday 11:00 AM"},
        {"Maths", "Mr. Zubair", "418", "A", "Zohad", "Monday 11:00 AM"},
        {"CP", "Dr.Raja", "418", "A", "Zohad", "Tuesday 10:30 AM"},
        {"CP", "Dr.Raja", "418", "A", "Armaghan", "Tuesday 10:30 AM"},
        {"DS", "Mr. Asim", "419", "A", "Armaghan", "Tuesday 1:00 PM"},
        {"DS", "Mr. Asim", "419", "A", "Zohad", "Tuesday 1:00 PM"},
        {"ECS", "Dr.Ahmad", "417", "A", "Zohad", "Wednesday 9:00 AM"},
		{"ECS", "Dr.Ahmad", "417", "A", "Armaghan", "Wednesday 9:00 AM"},
        {"Islamiyat", "Dr.RaheemUllah", "418", "A", "Armaghan", "Wednesday 11:00 AM"},
        {"Islamiyat", "Dr.RaheemUllah", "418", "A", "Zohad", "Wednesday 11:00 AM"},
        {"OOP LAB", "Mr.Z", "401", "A", "Zohad", "Thursday 1:00 PM"},
        {"OOP LAB", "Mr.Z", "401", "A", "Armaghan", "Thursday 1:00 PM"},
        {"DS", "Mr. Asim", "419", "A", "Armaghan", "Friday 9:00 AM"},
        {"DS", "Mr. Asim", "419", "A", "Zohad", "Friday 9:00 AM"},

        // Section B
        {"CP", "Dr.Raja", "418", "B", "Sher", "Monday 9:00 AM"},
        {"CP", "Dr.Raja", "418", "B", "Sibtain", "Monday 9:00 AM"},
        {"DS", "Mr. Asim", "419", "B", "Sibtain", "Monday 11:00 AM"},
		{"DS", "Mr. Asim", "419", "B", "Sher", "Monday 11:00 AM"},
        {"OOP", "Dr.Tamim", "417", "B", "Sher", "Tuesday 10:30 AM"},
		{"OOP", "Dr.Tamim", "417", "B", "Sibtain", "Tuesday 10:30 AM"},
        {"Maths", "Mr. Zubair", "418", "B", "Sibtain", "Tuesday 1:00 PM"},
        {"Maths", "Mr. Zubair", "418", "B", "Sher", "Tuesday 1:00 PM"},
        {"OOP LAB", "Mr.Z", "401", "B", "Sher", "Wednesday 9:00 AM"},
        {"OOP LAB", "Mr.Z", "401", "B", "Sibtain", "Wednesday 9:00 AM"},
        {"ECS", "Dr.Ahmad", "418", "B", "Sibtain", "Thursday 9:00 AM"},
        {"ECS", "Dr.Ahmad", "418", "B", "Sher", "Thursday 9:00 AM"},
        {"DS", "Mr. Asim", "419", "B", "Sher", "Thursday 11:00 AM"},
        {"DS", "Mr. Asim", "419", "B", "Sibtain", "Thursday 11:00 AM"},
        {"Islamiyat", "Dr.RaheemUllah", "417", "B", "Sibtain", "Friday 9:00 AM"},
        {"Islamiyat", "Dr.RaheemUllah", "417", "B", "Sher", "Friday 9:00 AM"},
        
    };
    int choice;
    do {
        cout << " \n";
        cout<<"====================================================================================================\n";
        cout << " \n";
        cout<<"---------------------------------Welcome to the Time Table System-----------------------------------\n";
        cout<< " \n";
        cout << "Choose from the following options:\n";
        cout << "1) Section wise time table\n";
        cout << "2) Student wise time table\n";
        cout << "3) Room wise and Lab wise\n";
        cout << "4) Day wise\n";
        cout << "5) Day and Time wise\n";
        cout << "6) Teacher wise Timetable\n";
        cout << "7) Print whole TimeTable\n";
        cout << "8) Exit\n";
        cout << "Enter option(1, 2, 3, 4, 5, 6, 8): ";
        cin >> choice;
        

        // Handle user's choice
        switch (choice)
        {
        case 1:
        {
            string section;
            cout << "Enter the section (A, B): ";
            cin >> section;

            // Get timetable for specific student section
            vector<TimetableEntry> timetableForSection = getTimetableForSection(timetable, section);
            cout << "\nTimetable for section " << section << ":\n";
            printTimetable(timetableForSection);
            break;

        }
        case 2:
        {
            string student;
            cout << "Enter the student name (Zohad, Armaghan, Sher, Sibtain): ";
            cin >> student;

            // Get timetable for specific student
            vector<TimetableEntry> timetableForStudent = getTimetableForStudent(timetable, student);
            cout << "\nStudents timetable " << student << ":\n";
            printTimetable(timetableForStudent);
           

            break;
        }

        case 3:
        {
            string room;
            cout << "Enter the room (417, 418, 419, 401, 4): ";
            cin >> room;

            // Get timetable for specific room
            vector<TimetableEntry> timetableForRoom = getTimetableForRoom(timetable, room);
            cout << "\nTimetable for room " << room << ":\n";
            printTimetable(timetableForRoom);
            

            break;
        }
        case 4:
        {
            string day;
            cout << "Enter the day (Monday, Tuesday, etc.): ";
            cin >> day;

            // Get timetable for specific day
            vector<TimetableEntry> timetableForDay = getTimetableForDay(timetable, day);
            cout << "\nTimetable for " << day << ":\n";
            printTimetable(timetableForDay);
            break;
        }
        case 5:
        {
            string day, time;
            cout << "Enter the day (Monday, Tuesday, Wednesday, Thursday, Friday): ";
            cin >> day;
            cout << "Enter the time ( 9:00 AM, 11:00 AM): ";
            cin.ignore();
            getline(cin, time);
            vector<TimetableEntry> timetableForTime = getTimetableForTime(timetable, day, time);
            cout << "\nTimetable for " << day << " at " << time << ":\n";
            printTimetable(timetableForTime);
            break;
        }
        case 6: {
            string teacher;
            cout << "Enter the teacher name: ";
            cin >> teacher;

            // Get timetable for specific teacher
            vector<TimetableEntry> timetableForTeacher = getTimetableForTeacher(timetable, teacher);
            cout << "\nTimetable for teacher " << teacher << ":\n";
            printTimetable(timetableForTeacher);
            break;
        }

        case 7:
            printTimetable(timetable);
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
        system("pause");
        system("cls");
    } while (choice != 8);

    return 0;
}
