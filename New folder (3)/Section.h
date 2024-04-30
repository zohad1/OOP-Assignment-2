#pragma once

#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>

namespace Assignment02 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;
    using namespace msclr::interop;

    public ref class Section : public System::Windows::Forms::Form
    {
    public:
        Section(void)
        {
            InitializeComponent();
        }

    protected:
        ~Section()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Panel^ panel1;
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::Color::Black;
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->ForeColor = System::Drawing::Color::White;
            this->textBox1->Location = System::Drawing::Point(235, 133);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(309, 15);
            this->textBox1->TabIndex = 0;
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Black;
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(321, 177);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 1;
            this->button1->Text = L"OK";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &Section::button1_Click);
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(161, 260);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(422, 325);
            this->dataGridView1->TabIndex = 2;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Section::dataGridView1_CellContentClick);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(176, 132);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(53, 16);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Search:";
            this->label1->Click += gcnew System::EventHandler(this, &Section::label1_Click);
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::White;
            this->panel1->Location = System::Drawing::Point(235, 154);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(308, 2);
            this->panel1->TabIndex = 4;
            // 
            // Section
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Black;
            this->ClientSize = System::Drawing::Size(716, 635);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox1);
            this->MaximumSize = System::Drawing::Size(1000, 1000);
            this->Name = L"Section";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Section";
            this->Load += gcnew System::EventHandler(this, &Section::Section_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            // Get the section name from the text box
            String^ sectionName = textBox1->Text;

            // Populate DataGridView with timetable for the specified section
            PopulateDataGridView(sectionName);
        }

        void PopulateDataGridView(String^ sectionName)
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

                    // Check if the line contains data for the specified section
                    if (data->Length > 5 && data[5]->Trim()->Equals(sectionName)) {
                        // Adjust the data to match the column headings
                        array<String^>^ adjustedData = gcnew array<String^>(columnHeadings->Length);
                        for (int i = 0; i < columnHeadings->Length; i++) {
                            if (i < data->Length) {
                                adjustedData[i] = data[i]->Trim();
                            }
                            else {
                                adjustedData[i] = "";
                            }
                        }
                        // Add the adjusted data to the DataGridView
                        dataGridView1->Rows->Add(adjustedData);
                    }
                }

                reader->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

    private: System::Void Section_Load(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
