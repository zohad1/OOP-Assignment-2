#include <iostream>
#include <fstream>

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
    public ref class ViewCourses : public System::Windows::Forms::Form
    {
    public:
        ViewCourses(void)
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
        ~ViewCourses()
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

    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ panel2;


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
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Black;
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(572, 178);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(100, 30);
            this->button1->TabIndex = 9;
            this->button1->Text = L"ADD";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &ViewCourses::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Black;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(324, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(118, 25);
            this->label1->TabIndex = 0;
            this->label1->Text = L"COURSES";
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(24, 126);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(318, 312);
            this->dataGridView1->TabIndex = 1;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ViewCourses::dataGridView1_CellContentClick);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Black;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::Color::White;
            this->label2->Location = System::Drawing::Point(567, 85);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(134, 25);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Add Course:";
            // 
            // label3
            // 
            this->label3->Location = System::Drawing::Point(0, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(100, 23);
            this->label3->TabIndex = 11;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::Black;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::Color::White;
            this->label4->Location = System::Drawing::Point(371, 140);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(137, 22);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Course Name:";
            // 
            // label5
            // 
            this->label5->Location = System::Drawing::Point(0, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(100, 23);
            this->label5->TabIndex = 10;
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(514, 140);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(269, 22);
            this->textBox2->TabIndex = 7;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::Color::Black;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label6->ForeColor = System::Drawing::Color::White;
            this->label6->Location = System::Drawing::Point(544, 359);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(157, 25);
            this->label6->TabIndex = 12;
            this->label6->Text = L"Delete Course:";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::Color::Black;
            this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label7->ForeColor = System::Drawing::Color::White;
            this->label7->Location = System::Drawing::Point(371, 416);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(137, 22);
            this->label7->TabIndex = 13;
            this->label7->Text = L"Course Name:";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(514, 416);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(269, 22);
            this->textBox1->TabIndex = 14;
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::Black;
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button2->ForeColor = System::Drawing::Color::White;
            this->button2->Location = System::Drawing::Point(572, 469);
            this->button2->Name = L"button2";
            this->button2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->button2->Size = System::Drawing::Size(100, 30);
            this->button2->TabIndex = 15;
            this->button2->Text = L"Delete";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &ViewCourses::button2_Click);
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::White;
            this->panel1->Location = System::Drawing::Point(12, 49);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(771, 2);
            this->panel1->TabIndex = 16;
            this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ViewCourses::panel1_Paint);
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::White;
            this->panel2->Location = System::Drawing::Point(363, 67);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(2, 481);
            this->panel2->TabIndex = 17;
            // 
            // ViewCourses
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Black;
            this->ClientSize = System::Drawing::Size(795, 632);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->label1);
            this->MaximumSize = System::Drawing::Size(1000, 1000);
            this->Name = L"ViewCourses";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Load += gcnew System::EventHandler(this, &ViewCourses::ViewCourses_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        // Load student data from file and bind it to the DataGridView
    private:
        // Load student data from file and bind it to the DataGridView
       private:
           void PopulateDataGridView()
           {
               try {
                   String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Course.txt";

                   // Open the file
                   StreamReader^ reader = gcnew StreamReader(filePath);

                   // Read the header line (optional)
                   String^ headerLine = reader->ReadLine();

                   // Create columns in DataGridView
                   array<String^>^ columnHeadings = { "Course" };
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

                   // Set DataGridViewAutoSizeColumnsMode to resize all columns
                   dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
               }
               catch (Exception^ ex)
               {
                   MessageBox::Show("Error reading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }


    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Get the data from the text boxes
      //  String^ section = textBox1->Text;
        String^ name = textBox2->Text;
        // String^ rollNo = textBox3->Text;

         // Validate the data
        if (name->Length == 0) {
            MessageBox::Show("Please enter all the fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Add the data to the DataGridView
        dataGridView1->Rows->Add(gcnew array<String^>  { name });

        // Add the data to the file
        try {
            String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Course.txt";

            // Open the file
            StreamWriter^ writer = gcnew StreamWriter(filePath, true);

            // Write the data to the file
            writer->WriteLine(name);

            // Close the file
            writer->Close();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error writing to file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        // Clear the text boxes
       // textBox1->Clear();
        textBox2->Clear();
        // textBox3->Clear();
    }
   private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
       // Get the data from the text box
       String^ name = textBox1->Text->Trim();

       // Validate the data
       if (name->Length == 0) {
           MessageBox::Show("Please enter the course name", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
           return;
       }

       // Find the row with the matching name and delete it from the DataGridView
       for (int i = 0; i < dataGridView1->Rows->Count; i++) {
           if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr &&
               dataGridView1->Rows[i]->Cells[0]->Value->ToString()->Trim() == name) {
               dataGridView1->Rows->RemoveAt(i);
               break; // Exit loop after removing the row
           }
       }

       // Save the remaining data back to the file
       try {
           String^ filePath = "D:/Course.txt";

           // Open the file for writing
           StreamWriter^ writer = gcnew StreamWriter(filePath);

           // Write the header line (optional)
           writer->WriteLine("Course");

           // Write the remaining data to the file
           for (int i = 0; i < dataGridView1->Rows->Count; i++) {
               if (dataGridView1->Rows[i]->Cells[0]->Value != nullptr) {
                   writer->WriteLine(dataGridView1->Rows[i]->Cells[0]->Value->ToString()->Trim());
               }
           }

           // Close the file
           writer->Close();

           MessageBox::Show("Course deleted successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
       }
       catch (Exception^ ex)
       {
           MessageBox::Show("Error writing to file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
       }

       // Clear the text box
       textBox1->Clear();
   }

    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
    private: System::Void ViewCourses_Load(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
