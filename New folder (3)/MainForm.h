#pragma once
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <fstream> // for file I/O
#include "ViewTimetable.h"
#include "TeacherTimetable1.h"
#include "DayTimetable.h"
#include "ViewStudents.h"
#include "ViewCourses.h"
#include "ViewRooms.h"
#include "ViewTeacher.h"
#include "Section.h"
#include"Teacher.h"

namespace Assignment02 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnviewtimetable;
	private: System::Windows::Forms::Button^ btnteachertimetable;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnviewtimetable = (gcnew System::Windows::Forms::Button());
			this->btnteachertimetable = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(205, 226);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(460, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"  BAHRIA UNIVERSITY TIMETABLE SYSTEM";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// btnviewtimetable
			// 
			this->btnviewtimetable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnviewtimetable->Location = System::Drawing::Point(158, 275);
			this->btnviewtimetable->Name = L"btnviewtimetable";
			this->btnviewtimetable->Size = System::Drawing::Size(200, 30);
			this->btnviewtimetable->TabIndex = 1;
			this->btnviewtimetable->Text = L"View Timetable";
			this->btnviewtimetable->UseVisualStyleBackColor = true;
			this->btnviewtimetable->Click += gcnew System::EventHandler(this, &MainForm::btnviewtimetable_Click);
			// 
			// btnteachertimetable
			// 
			this->btnteachertimetable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnteachertimetable->Location = System::Drawing::Point(158, 325);
			this->btnteachertimetable->Name = L"btnteachertimetable";
			this->btnteachertimetable->Size = System::Drawing::Size(200, 30);
			this->btnteachertimetable->TabIndex = 2;
			this->btnteachertimetable->Text = L"Teacher Timetable";
			this->btnteachertimetable->UseVisualStyleBackColor = true;
			this->btnteachertimetable->Click += gcnew System::EventHandler(this, &MainForm::btnteachertimetable_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(158, 375);
			this->button1->MaximumSize = System::Drawing::Size(200, 30);
			this->button1->MinimumSize = System::Drawing::Size(200, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 30);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Day Timetable";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(158, 425);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 30);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Section Timetable";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(513, 425);
			this->button3->MaximumSize = System::Drawing::Size(200, 30);
			this->button3->MinimumSize = System::Drawing::Size(200, 30);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(200, 30);
			this->button3->TabIndex = 5;
			this->button3->Text = L"View Students";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(513, 375);
			this->button4->MaximumSize = System::Drawing::Size(200, 30);
			this->button4->MinimumSize = System::Drawing::Size(200, 30);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(200, 30);
			this->button4->TabIndex = 6;
			this->button4->Text = L"View Courses";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(513, 325);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(200, 30);
			this->button5->TabIndex = 7;
			this->button5->Text = L"View Rooms";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(513, 275);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(200, 30);
			this->button6->TabIndex = 8;
			this->button6->Text = L"View Teachers";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->pictureBox1->Location = System::Drawing::Point(300, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(236, 200);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainForm::pictureBox1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGreen;
			this->ClientSize = System::Drawing::Size(823, 581);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnteachertimetable);
			this->Controls->Add(this->btnviewtimetable);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(1000, 1000);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}*/
	private: System::Void btnviewtimetable_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the ViewTimetable form
		ViewTimetable^ viewTimetable = gcnew ViewTimetable();
		// Display the form
		viewTimetable->ShowDialog();
	}

	private: System::Void btnteachertimetable_Click(System::Object^ sender, System::EventArgs^ e) {
		Teacher^ teacher = gcnew Teacher();
		teacher->ShowDialog();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		DayTimetable^ dayTimetable = gcnew DayTimetable();
		dayTimetable->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Section^ section = gcnew Section();
		section->ShowDialog();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		ViewStudents^ viewStudents = gcnew ViewStudents();
		viewStudents->ShowDialog();
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

		ViewCourses^ viewCourses = gcnew ViewCourses();
		// Display the form
		viewCourses->ShowDialog();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		ViewRooms^ viewRooms = gcnew ViewRooms();
		viewRooms->ShowDialog();
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		ViewTeacher^ viewTeachers = gcnew ViewTeacher();
		viewTeachers->ShowDialog();
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Load a default image into PictureBox
			pictureBox1->Image = Image::FromFile("C:\\Users\\zuhad\\Downloads\\bahria-university-logo.png");

			// Set the PictureBox properties
			pictureBox1->SizeMode = PictureBoxSizeMode::Zoom; // Adjust the picture to fit the PictureBox
			pictureBox1->BackColor = Color::SkyBlue; // Set the background color to SkyBlue
		}
		catch (Exception^ ex) {
			// Handle the exception
			MessageBox::Show("Failed to load the default image: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}






		   array<String^>^ ReadFromFile(String^ filePath)
		   {
			   try {
				   StreamReader^ reader = gcnew StreamReader(filePath);
				   String^ content = reader->ReadToEnd();
				   reader->Close();
				   // Split the content by newline characters and remove empty entries
				   array<String^>^ lines = content->Split(gcnew array<String^>{ Environment::NewLine }, StringSplitOptions::RemoveEmptyEntries);
				   return lines;
			   }
			   catch (Exception^ ex)
			   {
				   MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return gcnew array<String^>(0); // Return an empty array if reading fails
			   }
		   }

		   // Function to generate a random timetable
		   void GenerateRandomTimetable()
		   {
			   // Seed the random number generator
			   srand(time(NULL));

			   // Read data from respective files
			   array<String^>^ days = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
			   array<String^>^ subjects = ReadFromFile("D:/FINE laptop/Assignment 0.2/Course.txt");
			   array<String^>^ teachers = ReadFromFile("D:/FINE laptop/Assignment 0.2/Teacher.txt"); // Assume only teacher names are in this file
			   array<String^>^ rooms = ReadFromFile("D:/FINE laptop/Assignment 0.2/Room.txt");
			   array<String^>^ times = { "9:00-10:00", "10:00-11:00", "11:00-12:00", "13:00-14:00", "14:00-15:00" };
			   array<String^>^ sections = { "A", "B", "C", "D", "E" };

			   // Check if any file reading failed
			   if (subjects->Length == 0 || teachers->Length == 0 || rooms->Length == 0)
			   {
				   MessageBox::Show("Failed to generate timetable. Check file paths and content.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }

			   // Save the generated timetables to a file (overwrite old data)
			   String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/timetable.txt";
			   StreamWriter^ writer = gcnew StreamWriter(filePath, false);

			   // Generate and save 10 to 12 random timetables
			   for (int i = 0; i < rand() % 3 + 15; i++) {
				   // Randomly select data
				   String^ day = days[i % days->Length]; // Ensures days are selected in order
				   String^ subject = subjects[rand() % subjects->Length];
				   String^ teacher = teachers[rand() % teachers->Length]; // Random teacher name
				   String^ section = sections[rand() % sections->Length];
				   String^ room = rooms[rand() % rooms->Length];
				   String^ time = times[i % times->Length]; // Ensures times are selected in order

				   // Write the timetable entry
				   writer->WriteLine(day + "," + subject + "," + teacher + "," + room + "," + time + "," + section);
			   }

			   writer->Close();

			   MessageBox::Show("Random timetables generated and saved to file.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		   }


		   // Event handler for button7 Click event
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		GenerateRandomTimetable();
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
