#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits> // for std::numeric_limits

using namespace std;

class Student {
public:
    string section;
    string name;

    Student(string section, string name) : section(section), name(name) {}
};

class Teacher {
public:
    string name;

    Teacher(string name) : name(name) {}
};

class Room {
public:
    string number;
    bool is_lab;

    Room(string number, bool is_lab = false) : number(number), is_lab(is_lab) {}
};

class Course {
public:
    string name;
    Teacher* teacher;
    vector<Student*> students;
    Room* room;
    string day;
    string start_time;
    string end_time;

    Course(string name, Teacher* teacher, vector<Student*> students, Room* room, string day, string start_time, string end_time)
        : name(name), teacher(teacher), students(students), room(room), day(day), start_time(start_time), end_time(end_time) {}
};

class Timetable {
public:
    vector<Course*> courses;
    vector<Student*> students;
    vector<Teacher*> teachers;
    vector<Room*> rooms;

    void add_course(Course* course) {
        courses.push_back(course);
    }

    void add_student(Student* student) {
        students.push_back(student);
    }

    void add_teacher(Teacher* teacher) {
        teachers.push_back(teacher);
    }

    void add_room(Room* room) {
        rooms.push_back(room);
    }

    void remove_course(Course* course) {
        courses.erase(remove(courses.begin(), courses.end(), course), courses.end());
        delete course;
    }

    void remove_student(Student* student) {
        students.erase(remove(students.begin(), students.end(), student), students.end());
        delete student;
    }

    void remove_teacher(Teacher* teacher) {
        teachers.erase(remove(teachers.begin(), teachers.end(), teacher), teachers.end());
        delete teacher;
    }

    void remove_room(Room* room) {
        rooms.erase(remove(rooms.begin(), rooms.end(), room), rooms.end());
        delete room;
    }

    vector<Course*> teacher_timetable(string teacher_name) {
        vector<Course*> teacher_schedule;
        for (Course* course : courses) {
            if (course->teacher->name == teacher_name) {
                teacher_schedule.push_back(course);
            }
        }
        return teacher_schedule;
    }

    vector<Course*> section_timetable(string section) {
        vector<Course*> section_schedule;
        for (Course* course : courses) {
            for (Student* student : course->students) {
                if (student->section == section) {
                    section_schedule.push_back(course);
                    break;
                }
            }
        }
        return section_schedule;
    }

    vector<Course*> room_timetable(string room_number) {
        vector<Course*> room_schedule;
        for (Course* course : courses) {
            if (course->room->number == room_number) {
                room_schedule.push_back(course);
            }
        }
        return room_schedule;
    }

    vector<Course*> lab_timetable() {
        vector<Course*> lab_schedule;
        for (Course* course : courses) {
            if (course->room->is_lab) {
                lab_schedule.push_back(course);
            }
        }
        return lab_schedule;
    }

    vector<Course*> day_timetable(string day) {
        vector<Course*> day_schedule;
        for (Course* course : courses) {
            if (course->day == day) {
                day_schedule.push_back(course);
            }
        }
        return day_schedule;
    }

    Course* get_course_at_time(string day, string time) {
        for (Course* course : courses) {
            if (course->day == day && course->start_time == time) {
                return course;
            }
        }
        return nullptr;
    }

    bool validate_teacher_name(string teacher_name) {
        vector<string> valid_teacher_names = { "Tamim", "Waleed", "Awais" };
        return find(valid_teacher_names.begin(), valid_teacher_names.end(), teacher_name) != valid_teacher_names.end();
    }

    bool validate_course_name(string course_name) {
        vector<string> valid_course_names = { "OOP", "ISE", "LA" };
        return find(valid_course_names.begin(), valid_course_names.end(), course_name) != valid_course_names.end();
    }

    bool validate_student_name(string student_name) {
        vector<string> valid_student_names = { "Zohad", "Armaghan", "Jibran", "Sami", "Wajiha" };
        return find(valid_student_names.begin(), valid_student_names.end(), student_name) != valid_student_names.end();
    }

    bool validate_section_name(string section_name) {
        vector<string> valid_section_names = { "BSE 1B", "BSE 2B", "BSE 3B", "BSE 4B", "BSE 5B" };
        return find(valid_section_names.begin(), valid_section_names.end(), section_name) != valid_section_names.end();
    }
};

int main() {
    Timetable timetable;

    // Sample usage - Adding data
    Teacher* se_teacher = new Teacher("Waleed");
    Room* se_room = new Room("SE Room");
    timetable.add_teacher(se_teacher);
    timetable.add_room(se_room);
    vector<Student*> se_students = { new Student("BSE 1B", "Zohad"), new Student("BSE 2B", "Armaghan"), new Student("BSE 3B", "Jibran") };
    Course* se_course = new Course("OOP", se_teacher, se_students, se_room, "Monday", "08:30", "10:00");
    timetable.add_course(se_course);

    // Interaction with user
    cout << "Welcome to the timetabling system!" << endl;

    while (true) {
        cout << "\nOptions:\n1. View Teacher Timetable\n2. View Section Timetable\n3. View Room Timetable\n4. Delete Course\n5. Delete Student\n6. Delete Teacher\n7. Delete Room\n8. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter teacher name: ";
            string teacher_name;
            cin >> teacher_name;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            if (!timetable.validate_teacher_name(teacher_name)) {
                cout << "Invalid teacher name." << endl;
                break;
            }
            vector<Course*> teacher_schedule = timetable.teacher_timetable(teacher_name);
            //
                            // Display teacher schedule
               // Display teacher schedule
            cout << "Teacher Schedule for " << teacher_name << ":" << endl;
            for (Course* course : teacher_schedule) {
                cout << "Course: " << course->name << ", Day: " << course->day << ", Time: " << course->start_time << " - " << course->end_time << ", Room: " << course->room->number << endl;
            }

            break;
        }
        case 2: {
            cout << "Enter section: ";
            string section;
            cin >> section;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            if (!timetable.validate_section_name(section)) {
                cout << "Invalid section name." << endl;
                break;
            }
            vector<Course*> section_schedule = timetable.section_timetable(section);
            // Display section schedule
            // Add code to display section schedule based on vector<Course*> section_schedule
            break;
        }
        case 3: {
            cout << "Enter room number: ";
            string room_number;
            cin >> room_number;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            // Check room existence
            vector<Course*> room_schedule = timetable.room_timetable(room_number);
            // Display room schedule
            // Add code to display room schedule based on vector<Course*> room_schedule
            break;
        }
        case 4: {
            cout << "Enter course name to delete: ";
            string course_name;
            cin >> course_name;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            if (!timetable.validate_course_name(course_name)) {
                cout << "Invalid course name." << endl;
                break;
            }
            // Find course and delete
            // Add code to find and delete the course with given name
            break;
        }
        case 5: {
            cout << "Enter student name to delete: ";
            string student_name;
            cin >> student_name;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            if (!timetable.validate_student_name(student_name)) {
                cout << "Invalid student name." << endl;
                break;
            }
            // Find student and delete
            // Add code to find and delete the student with given name
            break;
        }
        case 6: {
            cout << "Enter teacher name to delete: ";
            string teacher_name;
            cin >> teacher_name;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            if (!timetable.validate_teacher_name(teacher_name)) {
                cout << "Invalid teacher name." << endl;
                break;
            }
            // Find teacher and delete
            // Add code to find and delete the teacher with given name
            break;
        }
        case 7: {
            cout << "Enter room number to delete: ";
            string room_number;
            cin >> room_number;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            // Check room existence
            // Delete room
            // Add code to find and delete the room with given number 
            break;
        }
        case 8: {
            cout << "Exiting program." << endl;
            return 0;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}

