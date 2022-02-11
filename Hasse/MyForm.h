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

	private: System::Windows::Forms::Button^  button1;






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
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // TXT_pasoN
				 // 
				 this->TXT_pasoN->AutoSize = true;
				 this->TXT_pasoN->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->TXT_pasoN->Location = System::Drawing::Point(15, 40);
				 this->TXT_pasoN->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->TXT_pasoN->Name = L"TXT_pasoN";
				 this->TXT_pasoN->Size = System::Drawing::Size(107, 22);
				 this->TXT_pasoN->TabIndex = 13;
				 this->TXT_pasoN->Text = L"Descripcion";
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(338, 190);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(110, 32);
				 this->button1->TabIndex = 14;
				 this->button1->Text = L"Cerrar";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				 this->BackColor = System::Drawing::Color::Aquamarine;
				 this->ClientSize = System::Drawing::Size(475, 344);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->TXT_pasoN);
				 this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
				 this->MaximizeBox = false;
				 this->MaximumSize = System::Drawing::Size(580, 450);
				 this->Name = L"MyForm";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Paso ";
				 this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {


		g = CreateGraphics();
		bfc = BufferedGraphicsManager::Current;
		bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->PageUnit = GraphicsUnit::Pixel;

		switch (paso) {
		case 1:
		/*	txt1->Text = gcnew String(" ");*/
			TXT_pasoN->Text = gcnew String("Representación del Orden Parcial en una Matriz");
			/*TXT_M->Text = gcnew String("");*/
			this->Text += gcnew String("");
			break;
		case 2:
		/*	txt1->Text = gcnew String(" ");*/
			TXT_pasoN->Text = gcnew String("M2 se consigue mediante M1 x M1");
			/*TXT_M->Text = gcnew String("");*/
			this->Text += gcnew String("");
			break;
		case 3:
			/*txt1->Text = gcnew String(" ");*/
			TXT_pasoN->Text = gcnew String("Se eliminan las ubicaciones de los 1 donde coinciden M1 y M2");
			/*TXT_M->Text = gcnew String("");*/
			this->Text += gcnew String("");
			break;
		}

		m0->set_WH(bf->Graphics, MFont);
		m0->x = 70;
		m0->y = 80;
		bf->Graphics->FillRectangle(gcnew SolidBrush(Color::Aquamarine), g->ClipBounds);
		m0->draw(bf->Graphics, MFont, MBrush0, MBrush1, this->Location.X, this->Location.Y);
		
		this->ResizeRedraw = true;
		this->ResumeLayout(false);
		this->PerformLayout();
		bf->Render(g);

	};
	private: System::Void Next_Step_Click(System::Object^  sender, System::EventArgs^  e) {
		
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}
};
}