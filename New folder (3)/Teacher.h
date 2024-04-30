#include <vcclr.h>
#include <string>

namespace Assignment02 {

    using namespace System;
    using namespace System::IO;
    using namespace System::Windows::Forms;

    public ref class Teacher : public System::Windows::Forms::Form
    {
    public:
        Teacher(void)
        {
            InitializeComponent();
        }

    protected:
        ~Teacher()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ searchButton;
        System::Windows::Forms::TextBox^ dayTextBox; // Renamed from teacherNameTextBox to dayTextBox
        System::Windows::Forms::DataGridView^ timetableDataGridView;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Panel^ panel1;
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->searchButton = (gcnew System::Windows::Forms::Button());
            this->dayTextBox = (gcnew System::Windows::Forms::TextBox());
            this->timetableDataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timetableDataGridView))->BeginInit();
            this->SuspendLayout();
            // 
            // searchButton
            // 
            this->searchButton->BackColor = System::Drawing::Color::Black;
            this->searchButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->searchButton->ForeColor = System::Drawing::Color::White;
            this->searchButton->Location = System::Drawing::Point(362, 160);
            this->searchButton->Name = L"searchButton";
            this->searchButton->Size = System::Drawing::Size(75, 28);
            this->searchButton->TabIndex = 0;
            this->searchButton->Text = L"Search";
            this->searchButton->UseVisualStyleBackColor = false;
            this->searchButton->Click += gcnew System::EventHandler(this, &Teacher::searchButton_Click);
            // 
            // dayTextBox
            // 
            this->dayTextBox->BackColor = System::Drawing::Color::Black;
            this->dayTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->dayTextBox->Location = System::Drawing::Point(188, 126);
            this->dayTextBox->Name = L"dayTextBox";
            this->dayTextBox->Size = System::Drawing::Size(483, 15);
            this->dayTextBox->TabIndex = 1;
            // 
            // timetableDataGridView
            // 
            this->timetableDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->timetableDataGridView->Location = System::Drawing::Point(68, 245);
            this->timetableDataGridView->Name = L"timetableDataGridView";
            this->timetableDataGridView->RowHeadersWidth = 51;
            this->timetableDataGridView->RowTemplate->Height = 24;
            this->timetableDataGridView->Size = System::Drawing::Size(603, 345);
            this->timetableDataGridView->TabIndex = 2;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Black;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(45, 121);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(137, 20);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Teacher Name:";
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::White;
            this->panel1->Location = System::Drawing::Point(188, 147);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(478, 2);
            this->panel1->TabIndex = 4;
            // 
            // Teacher
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Black;
            this->ClientSize = System::Drawing::Size(731, 643);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->timetableDataGridView);
            this->Controls->Add(this->dayTextBox);
            this->Controls->Add(this->searchButton);
            this->MaximumSize = System::Drawing::Size(1000, 1000);
            this->Name = L"Teacher";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Teacher Form";
            this->Load += gcnew System::EventHandler(this, &Teacher::Teacher_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timetableDataGridView))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ day = dayTextBox->Text->Trim(); // Trim the input
            PopulateDataGridView(day);
        }

        void PopulateDataGridView(String^ teacher)
        {
            try {
                String^ filePath = "D:/timetable.txt";
                StreamReader^ reader = gcnew StreamReader(filePath);
                array<String^>^ columnHeadings = { "Day", "Course", "Teacher", "Time", "Room", "Section" };

                // Clear existing columns and rows
                timetableDataGridView->Columns->Clear();
                timetableDataGridView->Rows->Clear();

                // Add columns to DataGridView
                for (int i = 0; i < columnHeadings->Length; i++) {
                    timetableDataGridView->Columns->Add(gcnew DataGridViewTextBoxColumn());
                    timetableDataGridView->Columns[i]->HeaderText = columnHeadings[i];
                }

                // Read lines and add data to DataGridView
                String^ line;
                while ((line = reader->ReadLine()) != nullptr) {
                    array<String^>^ data = line->Split(',');

                    // Check if the line contains data for the specified teacher
                    if (data->Length > 2 && data[2]->Trim()->Equals(teacher)) {
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
                        timetableDataGridView->Rows->Add(adjustedData);
                    }
                }

                reader->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    private: System::Void Teacher_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}