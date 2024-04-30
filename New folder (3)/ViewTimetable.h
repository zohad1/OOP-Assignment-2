#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace Assignment02 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO; // Include the System::IO namespace for file operations

    /// <summary>
    /// Summary for ViewTimetable
    /// </summary>
    public ref class ViewTimetable : public System::Windows::Forms::Form
    {
    public:
        ViewTimetable(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
            PopulateDataGridView();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ViewTimetable()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TextBox^ textBoxTeacher;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    protected:
    private: System::Windows::Forms::Label^ label1;

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
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AllowUserToDeleteRows = false;
            this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(36, 126);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(726, 502);
            this->dataGridView1->TabIndex = 0;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ViewTimetable::dataGridView1_CellContentClick);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Black;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(326, 52);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(133, 25);
            this->label1->TabIndex = 1;
            this->label1->Text = L"TIMETABLE";
            // 
            // ViewTimetable
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Black;
            this->ClientSize = System::Drawing::Size(789, 691);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dataGridView1);
            this->MaximumSize = System::Drawing::Size(1000, 1000);
            this->Name = L"ViewTimetable";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"ViewTimetable";
            this->Load += gcnew System::EventHandler(this, &ViewTimetable::ViewTimetable_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private:
        void PopulateDataGridView()
        {
            try {
                String^ filePath = "D:/timetable.txt";

                // Open the file
                StreamReader^ reader = gcnew StreamReader(filePath);

                // Read the header line (optional)
                String^ headerLine = reader->ReadLine();

                // Create columns in DataGridView
                array<String^>^ columnHeadings = { "Day", "Subject", "Teacher", "Room", "Time", "Section" };
                for (int i = 0; i < columnHeadings->Length; i++) {
                    dataGridView1->Columns->Add(gcnew DataGridViewTextBoxColumn());
                    dataGridView1->Columns[i]->HeaderText = columnHeadings[i];
                }

                // Set AutoSizeColumnsMode and AutoResizeRowsMode
                dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
                dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;

                // Read each line from the file and add it to the DataGridView
                String^ line;
                while ((line = reader->ReadLine()) != nullptr) {
                    array<String^>^ data = line->Split(','); // Assuming the data is separated by commas
                    dataGridView1->Rows->Add(data);
                }

                // Close the file
                reader->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

    private: System::Void ViewTimetable_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
};
}
