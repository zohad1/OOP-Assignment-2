#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <Windows.h>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;


namespace Assignment02 {

    public ref class DayTimetable : public Form
    {
    public:
        DayTimetable(void)
        {
            InitializeComponent();
        }

    protected:
        ~DayTimetable()
        {
            if (components != nullptr)
            {
                delete components;
            }
        }

    private:
        void InitializeComponent(void)
        {
            this->label1 = (gcnew Label());
            this->textBox1 = (gcnew TextBox());
            this->button1 = (gcnew Button());
            this->dataGridView1 = (gcnew DataGridView());
            this->SuspendLayout();

            // Form Settings
            this->AutoSize = true;
            this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->BackColor = Color::White;
            this->Text = "Day Timetable";
            this->MaximumSize = System::Drawing::Size(400, 750);
            this->MinimumSize = System::Drawing::Size(400, 300);

            // Label
            this->label1->AutoSize = true;
            this->label1->Location = Point(12, 15);
            this->label1->Text = "Enter Day:";
            this->Controls->Add(this->label1);

            // TextBox
            this->textBox1->Location = Point(12, 40);
            this->textBox1->Size = System::Drawing::Size(200, 22);
            this->Controls->Add(this->textBox1);

            // Button
            this->button1->Location = Point(220, 40);
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->Text = "OK";
            this->button1->Click += gcnew EventHandler(this, &DayTimetable::button1_Click);
            this->Controls->Add(this->button1);

            // DataGridView
            this->dataGridView1->Location = Point(12, 70);
            this->dataGridView1->Size = System::Drawing::Size(350, 200);
            this->dataGridView1->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AllowUserToDeleteRows = false;
            this->Controls->Add(this->dataGridView1);

            // Event Handlers
            this->Load += gcnew EventHandler(this, &DayTimetable::DayTimetable_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void PopulateDataGridView(String^ day)
        {
            try {
                String^ filePath = "D:/timetable.txt";
                StreamReader^ reader = gcnew StreamReader(filePath);
                array<String^>^ columnHeadings = { "Day", "Course", "Teacher", "Time", "Room", "Section" };

                // Clear existing columns and rows
                dataGridView1->Columns->Clear();
                dataGridView1->Rows->Clear();

                // Add columns to DataGridView
                for (int i = 0; i < columnHeadings->Length; i++) {
                    dataGridView1->Columns->Add(gcnew DataGridViewTextBoxColumn());
                    dataGridView1->Columns[i]->HeaderText = columnHeadings[i];
                }

                // Read lines and add data to DataGridView
                String^ line;
                while ((line = reader->ReadLine()) != nullptr) {
                    array<String^>^ data = line->Split(',');
                    if (data->Length > 0 && data[0]->Trim()->Equals(day)) {
                        dataGridView1->Rows->Add(data);
                    }
                }

                reader->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ day = textBox1->Text->Trim();
            if (!String::IsNullOrEmpty(day)) {
                PopulateDataGridView(day);
            }
            else {
                MessageBox::Show("Please enter a day.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void DayTimetable_Load(System::Object^ sender, System::EventArgs^ e) {
            // Optional: Perform any initialization here
        }

    private:
        Label^ label1;
        TextBox^ textBox1;
        Button^ button1;
        DataGridView^ dataGridView1;
        System::ComponentModel::Container^ components;
    };
}
