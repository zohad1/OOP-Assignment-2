#include "MainForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Assignment02::MainForm form;
    Application::Run(% form);

    return 0;
}

