#include <iostream>
#include<string>
#include<sstream>
#include <vector>
#include <iomanip>
#include<fstream>
#include "TTE.h"
#include "TTF.h"

using namespace std;

TimetableEntry::TimetableEntry(string sub, string tea, string rom, string sec, string stu, string tim)
    : subject(sub), teacher(tea), room(rom), section(sec), student(stu), time(tim) {}


void saveTimetableToFile(const vector<TimetableEntry>& timetable) {
    ofstream outFile("timetable.txt");
    if (outFile.is_open()) {
        for (const auto& entry : timetable) {
            outFile << entry.subject << ","
                << entry.teacher << ","
                << entry.room << ","
                << entry.section << ","
                << entry.student << ","
                << entry.time << "\n";
        }
        outFile.close();
        cout << "Timetable saved to file successfully.\n";
    }
    else {
        cout << "Unable to open file for writing.\n";
    }
}

bool loadTimetableFromFile(vector<TimetableEntry>& timetable, const string& filePath) {
    ifstream inFile(filePath);
    string line;
    string subject, teacher, room, section, student, time;

    // Check if we can open the file
    if (!inFile.is_open()) {
        cout << "Unable to open file for reading.\n";
        return false;
    }

    // Clear existing entries in the timetable
    timetable.clear();

    while (getline(inFile, line)) {
        stringstream ss (line);
        getline(ss, subject, ',');
        getline(ss, teacher, ',');
        getline(ss, room, ',');
        getline(ss, section, ',');
        getline(ss, student, ',');
        getline(ss, time);

        // Create a new TimetableEntry object and add it to the vector
        TimetableEntry entry(subject, teacher, room, section, student, time);
        timetable.push_back(entry);
    }

    inFile.close();
    return true;
}



void printTimetable(const vector<TimetableEntry>& timetable) {
    // Print the table header
    cout << left << setw(12) << "Course" << setw(18) << "Instructor"
        << setw(8) << "Room" << setw(10) << "Student"
        << setw(12) << "Day" << "Time" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    // Print each timetable entry
    for (const auto& entry : timetable) {
        cout << left << setw(12) << entry.subject
            << setw(18) << entry.teacher
            << setw(8) << entry.room
            << setw(10) << entry.student
            << setw(12) << entry.time.substr(0, entry.time.find(' '))
            << entry.time.substr(entry.time.find(' ') + 1) << endl;
    }
}

vector<TimetableEntry> getTimetableForDay(const vector<TimetableEntry>& timetable, const string& day) {
    vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.time.find(day) != string::npos) {
            result.push_back(entry);
        }
    }
    return result;
}

vector<TimetableEntry> getTimetableForTime(const vector<TimetableEntry>& timetable, const string& day, const string& time) {
    vector<TimetableEntry> result;
    string target = day + " " + time;
    for (const auto& entry : timetable) {
        if (entry.time == target) {
            result.push_back(entry);
        }
    }
    return result;
}

vector<TimetableEntry> getTimetableForTeacher(const vector<TimetableEntry>& timetable, const string& teacher) {
    vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.teacher == teacher) {
            result.push_back(entry);
        }
    }
    return result;
}

vector<TimetableEntry> getTimetableForSection(const vector<TimetableEntry>& timetable, const string& section) {
    vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.section == section) {
            result.push_back(entry);
        }
    }
    return result;
}

vector<TimetableEntry> getTimetableForRoom(const vector<TimetableEntry>& timetable, const string& room) {
    vector<TimetableEntry> result;
    for (const auto& entry : timetable) {
        if (entry.room == room) {
            result.push_back(entry);
        }
    }
    return result;
}

vector<TimetableEntry> getTimetableForStudent(const vector<TimetableEntry>& timetable, const string& student) {
    vector<TimetableEntry> result;
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
    vector<TimetableEntry> timetable; 

     


    if(!loadTimetableFromFile(timetable, "timetable.txt")) {
        cout << "Failed to load timetable from file. Starting with an empty timetable.\n";
    }

    int choice;
    do {
        cout << " \n";
        cout << "====================================================================================================\n";
        cout << " \n";
        cout << "---------------------------------Welcome to the Time Table System-----------------------------------\n";
        cout << " \n";
        cout << "Choose from the following options:\n";
        cout << "1) Section wise time table\n";
        cout << "2) Student wise time table\n";
        cout << "3) Room wise and Lab wise\n";
        cout << "4) Day wise\n";
        cout << "5) Day and Time wise\n";
        cout << "6) Teacher wise Timetable\n";
        cout << "7) Print whole TimeTable\n";
        cout << "8) Update timetable\n";
        cout << "9) Exit\n";
        cout << "Enter option(1, 2, 3, 4, 5, 6, 8): ";
        cin >> choice;


        // Handle user's choice
        switch (choice)
        {
        case 1: {
            string section;
            cout << "Enter the section (A, B): ";
            cin >> section;

            // Validate input
            if (section == "A" || section == "B") {
                // Get timetable for specific student section
                vector<TimetableEntry> timetableForSection = getTimetableForSection(timetable, section);
                cout << "\nTimetable for section " << section << ":\n";
                printTimetable(timetableForSection);
            }
            else {
                cout << "Wrong input. Please enter either 'A' or 'B'.\n";
            }
            break;
        }
        case 2: {
            string student;
            cout << "Enter the student name (Zohad, Armaghan, Sher, Sibtain): ";
            cin >> student;
            if (student == "Zohad" || student == "Armaghan" || student == "Sher" || student == "Sibtain") {

                vector<TimetableEntry> timetableForStudent = getTimetableForStudent(timetable, student);
                cout << "\nStudents timetable " << student << ":\n";
                printTimetable(timetableForStudent);
            }
            else {
                cout << "Wrong input. Please enter a valid student name.\n";
            }

            break;
        }
        case 3: {
            string room;
            cout << "Enter the room (417, 418, 419, 401, 4): ";
            cin >> room;
            if (room == "417" || room == "418" || room == "419" || room == "401" || room == "4") {

                vector<TimetableEntry> timetableForRoom = getTimetableForRoom(timetable, room);
                cout << "\nTimetable for room " << room << ":\n";
                printTimetable(timetableForRoom);
            }
            else {
                cout << "Wrong input. Please enter a valid room number.\n";
            }

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
            timetable = {
                // Section A
                {"OOP", "Dr.Tamim", "417", "A", "Rehan", "Monday 9:00 AM"},
                {"OOP", "Dr.Tamim", "417", "A", "Ahmed", "Monday 9:00 AM"},
                {"Maths", "Mr. Zubair", "418", "A", "Ahmed", "Monday 11:00 AM"},
                {"Maths", "Mr. Zubair", "418", "A", "Zeshan", "Monday 11:00 AM"},
                {"CP", "Dr.Raja", "418", "A", "Zeshan", "Tuesday 10:30 AM"},
                {"CP", "Dr.Raja", "418", "A", "Ahmed", "Tuesday 10:30 AM"},
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
            saveTimetableToFile(timetable);
            break;
        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
        system("pause");
        system("cls");
    } while (choice != 9);

    return 0;
}
