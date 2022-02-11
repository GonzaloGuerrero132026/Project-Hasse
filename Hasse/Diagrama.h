#pragma once
#include "stdafx.h"	
#include "diagram.h"

namespace Hasse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	public ref class Diagrama : public System::Windows::Forms::Form {
		Graphics ^ g;
		BufferedGraphicsContext ^bfc;
		BufferedGraphics ^bf;
		cmatrix *mF;
		diagram *dF;

	public: SolidBrush ^ MBrush0 = gcnew System::Drawing::SolidBrush(Color::FromArgb(C::COLORES::MATRIZ_0));


	public: SolidBrush ^ MBrush1 = gcnew System::Drawing::SolidBrush(Color::FromArgb(C::COLORES::MATRIZ_1));
	public: Pen ^ LPen0 = gcnew System::Drawing::Pen(MBrush1);
	private: System::Windows::Forms::Label^  txt1;
	private: System::Windows::Forms::Button^  button1;
	public:
	public: System::Drawing::Font ^MFont = gcnew System::Drawing::Font(
		L"Consolas",
		12,
		FontStyle::Bold,
		GraphicsUnit::Point,
		static_cast<System::Byte>(0));



	public:
		Diagrama(diagram &d, cmatrix &m) {
			InitializeComponent();
			dF = &d;
			*dF = d;
			mF = &m;
			*mF = m;
		};

	protected:
		~Diagrama() {
			if (components) {
				delete components;
			}
		};

	private:System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void) {
				this->txt1 = (gcnew System::Windows::Forms::Label());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// txt1
				// 
				this->txt1->AutoSize = true;
				this->txt1->Font = (gcnew System::Drawing::Font(L"Calibri", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->txt1->Location = System::Drawing::Point(18, 14);
				this->txt1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->txt1->Name = L"txt1";
				this->txt1->Size = System::Drawing::Size(362, 54);
				this->txt1->TabIndex = 15;
				this->txt1->Text = L"Diagrama de Hasse";
				this->txt1->Click += gcnew System::EventHandler(this, &Diagrama::txt1_Click);
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(387, 29);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(168, 39);
				this->button1->TabIndex = 16;
				this->button1->Text = L"Cerrar";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &Diagrama::button1_Click);
				// 
				// Diagrama
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
				this->BackColor = System::Drawing::Color::Aquamarine;
				this->ClientSize = System::Drawing::Size(567, 444);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->txt1);
				this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
				this->MaximizeBox = false;
				this->MaximumSize = System::Drawing::Size(600, 700);
				this->Name = L"Diagrama";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Diagrama Hasse";
				this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
				this->Load += gcnew System::EventHandler(this, &Diagrama::Diagrama_Load);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion


	private: System::Void Diagrama_Load(System::Object^  sender, System::EventArgs^  e) {

		g = CreateGraphics();
		bfc = BufferedGraphicsManager::Current;
		bf = bfc->Allocate(g, this->ClientRectangle);
		bf->Graphics->PageUnit = GraphicsUnit::Pixel;

		dF->x = 95;
		dF->y += 20;

		txt1->Text = gcnew String("Diagrama de Hasse ");
		mF->set_WH(bf->Graphics, MFont);
	/*	:FromArgb(C::COLORES::FONDO)*/
		bf->Graphics->FillRectangle(gcnew SolidBrush(Color::Aquamarine), g->ClipBounds);
		dF->draw(*mF, bf->Graphics, MFont, MBrush0, MBrush1, LPen0);
		
		this->ResizeRedraw = true;
		this->ResumeLayout(false);
		this->PerformLayout();
		bf->Render(g);
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void txt1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};

};
