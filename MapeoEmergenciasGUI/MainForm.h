#pragma once

namespace MapeoEmergenciasGUI {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MainForm : public Form
    {
    private:
        Label^ lblTitulo;
        Label^ lblNombre;
        TextBox^ txtNombre;
        Label^ lblTipoDesastre;
        ComboBox^ cmbTipoDesastre;
        Label^ lblLargo;
        NumericUpDown^ nudLargo;
        Label^ lblAncho;
        NumericUpDown^ nudAncho;
        Button^ btnIniciar;

    public:
        MainForm() {
            InicializarComponentes();
        }

    private:
        void InicializarComponentes() {
            this->Text = "Inicialización del Sistema de Mapeo";
            this->Width = 400;
            this->Height = 350;

            lblTitulo = gcnew Label();
            lblTitulo->Text = "Datos Iniciales de Exploración";
            lblTitulo->AutoSize = true;
            lblTitulo->Location = System::Drawing::Point(100, 20);
            this->Controls->Add(lblTitulo);

            lblNombre = gcnew Label();
            lblNombre->Text = "Nombre del operador:";
            lblNombre->Location = System::Drawing::Point(30, 60);
            this->Controls->Add(lblNombre);

            txtNombre = gcnew TextBox();
            txtNombre->Location = System::Drawing::Point(180, 57);
            this->Controls->Add(txtNombre);

            lblTipoDesastre = gcnew Label();
            lblTipoDesastre->Text = "Tipo de desastre:";
            lblTipoDesastre->Location = System::Drawing::Point(30, 100);
            this->Controls->Add(lblTipoDesastre);

            cmbTipoDesastre = gcnew ComboBox();
            cmbTipoDesastre->Location = System::Drawing::Point(180, 97);
            cmbTipoDesastre->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbTipoDesastre->Items->AddRange(gcnew array<Object^> { "Terremoto", "Inundación", "Incendio", "Deslizamiento" });
            cmbTipoDesastre->SelectedIndex = 0;
            this->Controls->Add(cmbTipoDesastre);

            lblLargo = gcnew Label();
            lblLargo->Text = "Largo de la zona (m):";
            lblLargo->Location = System::Drawing::Point(30, 140);
            this->Controls->Add(lblLargo);

            nudLargo = gcnew NumericUpDown();
            nudLargo->Minimum = 1;
            nudLargo->Maximum = 1000;
            nudLargo->Location = System::Drawing::Point(180, 137);
            this->Controls->Add(nudLargo);

            lblAncho = gcnew Label();
            lblAncho->Text = "Ancho de la zona (m):";
            lblAncho->Location = System::Drawing::Point(30, 180);
            this->Controls->Add(lblAncho);

            nudAncho = gcnew NumericUpDown();
            nudAncho->Minimum = 1;
            nudAncho->Maximum = 1000;
            nudAncho->Location = System::Drawing::Point(180, 177);
            this->Controls->Add(nudAncho);

            btnIniciar = gcnew Button();
            btnIniciar->Text = "Iniciar Exploración";
            btnIniciar->Location = System::Drawing::Point(120, 230);
            btnIniciar->Click += gcnew EventHandler(this, &MainForm::btnIniciar_Click);
            this->Controls->Add(btnIniciar);
        }

        void btnIniciar_Click(Object^ sender, EventArgs^ e) {
            String^ nombre = txtNombre->Text;
            String^ tipo = cmbTipoDesastre->SelectedItem->ToString();
            int largo = Decimal::ToInt32(nudLargo->Value);
            int ancho = Decimal::ToInt32(nudAncho->Value);

            MessageBox::Show("Inicio de exploración:\nOperador: " + nombre +
                "\nDesastre: " + tipo +
                "\nZona: " + largo + "m x " + ancho + "m",
                "Confirmación", MessageBoxButtons::OK, MessageBoxIcon::Information);

            // Aquí podrías continuar abriendo otra ventana o iniciar procesos del robot
        }
    };
}