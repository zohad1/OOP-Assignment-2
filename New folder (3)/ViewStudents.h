#include <iostream>
#include <fstream>
#include<List>

namespace Assignment02 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    /// <summary>
    /// Summary for ViewStudents
    /// </summary>
    public ref class ViewStudents : public System::Windows::Forms::Form
    {
    public:
        ViewStudents(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //

            // Load student data when the form is initialized
            PopulateDataGridView();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ViewStudents()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    protected:
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::TextBox^ textBox4;
    private: System::Windows::Forms::TextBox^ textBox5;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::TextBox^ textBox6;
    private: System::Windows::Forms::Button^ button2;

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
            System::Windows::Forms::Button^ button1;
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->textBox5 = (gcnew System::Windows::Forms::TextBox());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->textBox6 = (gcnew System::Windows::Forms::TextBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            button1->Location = System::Drawing::Point(185, 530);
            button1->Name = L"button1";
            button1->Size = System::Drawing::Size(100, 30);
            button1->TabIndex = 9;
            button1->Text = L"ADD";
            button1->UseVisualStyleBackColor = true;
            button1->Click += gcnew System::EventHandler(this, &ViewStudents::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->label1->Location = System::Drawing::Point(343, 20);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(129, 25);
            this->label1->TabIndex = 0;
            this->label1->Text = L"STUDENTS";
            // 
            // dataGridView1
            // 
            this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::WindowFrame;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(172, 61);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(448, 324);
            this->dataGridView1->TabIndex = 1;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ViewStudents::dataGridView1_CellContentClick);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(12, 420);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(117, 20);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Add Student:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(12, 493);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(72, 20);
            this->label3->TabIndex = 3;
            this->label3->Text = L"Section";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(12, 455);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(63, 20);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Name:";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(181, 493);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(77, 20);
            this->label5->TabIndex = 5;
            this->label5->Text = L"Roll No:";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(100, 491);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(69, 22);
            this->textBox1->TabIndex = 6;
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(100, 455);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(344, 22);
            this->textBox2->TabIndex = 7;
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(264, 493);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(180, 22);
            this->textBox3->TabIndex = 8;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(16, 580);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(140, 20);
            this->label6->TabIndex = 10;
            this->label6->Text = L"Delete Student:";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(12, 618);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(63, 20);
            this->label7->TabIndex = 11;
            this->label7->Text = L"Name:";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(6, 657);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(78, 20);
            this->label8->TabIndex = 12;
            this->label8->Text = L"Section:";
            // 
            // textBox4
            // 
            this->textBox4->Location = System::Drawing::Point(100, 618);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(344, 22);
            this->textBox4->TabIndex = 13;
            this->textBox4->TextChanged += gcnew System::EventHandler(this, &ViewStudents::textBox4_TextChanged);
            // 
            // textBox5
            // 
            this->textBox5->Location = System::Drawing::Point(100, 657);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(69, 22);
            this->textBox5->TabIndex = 14;
            this->textBox5->TextChanged += gcnew System::EventHandler(this, &ViewStudents::textBox5_TextChanged);
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label9->Location = System::Drawing::Point(185, 662);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(77, 20);
            this->label9->TabIndex = 15;
            this->label9->Text = L"Roll No:";
            // 
            // textBox6
            // 
            this->textBox6->Location = System::Drawing::Point(268, 660);
            this->textBox6->Name = L"textBox6";
            this->textBox6->Size = System::Drawing::Size(176, 22);
            this->textBox6->TabIndex = 16;
            this->textBox6->TextChanged += gcnew System::EventHandler(this, &ViewStudents::textBox6_TextChanged);
            // 
            // button2
            // 
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(185, 699);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(100, 30);
            this->button2->TabIndex = 17;
            this->button2->Text = L"Del.";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &ViewStudents::button2_Click);
            // 
            // ViewStudents
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LightGreen;
            this->ClientSize = System::Drawing::Size(758, 735);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->textBox6);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->textBox5);
            this->Controls->Add(this->textBox4);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(button1);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->label1);
            this->MaximumSize = System::Drawing::Size(1000, 1000);
            this->Name = L"ViewStudents";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Load += gcnew System::EventHandler(this, &ViewStudents::ViewStudents_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        // Load student data from file and bind it to the DataGridView
    private:
        void PopulateDataGridView()
        {
            try {
                String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Student.txt";

                // Open the file
                StreamReader^ reader = gcnew StreamReader(filePath);

                // Read the header line (optional)
                String^ headerLine = reader->ReadLine();

                // Create columns in DataGridView
                array<String^>^ columnHeadings = { "Setion", "Name", "Roll No." };
                for (int i = 0; i < columnHeadings->Length; i++) {
                    dataGridView1->Columns->Add(gcnew DataGridViewTextBoxColumn());
                    dataGridView1->Columns[i]->HeaderText = columnHeadings[i];
                }

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

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Get the data from the text boxes
        String^ section = textBox1->Text;
        String^ name = textBox2->Text;
        String^ rollNo = textBox3->Text;

        // Validate the data
        if (section->Length == 0 || name->Length == 0 || rollNo->Length == 0) {
            MessageBox::Show("Please enter all the fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Add the data to the DataGridView
        dataGridView1->Rows->Add(gcnew array<String^> { section, name, rollNo });

        // Add the data to the file
        try {
            String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Student.txt";

            // Open the file
            StreamWriter^ writer = gcnew StreamWriter(filePath, true);

            // Write the data to the file
            writer->WriteLine(section + "," + name + "," + rollNo);

            // Close the file
            writer->Close();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error writing to file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        // Clear the text boxes
        textBox1->Clear();
        textBox2->Clear();
        textBox3->Clear();
    }
    private: System::Void ViewStudents_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }


     private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
         try {
             // Ensure dataGridView1 is not null
             if (dataGridView1 == nullptr) {
                 MessageBox::Show("DataGridView is not initialized", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                 return;
             }

             // Get the data from the text boxes
             String^ name = textBox4->Text;
             String^ section = textBox5->Text;
             String^ rollNo = textBox6->Text;

             // Validate the data
             if (name->Length == 0 || section->Length == 0 || rollNo->Length == 0) {
                 MessageBox::Show("Please enter all the fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                 return;
             }

             // Find the row with the matching data
             bool found = false;
             for (int i = 0; i < dataGridView1->Rows->Count; i++) {
                 if (dataGridView1->Rows[i]->Cells[1]->Value != nullptr && dataGridView1->Rows[i]->Cells[2]->Value != nullptr &&
                     dataGridView1->Rows[i]->Cells[1]->Value->ToString() == name &&
                     dataGridView1->Rows[i]->Cells[0]->Value->ToString() == section &&
                     dataGridView1->Rows[i]->Cells[2]->Value->ToString() == rollNo) {
                     // Remove the row from the DataGridView
                     dataGridView1->Rows->RemoveAt(i);
                     found = true;
                     break;
                 }
             }

             // If the data was found, update the file
             if (found) {
                 String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Student.txt";
                 StreamWriter^ writer = gcnew StreamWriter(filePath);

                 // Write the header line
                 array<String^>^ columnHeadings = { "Section", "Name", "Roll No." };
                 writer->WriteLine(String::Join(",", columnHeadings));

                 // Write each row in the DataGridView to the file
                 for (int i = 0; i < dataGridView1->Rows->Count; i++) {
                     if (dataGridView1->Rows[i]->Cells[1]->Value != nullptr && dataGridView1->Rows[i]->Cells[2]->Value != nullptr) {
                         array<String^>^ data = gcnew array<String^>(3);
                         for (int j = 0; j < 3; j++) {
                             data[j] = dataGridView1->Rows[i]->Cells[j]->Value->ToString();
                         }
                         writer->WriteLine(String::Join(",", data));
                     }
                 }

                 // Close the file
                 writer->Close();
             }
             else {
                 MessageBox::Show("Student not found", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
             }

             // Clear the text boxes
             textBox4->Clear();
             textBox5->Clear();
             textBox6->Clear();
         }
         catch (Exception^ ex) {
             MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
         }
     }





    private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    };
}
