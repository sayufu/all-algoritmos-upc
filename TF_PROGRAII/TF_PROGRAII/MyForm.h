#pragma once
#include <msclr\marshal_cppstd.h>
#include"Controller.h"

namespace Forms {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::ComponentModel::IContainer^ components;
		//
		//Juego
		//
		Panel^ Panel;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpMapa;
		Controller*controller;
		//
		//BOTONES
		System::Windows::Forms::Button^ button_jugar;
		System::Windows::Forms::Button^ button_instrucciones;
		System::Windows::Forms::Button^ button_creditos;
		System::Windows::Forms::Button^ button_salir;
		System::Windows::Forms::Button^ button_atras;
		System::Windows::Forms::Button^ Boton_Pausa;
		System::Windows::Forms::Button^ button_Ranking_1;
		System::Windows::Forms::Button^ button_Nivel_1;
		System::Windows::Forms::Button^ button_Nivel_2;
		System::Windows::Forms::Button^ button_Ranking_2;
		System::Windows::Forms::Button^ boton_Terminar_Partida;
		System::Windows::Forms::Button^ button_Continuar_Partida;
		System::Windows::Forms::TextBox^ textBox_nombre;
		System::Windows::Forms::Label^ label_texto;
		System::Windows::Forms::Label^ Cofre;
		//
		//Bitmaps
		Bitmap^ bmpMain;
		Bitmap^ bmpInstrucciones;
		Bitmap^ bmpCredits;
		Bitmap^ bmpMenu;
		Bitmap^ icon;
		//
		// SounPlayers
		SoundPlayer^ Musica_Fondo;
		// 
		//Timers
		System::Windows::Forms::Timer^ Timer_Juego;
	private: System::Windows::Forms::Button^ Button_cerrar_rank;
	private: System::Windows::Forms::Label^ Box_Ranking;

		   System::Windows::Forms::Timer^ Timer_Menu;
		//
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//Juego
			//
			g = Panel->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, Panel->ClientRectangle);
			//
			//Bitmaps
			//
			bmpMain = gcnew Bitmap("Resources//Fondos//Main_Fondo.png");
			bmpInstrucciones = gcnew Bitmap("Resources//Fondos//Instrucciones.png");
			bmpCredits = gcnew Bitmap("Resources//Fondos//Credits.png");
			bmpMenu = gcnew Bitmap("Resources//Fondos//Menu_Seleccion.png");
			controller = new Controller();
			//
			//SoundPlayers
			//
			Musica_Fondo = gcnew SoundPlayer("Resources//Loop_SFX.wav");
		}
#pragma region Windows Form Designer generated code
		//Forms
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button_jugar = (gcnew System::Windows::Forms::Button());
			this->button_instrucciones = (gcnew System::Windows::Forms::Button());
			this->button_creditos = (gcnew System::Windows::Forms::Button());
			this->button_salir = (gcnew System::Windows::Forms::Button());
			this->button_atras = (gcnew System::Windows::Forms::Button());
			this->Panel = (gcnew System::Windows::Forms::Panel());
			this->Button_cerrar_rank = (gcnew System::Windows::Forms::Button());
			this->Cofre = (gcnew System::Windows::Forms::Label());
			this->textBox_nombre = (gcnew System::Windows::Forms::TextBox());
			this->boton_Terminar_Partida = (gcnew System::Windows::Forms::Button());
			this->button_Continuar_Partida = (gcnew System::Windows::Forms::Button());
			this->button_Nivel_2 = (gcnew System::Windows::Forms::Button());
			this->button_Ranking_2 = (gcnew System::Windows::Forms::Button());
			this->button_Ranking_1 = (gcnew System::Windows::Forms::Button());
			this->button_Nivel_1 = (gcnew System::Windows::Forms::Button());
			this->Boton_Pausa = (gcnew System::Windows::Forms::Button());
			this->label_texto = (gcnew System::Windows::Forms::Label());
			this->Timer_Menu = (gcnew System::Windows::Forms::Timer(this->components));
			this->Timer_Juego = (gcnew System::Windows::Forms::Timer(this->components));
			this->Box_Ranking = (gcnew System::Windows::Forms::Label());
			this->Panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_jugar
			// 
			this->button_jugar->BackColor = System::Drawing::Color::Maroon;
			this->button_jugar->Font = (gcnew System::Drawing::Font(L"MV Boli", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_jugar->ForeColor = System::Drawing::Color::Lime;
			this->button_jugar->Location = System::Drawing::Point(98, 478);
			this->button_jugar->Name = L"button_jugar";
			this->button_jugar->Size = System::Drawing::Size(239, 81);
			this->button_jugar->TabIndex = 0;
			this->button_jugar->Text = L"JUGAR";
			this->button_jugar->UseVisualStyleBackColor = false;
			this->button_jugar->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button_click_Jugar);
			// 
			// button_instrucciones
			// 
			this->button_instrucciones->BackColor = System::Drawing::Color::Maroon;
			this->button_instrucciones->Font = (gcnew System::Drawing::Font(L"MV Boli", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_instrucciones->ForeColor = System::Drawing::Color::Lime;
			this->button_instrucciones->Location = System::Drawing::Point(370, 478);
			this->button_instrucciones->Name = L"button_instrucciones";
			this->button_instrucciones->Size = System::Drawing::Size(251, 81);
			this->button_instrucciones->TabIndex = 1;
			this->button_instrucciones->Text = L"INSTRUCCIONES";
			this->button_instrucciones->UseVisualStyleBackColor = false;
			this->button_instrucciones->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button_click_Instrucciones);
			// 
			// button_creditos
			// 
			this->button_creditos->BackColor = System::Drawing::Color::Maroon;
			this->button_creditos->Font = (gcnew System::Drawing::Font(L"MV Boli", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_creditos->ForeColor = System::Drawing::Color::Lime;
			this->button_creditos->Location = System::Drawing::Point(657, 478);
			this->button_creditos->Name = L"button_creditos";
			this->button_creditos->Size = System::Drawing::Size(241, 81);
			this->button_creditos->TabIndex = 2;
			this->button_creditos->Text = L"CREDITOS";
			this->button_creditos->UseVisualStyleBackColor = false;
			this->button_creditos->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::boton_click_creditos);
			// 
			// button_salir
			// 
			this->button_salir->BackColor = System::Drawing::Color::Maroon;
			this->button_salir->Font = (gcnew System::Drawing::Font(L"MV Boli", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_salir->ForeColor = System::Drawing::Color::Lime;
			this->button_salir->Location = System::Drawing::Point(936, 478);
			this->button_salir->Name = L"button_salir";
			this->button_salir->Size = System::Drawing::Size(239, 81);
			this->button_salir->TabIndex = 3;
			this->button_salir->Text = L"SALIR";
			this->button_salir->UseVisualStyleBackColor = false;
			this->button_salir->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button_click_Salir);
			// 
			// button_atras
			// 
			this->button_atras->BackColor = System::Drawing::Color::Maroon;
			this->button_atras->Font = (gcnew System::Drawing::Font(L"MV Boli", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_atras->ForeColor = System::Drawing::Color::Lime;
			this->button_atras->Location = System::Drawing::Point(14, 18);
			this->button_atras->Name = L"button_atras";
			this->button_atras->Size = System::Drawing::Size(130, 28);
			this->button_atras->TabIndex = 4;
			this->button_atras->Text = L"Volver al Menu";
			this->button_atras->UseVisualStyleBackColor = true;
			this->button_atras->Visible = false;
			this->button_atras->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button_click_atras);
			// 
			// Panel
			// 
			this->Panel->Controls->Add(this->boton_Terminar_Partida);
			this->Panel->Controls->Add(this->Box_Ranking);
			this->Panel->Controls->Add(this->Button_cerrar_rank);
			this->Panel->Controls->Add(this->Cofre);
			this->Panel->Controls->Add(this->textBox_nombre);
			this->Panel->Controls->Add(this->button_Continuar_Partida);
			this->Panel->Controls->Add(this->button_Nivel_2);
			this->Panel->Controls->Add(this->button_Ranking_2);
			this->Panel->Controls->Add(this->button_Ranking_1);
			this->Panel->Controls->Add(this->button_Nivel_1);
			this->Panel->Controls->Add(this->button_atras);
			this->Panel->Controls->Add(this->button_jugar);
			this->Panel->Controls->Add(this->button_salir);
			this->Panel->Controls->Add(this->Boton_Pausa);
			this->Panel->Controls->Add(this->button_instrucciones);
			this->Panel->Controls->Add(this->button_creditos);
			this->Panel->Controls->Add(this->label_texto);
			this->Panel->Location = System::Drawing::Point(-2, -4);
			this->Panel->Name = L"Panel";
			this->Panel->Size = System::Drawing::Size(1284, 724);
			this->Panel->TabIndex = 6;
			// 
			// Button_cerrar_rank
			// 
			this->Button_cerrar_rank->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Button_cerrar_rank->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Button_cerrar_rank->Location = System::Drawing::Point(747, 98);
			this->Button_cerrar_rank->Name = L"Button_cerrar_rank";
			this->Button_cerrar_rank->Size = System::Drawing::Size(75, 23);
			this->Button_cerrar_rank->TabIndex = 14;
			this->Button_cerrar_rank->Text = L"X";
			this->Button_cerrar_rank->UseVisualStyleBackColor = false;
			this->Button_cerrar_rank->Visible = false;
			this->Button_cerrar_rank->Click += gcnew System::EventHandler(this, &MyForm::Button_cerrar_rank_Click);
			// 
			// Cofre
			// 
			this->Cofre->BackColor = System::Drawing::Color::Teal;
			this->Cofre->Font = (gcnew System::Drawing::Font(L"MV Boli", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cofre->Location = System::Drawing::Point(452, 124);
			this->Cofre->Name = L"Cofre";
			this->Cofre->Padding = System::Windows::Forms::Padding(20, 10, 10, 10);
			this->Cofre->Size = System::Drawing::Size(370, 420);
			this->Cofre->TabIndex = 7;
			this->Cofre->Text = L"  ";
			this->Cofre->Visible = false;
			// 
			// textBox_nombre
			// 
			this->textBox_nombre->AcceptsReturn = true;
			this->textBox_nombre->AcceptsTab = true;
			this->textBox_nombre->BackColor = System::Drawing::Color::White;
			this->textBox_nombre->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox_nombre->ForeColor = System::Drawing::SystemColors::WindowText;
			this->textBox_nombre->Location = System::Drawing::Point(570, 249);
			this->textBox_nombre->Name = L"textBox_nombre";
			this->textBox_nombre->Size = System::Drawing::Size(276, 33);
			this->textBox_nombre->TabIndex = 12;
			this->textBox_nombre->UseWaitCursor = true;
			this->textBox_nombre->Visible = false;
			// 
			// boton_Terminar_Partida
			// 
			this->boton_Terminar_Partida->BackColor = System::Drawing::Color::Cyan;
			this->boton_Terminar_Partida->Font = (gcnew System::Drawing::Font(L"MV Boli", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->boton_Terminar_Partida->ForeColor = System::Drawing::Color::Red;
			this->boton_Terminar_Partida->Location = System::Drawing::Point(516, 436);
			this->boton_Terminar_Partida->Name = L"boton_Terminar_Partida";
			this->boton_Terminar_Partida->Size = System::Drawing::Size(244, 81);
			this->boton_Terminar_Partida->TabIndex = 11;
			this->boton_Terminar_Partida->Text = L"Salir al Menu";
			this->boton_Terminar_Partida->UseVisualStyleBackColor = false;
			this->boton_Terminar_Partida->Visible = false;
			this->boton_Terminar_Partida->Click += gcnew System::EventHandler(this, &MyForm::boton_Terminar_Partida_Click);
			// 
			// button_Continuar_Partida
			// 
			this->button_Continuar_Partida->BackColor = System::Drawing::Color::Cyan;
			this->button_Continuar_Partida->Font = (gcnew System::Drawing::Font(L"MV Boli", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Continuar_Partida->Location = System::Drawing::Point(516, 317);
			this->button_Continuar_Partida->Name = L"button_Continuar_Partida";
			this->button_Continuar_Partida->Size = System::Drawing::Size(244, 81);
			this->button_Continuar_Partida->TabIndex = 9;
			this->button_Continuar_Partida->Text = L"Continuar";
			this->button_Continuar_Partida->UseVisualStyleBackColor = false;
			this->button_Continuar_Partida->Visible = false;
			this->button_Continuar_Partida->Click += gcnew System::EventHandler(this, &MyForm::button_Continuar_Partida_Click);
			// 
			// button_Nivel_2
			// 
			this->button_Nivel_2->BackColor = System::Drawing::Color::Maroon;
			this->button_Nivel_2->Font = (gcnew System::Drawing::Font(L"MV Boli", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Nivel_2->ForeColor = System::Drawing::Color::Lime;
			this->button_Nivel_2->Location = System::Drawing::Point(387, 388);
			this->button_Nivel_2->Name = L"button_Nivel_2";
			this->button_Nivel_2->Size = System::Drawing::Size(285, 84);
			this->button_Nivel_2->TabIndex = 8;
			this->button_Nivel_2->Text = L"Nivel 2";
			this->button_Nivel_2->UseVisualStyleBackColor = false;
			this->button_Nivel_2->Visible = false;
			this->button_Nivel_2->Click += gcnew System::EventHandler(this, &MyForm::button_Nivel_2_Click);
			// 
			// button_Ranking_2
			// 
			this->button_Ranking_2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_Ranking_2->Font = (gcnew System::Drawing::Font(L"MV Boli", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Ranking_2->ForeColor = System::Drawing::Color::Navy;
			this->button_Ranking_2->Location = System::Drawing::Point(678, 388);
			this->button_Ranking_2->Name = L"button_Ranking_2";
			this->button_Ranking_2->Size = System::Drawing::Size(168, 84);
			this->button_Ranking_2->TabIndex = 7;
			this->button_Ranking_2->Text = L"Ranking";
			this->button_Ranking_2->UseVisualStyleBackColor = false;
			this->button_Ranking_2->Visible = false;
			this->button_Ranking_2->Click += gcnew System::EventHandler(this, &MyForm::button_Ranking_2_Click);
			// 
			// button_Ranking_1
			// 
			this->button_Ranking_1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button_Ranking_1->Font = (gcnew System::Drawing::Font(L"MV Boli", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Ranking_1->ForeColor = System::Drawing::Color::Navy;
			this->button_Ranking_1->Location = System::Drawing::Point(678, 288);
			this->button_Ranking_1->Name = L"button_Ranking_1";
			this->button_Ranking_1->Size = System::Drawing::Size(168, 84);
			this->button_Ranking_1->TabIndex = 6;
			this->button_Ranking_1->Text = L"Ranking";
			this->button_Ranking_1->UseVisualStyleBackColor = false;
			this->button_Ranking_1->Visible = false;
			this->button_Ranking_1->Click += gcnew System::EventHandler(this, &MyForm::button_Ranking_1_Click);
			// 
			// button_Nivel_1
			// 
			this->button_Nivel_1->BackColor = System::Drawing::Color::Maroon;
			this->button_Nivel_1->Font = (gcnew System::Drawing::Font(L"MV Boli", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Nivel_1->ForeColor = System::Drawing::Color::Lime;
			this->button_Nivel_1->Location = System::Drawing::Point(387, 288);
			this->button_Nivel_1->Name = L"button_Nivel_1";
			this->button_Nivel_1->Size = System::Drawing::Size(285, 84);
			this->button_Nivel_1->TabIndex = 5;
			this->button_Nivel_1->Text = L"Nivel 1";
			this->button_Nivel_1->UseVisualStyleBackColor = false;
			this->button_Nivel_1->Visible = false;
			this->button_Nivel_1->Click += gcnew System::EventHandler(this, &MyForm::button_Nivel_1_Click);
			// 
			// Boton_Pausa
			// 
			this->Boton_Pausa->BackColor = System::Drawing::Color::Yellow;
			this->Boton_Pausa->Font = (gcnew System::Drawing::Font(L"MV Boli", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Boton_Pausa->ForeColor = System::Drawing::Color::Black;
			this->Boton_Pausa->Location = System::Drawing::Point(14, 16);
			this->Boton_Pausa->Name = L"Boton_Pausa";
			this->Boton_Pausa->Size = System::Drawing::Size(116, 32);
			this->Boton_Pausa->TabIndex = 0;
			this->Boton_Pausa->Text = L"Pausa";
			this->Boton_Pausa->UseVisualStyleBackColor = false;
			this->Boton_Pausa->Visible = false;
			this->Boton_Pausa->Click += gcnew System::EventHandler(this, &MyForm::Boton_Pausa_Click);
			// 
			// label_texto
			// 
			this->label_texto->AutoSize = true;
			this->label_texto->BackColor = System::Drawing::Color::Maroon;
			this->label_texto->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label_texto->Font = (gcnew System::Drawing::Font(L"MV Boli", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_texto->ForeColor = System::Drawing::Color::Lime;
			this->label_texto->Location = System::Drawing::Point(387, 249);
			this->label_texto->Name = L"label_texto";
			this->label_texto->Padding = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->label_texto->Size = System::Drawing::Size(177, 23);
			this->label_texto->TabIndex = 13;
			this->label_texto->Text = L"Ingrese su nombre:";
			this->label_texto->Visible = false;
			// 
			// Timer_Menu
			// 
			this->Timer_Menu->Enabled = true;
			this->Timer_Menu->Tick += gcnew System::EventHandler(this, &MyForm::Timer0_Tick);
			// 
			// Timer_Juego
			// 
			this->Timer_Juego->Tick += gcnew System::EventHandler(this, &MyForm::Timer_Juego_Tick);
			// 
			// Box_Ranking
			// 
			this->Box_Ranking->BackColor = System::Drawing::Color::Teal;
			this->Box_Ranking->Font = (gcnew System::Drawing::Font(L"MV Boli", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Box_Ranking->Location = System::Drawing::Point(452, 124);
			this->Box_Ranking->Name = L"Box_Ranking";
			this->Box_Ranking->Padding = System::Windows::Forms::Padding(20, 10, 10, 10);
			this->Box_Ranking->Size = System::Drawing::Size(370, 420);
			this->Box_Ranking->TabIndex = 15;
			this->Box_Ranking->Text = L"  ";
			this->Box_Ranking->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->ControlBox = false;
			this->Controls->Add(this->Panel);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Chris: una aventura bajo el agua";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Panel->ResumeLayout(false);
			this->Panel->PerformLayout();
			this->ResumeLayout(false);

		}
		//
#pragma endregion
	//SFX Musica de fondo
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Musica_Fondo->PlayLooping();
	}

	//Boton instrucciones
	private: System::Void button_click_Instrucciones(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		button_atras->Visible = true;
		Buttons_Inicio(false);
		g->DrawImage(bmpInstrucciones, 0, 0, Panel->Width, Panel->Height);
	}

	//Boton creditos
	private: System::Void boton_click_creditos(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		button_atras->Visible = true;
		Buttons_Inicio(false);
		g->DrawImage(bmpCredits, 0, 0, Panel->Width, Panel->Height);
	}

	//Boton Salir (cierra el formulario)
	private: System::Void button_click_Salir(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Timer_Menu->Enabled = false;
		Timer_Juego->Enabled = false;
		Application::Exit();
	}

	//Boton atras en el menu principal
	private: System::Void button_click_atras(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Timer_Juego->Enabled = false;
		button_atras->Visible = false;
		Buttons_Inicio(true);
		Buttons_Menu_Seleccion(false);
	}
	
	//Jugar y va a seleccion de niveles INGRESA NOMBRE
	private: System::Void button_click_Jugar(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Buttons_Menu_Seleccion(true);
		button_atras->Visible = true;
		Buttons_Inicio(false);
		g->DrawImage(bmpMenu, 0, 0, Panel->Width, Panel->Height);
	}

	//Seleccion de niveles   	
	private: System::Void button_Nivel_1_Click(System::Object^ sender, System::EventArgs^ e) {
		controller->Nueva_Partida(1);
		Empezar_Juego();
	}
	private: System::Void button_Nivel_2_Click(System::Object^ sender, System::EventArgs^ e) {
		controller->Nueva_Partida(2);
		Empezar_Juego();
	}



	//Ranking de partidas
	//De nivel 1
	private: System::Void button_Ranking_1_Click(System::Object^ sender, System::EventArgs^ e) {
		Buttons_Menu_Seleccion(false);
		Box_Ranking->Visible = true;
		Button_cerrar_rank->Visible = true;
		button_atras->Visible = false;
		//Para ranking
		String^ texto = gcnew String(controller->getRanking(1).c_str());
		Box_Ranking->Text = "Ranking Nivel 1\nNombre     Puntaje\n" + texto;
		g->DrawImage(Image::FromFile("Resources//Fondos//Menu_Seleccion.png"), 0, 0, Panel->Width, Panel->Height);
		delete texto;
	}
	//De nivel 2
	private: System::Void button_Ranking_2_Click(System::Object^ sender, System::EventArgs^ e) {
		Buttons_Menu_Seleccion(false);
		Box_Ranking->Visible = true;
		Button_cerrar_rank->Visible = true;
		button_atras->Visible = false;
		//Para ranking
		String^ texto = gcnew String(controller->getRanking(2).c_str());
		Box_Ranking->Text = "Ranking Nivel 2\nNombre     Puntaje\n" + texto;
		g->DrawImage(Image::FromFile("Resources//Fondos//Menu_Seleccion.png"), 0, 0, Panel->Width, Panel->Height);
		delete texto;
	}


	//Pausa el timer del juego
	private: System::Void Boton_Pausa_Click(System::Object^ sender, System::EventArgs^ e) {
		Timer_Juego->Enabled = false;
		Boton_Pausa->Visible = false;
		button_Continuar_Partida->Visible = true;
		boton_Terminar_Partida->Visible = true;
		//Aparece un box con opciones de continuar a salir al menu principal
		g->DrawImage(Image::FromFile("Resources//Fondos//Menu_Seleccion.png"), 0, 0, Panel->Width, Panel->Height);
		g->DrawImage(Image::FromFile("Resources//Fondos//Menu_Pausa.png"), 420, 120, 430, 456);
	}

	//Boton para continuar con la misma partida en menu de pausa
	private: System::Void button_Continuar_Partida_Click(System::Object^ sender, System::EventArgs^ e) {
		Timer_Juego->Enabled = true;
		button_Continuar_Partida->Visible = false;
		boton_Terminar_Partida->Visible = false;
		Boton_Pausa->Visible = true;
	}
	//Boton para finalizar una partida y almacenar datos en el ranking
	private: System::Void boton_Terminar_Partida_Click(System::Object^ sender, System::EventArgs^ e) {
		//Botones de menu de pausa
		button_Continuar_Partida->Visible = false;
		boton_Terminar_Partida->Visible = false;
		Boton_Pausa->Visible = false;
		//Aparecen objetos de Menu principal
		Buttons_Inicio(true);
		Cofre->Visible = false;
		
		//Pasamos por parametro los datos del textbox (textbox es un managed string, lo pasamos a unmanaged)
		string nombre= msclr::interop::marshal_as<std::string>(textBox_nombre->Text);
		//Vemos si el string es vacio
		if (nombre.empty()) {
			nombre = "Jugador";
		}
		controller->Salir_Partida(nombre);
	}
	//Boton para cerrar menu de ranking
	private: System::Void Button_cerrar_rank_Click(System::Object^ sender, System::EventArgs^ e) {
		Button_cerrar_rank->Visible = false;
		Box_Ranking->Visible = false;
		button_atras->Visible = true;
		g->DrawImage(Image::FromFile("Resources//Fondos//Menu_Seleccion.png"), 0, 0, Panel->Width, Panel->Height);
		Buttons_Menu_Seleccion(true);
	}
	//Timers
	private: System::Void Timer0_Tick(System::Object^ sender, System::EventArgs^ e) {
		g->DrawImage(bmpMain, 0, 0, Panel->Width, Panel->Height);
	}
	//Timer Juego
	private: System::Void Timer_Juego_Tick(System::Object^ sender, System::EventArgs^ e) {
		KeyPreview = true;
		//Draw
		controller->getFondo()->Mostrar(buffer->Graphics);
		//Controller
		controller->Juego(buffer->Graphics);
		//Partida acaba y aparece fin
		if (controller->getTiempo() == false||controller->getVidas()==false) {
			Timer_Juego->Enabled = false;
			boton_Terminar_Partida->Visible = true;
			//Cofre e información de partida
			Menu_Final();
			Boton_Pausa->Visible = false;
		}
		//Render
		buffer->Render(g);
	}

	//Key_Down
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W:
			controller->getBuzo()->Mover(buffer->Graphics, 'W');
			break;
		case Keys::S:
			controller->getBuzo()->Mover(buffer->Graphics, 'S');
			break;
		}
	}

	//Box Menu de inicio
	void Buttons_Inicio(bool visible) {
		Timer_Menu->Enabled = visible;
		button_jugar->Visible = visible;
		button_instrucciones->Visible = visible;
		button_creditos->Visible = visible;
		button_salir->Visible = visible;
	}

	//Box Menu de seleccion de nivel
	void Buttons_Menu_Seleccion(bool visible) {
		button_Nivel_1->Visible = visible;
		button_Nivel_2->Visible = visible;
		button_Ranking_1->Visible = visible;
		button_Ranking_2->Visible = visible;
		textBox_nombre->Visible = visible;
		label_texto->Visible = visible;
	}

	//Box para juegos
	void Empezar_Juego() {
		Timer_Menu->Enabled = false;
		Timer_Juego->Enabled = true;
		button_atras->Visible = false;
		Boton_Pausa->Visible = true;
		Buttons_Inicio(false);
		Buttons_Menu_Seleccion(false);
	}

	void Menu_Final() {
		//La información del cofre recogido
		Random r;
		int tipo;
		tipo = r.Next(1, 6);
		if (controller->getCofres() > 0) {
			switch (tipo)
			{
			case 1:
				Cofre->Text = "¡FIN DE PARTIDA!\nRecogiste un cofre!Este dice : Poblaciones mundiales de peces se estan agotando rapidamente debido a la demanda, la perdida de su habitat y las practicas de pesca insostenibles.Al hacer la compra o salir a cenar, ayudar a reducir la demanda de estas especies sobreexplotadas escogiendo productos  saludables y sostenibles.";
				Cofre->Visible = true;
				break;
			case 2:
				Cofre->Text = "¡FIN DE PARTIDA!\nRecogiste un cofre! Este dice: Los plasticos que terminan como basura en el mar contribuyen a la destruccion de los habitats y pueden provocar la muerte a miles de animales marinos cada año. Para limitar su impacto, podemos reutilizar las botellas de agua, guardar los alimentos en recipientes no desechables, utilizar bolsas de tela para transportar nuestras compras. En el fondo se trata de reciclar lo máximo posible.";
				Cofre->Visible = true;
				break;
			case 3:
				Cofre->Text = "¡FIN DE PARTIDA!\nRecogiste un cofre! Este dice: Si te gusta el buceo, el surf, o relajarse en la playa, dejemos limpio una vez abandonemos la playa. Alienta a tantas personas como podamos a respetar el medio marino y házlos participe de ello.";
				Cofre->Visible = true;
				break;
			case 4:
				Cofre->Text = "¡FIN DE PARTIDA!\nRecogiste un cofre! Este dice: Algunos productos contribuyen al daño de los fragiles arrecifes de coral y las poblaciones marinas. Evite comprar articulos tales como joyería de coral, accesorios de pelo hechos con conchas (a partir de las tortugas carey), y productos derivados del tiburon.";
				Cofre->Visible = true;
				break;
			case 5:
				Cofre->Text = "¡FIN DE PARTIDA!\nRecogiste un cofre! Este dice: Intentar ir con cuidado con los alimentos prominentes del mar que le damos a nuestras mascotas. Leamos las etiquetas de los productos y consideremos la sostenibilidad de estos a la hora de comprarlos. Evitar comprar para un acuario los peces de agua salada capturados de su habitat natural ni arrojar peces u otras especies marinas criadas en acuarios al mar, esta practica puede introducir especies no autoctonas perjudiciales para el ecosistema existente.";
				Cofre->Visible = true;
				break;
			}
		}
		else Cofre->Text = "¡FIN DE PARTIDA!\nNo recogiste ningun cofre! Sigue intentando";
		Cofre->Visible = true;
	}
};
}