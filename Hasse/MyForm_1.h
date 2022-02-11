#pragma once
#include "stdafx.h"			//  <-namespace COLORES en stdafx.h

//include creado, matriz 2D, colores

namespace Hasse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		/*—————————————————————————————————————————————————————————————————————————
		|						↓====CODIGO AGREGADO====↓
		————————————————————————↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓——————————————————————————*/
		Graphics ^ g;
		BufferedGraphicsContext ^bfc;
		BufferedGraphics ^bf;

		cmatrix *m0;
		int paso;

		//↓ —la fuente del texto de matrices— ↓
	public: System::Drawing::Font ^MFont = gcnew System::Drawing::Font(
		L"Consolas",
		12,
		FontStyle::Bold,
		GraphicsUnit::Point,
		static_cast<System::Byte>(0));

			//↓ —colores de textos de matrices (0's y 1's con colores diferentes)— ↓
	public: SolidBrush ^ MBrush0 = gcnew System::Drawing::SolidBrush(Color::FromArgb(C::COLORES::MATRIZ_0));


	public: SolidBrush ^ MBrush1 = gcnew System::Drawing::SolidBrush(Color::FromArgb(C::COLORES::MATRIZ_1));
	public: Pen ^ LPen0 = gcnew System::Drawing::Pen(MBrush1);
	private: System::Windows::Forms::Label^  TXT_pasoN;
	private: System::Windows::Forms::Label^  txt1;
	private: System::Windows::Forms::Label^  TXT_M;




	public:
		MyForm(cmatrix &mi) { //Constructor
			InitializeComponent();
			m0 = &mi;
			*m0 = mi;
		}
		MyForm(cmatrix &mi, int paso) :MyForm(mi) {
			this->paso = paso;
		}

	protected:
		~MyForm() {
			if (components) {
				delete components;
			}
		}

	private: System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
			 void InitializeComponent(void) {
				 this->TXT_pasoN = (gcnew System::Windows::Forms::Label());
				 this->TXT_M = (gcnew System::Windows::Forms::Label());
				 this->txt1 = (gcnew System::Windows::Forms::Label());
				 this->SuspendLayout();
				 // 
				 // TXT_pasoN
				 // 
				 this->TXT_pasoN->AutoSize = true;
				 this->TXT_pasoN->Font = (gcnew System::Drawing::Font(L"Times New Roman", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->TXT_pasoN->Location = System::Drawing::Point(10, 10);
				 this->TXT_pasoN->Name = L"TXT_pasoN";
				 this->TXT_pasoN->Size = System::Drawing::Size(218, 73);
				 this->TXT_pasoN->TabIndex = 13;
				 this->TXT_pasoN->Text = L"Paso x:";
				 // 
				 // TXT_M
				 // 
				 this->TXT_M->AutoSize = true;
				 this->TXT_M->Font = (gcnew System::Drawing::Font(L"Times New Roman", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->TXT_M->Location = System::Drawing::Point(219, 10);
				 this->TXT_M->Name = L"TXT_M";
				 this->TXT_M->Size = System::Drawing::Size(93, 73);
				 this->TXT_M->TabIndex = 12;
				 this->TXT_M->Text = L"M";
				 // 
				 // txt1
				 // 
				 this->txt1->AutoSize = true;
				 this->txt1->Font = (gcnew System::Drawing::Font(L"Calibri", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->txt1->Location = System::Drawing::Point(17, 87);
				 this->txt1->Name = L"txt1";
				 this->txt1->Size = System::Drawing::Size(158, 36);
				 this->txt1->TabIndex = 14;
				 this->txt1->Text = L"Descripción.";
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 this->BackColor = System::Drawing::Color::Gray;
				 this->ClientSize = System::Drawing::Size(970, 690);
				 this->Controls->Add(this->txt1);
				 this->Controls->Add(this->TXT_pasoN);
				 this->Controls->Add(this->TXT_M);
				 this->MaximizeBox = false;
				 this->Name = L"MyForm";
				 this->Text = L"Paso ";
				 this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
			 /*—————————————————————————————————————————————————————————————————————————
			 |						↓====CODIGO AGREGADO====↓
			 ————————————————————————↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓————————————————————————*/
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {


		g = CreateGraphics();
		bfc = BufferedGraphicsManager::Current;
		bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->PageUnit = GraphicsUnit::Pixel;

		switch (paso) {
		case 1:
			txt1->Text = gcnew String("Se suman los indicadores y se\ncomparan para llenar la Matriz\nde relaciones.");
			TXT_pasoN->Text = gcnew String("Paso 1:");
			TXT_M->Text = gcnew String("M");
			this->Text += gcnew String("1");
			break;
		case 2:
			txt1->Text = gcnew String("La Matriz booleana de relaciones\nse eleva al cuadrado, para extraer\nlas aristas transitivas.");
			TXT_pasoN->Text = gcnew String("Paso 2:");
			TXT_M->Text = gcnew String("M²");
			this->Text += gcnew String("2");
			break;
		case 3:
			txt1->Text = gcnew String("Se restan las matrices y se ordenan\nlos proyectos internamente.");
			TXT_pasoN->Text = gcnew String("Paso 3:");
			TXT_M->Text = gcnew String("M^¬M²");
			this->Text += gcnew String("3");
			break;
		}

		m0->set_WH(bf->Graphics, MFont);
		m0->x = 50;
		m0->y = 220;
		bf->Graphics->FillRectangle(gcnew SolidBrush(Color::FromArgb(C::COLORES::FONDO)), g->ClipBounds);
		m0->draw(bf->Graphics, MFont, MBrush0, MBrush1, this->Location.X, this->Location.Y);
		
		this->ResizeRedraw = true;
		this->ResumeLayout(false);
		this->PerformLayout();
		bf->Render(g);

	};
	};
}