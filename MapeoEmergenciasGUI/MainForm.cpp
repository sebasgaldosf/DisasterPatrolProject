#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MapeoEmergenciasGUI; // <<--- ESTA LÍNEA ES CLAVE

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Crear e iniciar el formulario principal
    Application::Run(gcnew MainForm());
    return 0;
}