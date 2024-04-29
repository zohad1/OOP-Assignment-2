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
    public ref class ViewTeacher : public System::Windows::Forms::Form
    {
    public:
        ViewTeacher(void)
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
        ~ViewTeacher()
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
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::TextBox^ textBox4;
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
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(356, 450);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(70, 30);
            this->button1->TabIndex = 9;
            this->button1->Text = L"ADD";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &ViewTeacher::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->label1->Location = System::Drawing::Point(271, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(129, 25);
            this->label1->TabIndex = 0;
            this->label1->Text = L"TEACHERS";
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(177, 51);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(302, 322);
            this->dataGridView1->TabIndex = 1;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ViewTeacher::dataGridView1_CellContentClick);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(16, 397);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(121, 20);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Add Teacher:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(12, 479);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(34, 20);
            this->label3->TabIndex = 3;
            this->label3->Text = L"ID:";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(12, 439);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(63, 20);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Name:";
            // 
            // label5
            // 
            this->label5->Location = System::Drawing::Point(0, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(100, 23);
            this->label5->TabIndex = 10;
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(92, 439);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(234, 22);
            this->textBox1->TabIndex = 6;
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(92, 479);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(234, 22);
            this->textBox2->TabIndex = 7;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(12, 540);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(144, 20);
            this->label6->TabIndex = 11;
            this->label6->Text = L"Delete Teacher:";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(16, 580);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(63, 20);
            this->label7->TabIndex = 12;
            this->label7->Text = L"Name:";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(19, 621);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(34, 20);
            this->label8->TabIndex = 13;
            this->label8->Text = L"ID:";
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(92, 580);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(234, 22);
            this->textBox3->TabIndex = 14;
            this->textBox3->TextChanged += gcnew System::EventHandler(this, &ViewTeacher::textBox3_TextChanged);
            // 
            // textBox4
            // 
            this->textBox4->Location = System::Drawing::Point(92, 621);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(234, 22);
            this->textBox4->TabIndex = 15;
            this->textBox4->TextChanged += gcnew System::EventHandler(this, &ViewTeacher::textBox4_TextChanged);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(356, 598);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(70, 30);
            this->button2->TabIndex = 16;
            this->button2->Text = L"Delete";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &ViewTeacher::button2_Click);
            // 
            // ViewTeacher
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LightGreen;
            this->ClientSize = System::Drawing::Size(662, 683);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->textBox4);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->label1);
            this->MaximumSize = System::Drawing::Size(1000, 1000);
            this->Name = L"ViewTeacher";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Load += gcnew System::EventHandler(this, &ViewTeacher::ViewStudents_Load);
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
                String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Teacher.txt";

                // Open the file
                StreamReader^ reader = gcnew StreamReader(filePath);

                // Read the header line (optional)
                String^ headerLine = reader->ReadLine();

                // Create columns in DataGridView
                array<String^>^ columnHeadings = { "Name", "ID" };
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
        //String^ rollNo = textBox3->Text;

        // Validate the data
        if (section->Length == 0 || name->Length == 0) {
            MessageBox::Show("Please enter all the fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Add the data to the DataGridView
        dataGridView1->Rows->Add(gcnew array<String^> { section, name });

        // Add the data to the file
        try {
            String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Teacher.txt";

            // Open the file
            StreamWriter^ writer = gcnew StreamWriter(filePath, true);

            // Write the data to the file
            writer->WriteLine(section + "," + name);

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

    }
    private: System::Void ViewStudents_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        // Get the data from the text boxes
        String^ section = textBox3->Text;
        String^ name = textBox4->Text;

        // Validate the data
        if (section->Length == 0 || name->Length == 0) {
            MessageBox::Show("Please enter all the fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Find the row in the DataGridView that matches the data
        for (int i = 0; i < dataGridView1->Rows->Count; i++) {
            if (dataGridView1->Rows[i]->Cells[0]->Value->ToString() == section &&
                dataGridView1->Rows[i]->Cells[1]->Value->ToString() == name) {
                // Remove the row from the DataGridView
                dataGridView1->Rows->RemoveAt(i);

                // Remove the row from the file
                try {
                    String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Teacher.txt";

                    // Open the file
                    StreamWriter^ writer = gcnew StreamWriter(filePath);

                    // Write the header line (optional)
                    writer->WriteLine("Name-ID");

                    // Write the data to the file
                    for (int i = 0; i < dataGridView1->Rows->Count; i++) {
                        writer->WriteLine(dataGridView1->Rows[i]->Cells[0]->Value + "," + dataGridView1->Rows[i]->Cells[1]->Value);
                    }

                    // Close the file
                    writer->Close();
                }
                catch (Exception^ ex)
                {
                    MessageBox::Show("Error writing to file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }

                // Clear the text boxes
                textBox3->Clear();
                textBox4->Clear();

                return;
            }
        }

        MessageBox::Show("Teacher not found", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }


private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    // Add any logic you want to implement when the text in textBox4 changes
}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    // Add any logic you want to implement when the text in textBox3 changes
}





    
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
