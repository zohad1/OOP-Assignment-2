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
    public ref class ViewRooms : public System::Windows::Forms::Form
    {
    public:
        ViewRooms(void)
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
        ~ViewRooms()
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(228, 533);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(100, 30);
            this->button1->TabIndex = 9;
            this->button1->Text = L"ADD";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &ViewRooms::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->label1->Location = System::Drawing::Point(223, 27);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(100, 25);
            this->label1->TabIndex = 0;
            this->label1->Text = L"ROOMS:";
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(130, 78);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(269, 312);
            this->dataGridView1->TabIndex = 1;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(224, 417);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(119, 25);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Add Room:";
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
            this->label4->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(-1, 491);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(142, 22);
            this->label4->TabIndex = 4;
            this->label4->Text = L"Room Number:";
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
            this->textBox2->Location = System::Drawing::Point(172, 491);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(269, 22);
            this->textBox2->TabIndex = 7;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(224, 602);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(142, 25);
            this->label6->TabIndex = 12;
            this->label6->Text = L"Delete Room:";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::SystemColors::ButtonFace;
            this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(-1, 650);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(142, 22);
            this->label7->TabIndex = 13;
            this->label7->Text = L"Room Number:";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(172, 650);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(269, 22);
            this->textBox1->TabIndex = 14;
            // 
            // button2
            // 
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(229, 696);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(100, 30);
            this->button2->TabIndex = 15;
            this->button2->Text = L"Del.";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &ViewRooms::button2_Click);
            // 
            // ViewRooms
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LightGreen;
            this->ClientSize = System::Drawing::Size(779, 753);
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
            this->Name = L"ViewRooms";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Load += gcnew System::EventHandler(this, &ViewRooms::ViewRooms_Load);
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
                String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Room.txt";

                // Open the file
                StreamReader^ reader = gcnew StreamReader(filePath);

                // Read the header line (optional)
                String^ headerLine = reader->ReadLine();

                // Create columns in DataGridView
                array<String^>^ columnHeadings = { "Room" };
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
        String^ name = textBox2->Text;

         // Validate the data
        if (name->Length == 0) {
            MessageBox::Show("Please enter all the fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Add the data to the DataGridView
        dataGridView1->Rows->Add(gcnew array<String^>  { name });

        // Add the data to the file
        try {
            String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Room.txt";

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

        
        textBox2->Clear();
      
    }
    
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    // Get the room number to be deleted
    String^ roomToDelete = textBox1->Text;

    // Find the row index corresponding to the room number
    int rowIndex = -1;
    for (int i = 0; i < dataGridView1->RowCount; i++) {
        if (dataGridView1->Rows[i]->Cells[0]->Value->ToString() == roomToDelete) {
            rowIndex = i;
            break;
        }
    }

    // If the room number is found, remove the row from DataGridView and the file
    if (rowIndex != -1) {
        dataGridView1->Rows->RemoveAt(rowIndex);

        try {
            String^ filePath = "C:/Users/zuhad/OneDrive/Desktop/New folder (3)/Room.txt";

            // Read the lines from the file
            array<String^>^ lines = File::ReadAllLines(filePath);

            // Write the lines back to the file, excluding the line to be deleted
            StreamWriter^ writer = gcnew StreamWriter(filePath);
            for (int i = 0; i < lines->Length; i++) {
                if (lines[i] != roomToDelete) {
                    writer->WriteLine(lines[i]);
                }
            }

            // Close the file
            writer->Close();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error writing to file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    else {
        MessageBox::Show("Room number not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

private: System::Void ViewRooms_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
