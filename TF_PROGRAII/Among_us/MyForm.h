#pragma once
#include "Controlador.h"
#include "Data.h"

namespace Ejercicio011 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Controlador* control;
		Datos* data;
		Bitmap^ bmp;
		Graphics^ g;
		BufferedGraphicsContext^ context;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Timer^ timer3;
	private: System::Windows::Forms::Label^ label1;
		   BufferedGraphics^ buffer;
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			bmp = gcnew Bitmap("amongus.png");
			bmp->MakeTransparent(bmp->GetPixel(0, 0));

			g = this->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(g, this->ClientRectangle);

			control = new Controlador();
			data = new Datos();

			timer2->Interval = data->getS() * 1000;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Enabled = true;
			this->timer3->Interval = 1000;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(855, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tiempo: ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1002, 585);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::White);
		control->jugar(buffer, bmp, data->getS(), this->ClientRectangle.Width, this->ClientRectangle.Height);
		if (data->getT() == 0) {
			String^ aux = "Se termino el juego\n";
			aux += ("Cyan: " + control->getCyan() + "\n");
			aux += ("Rojo: " + control->getRojo() + "\n");
			aux += ("Magenta: " + control->getMagenta() + "\n");
			aux += ("Marron: " + control->getBrown() + "\n");
			aux += ("Negro: " + control->getBlack() + "\n");
			aux += ("Rosado: " + control->getPink() + "\n");
			timer1->Enabled = false;
			timer2->Enabled = false;
			timer3->Enabled = false;
			MessageBox::Show(aux);
			this->Close();
		}
		else {
			label1->Text = Convert::ToString("Tiempo: " + data->getT());
			buffer->Render(g);
		}
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		control->agregar();
	}
	private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
		data->setT(data->getT() - 1);
	}
	private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		delete buffer, context, g;
	}
	};
}
