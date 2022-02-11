#pragma once

#include "stdafx.h"	
#include "MyForm.h"
#include "Diagrama.h"


namespace Hasse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for input
	/// </summary>
	public ref class input : public System::Windows::Forms::Form {
	public:

		/*—————————————————————————————————————————————————————————————————————————
		|						↓====CODIGO AGREGADO====↓
		————————————————————————↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓——————————————————————————*/
		List<Label^> ^i_txt;
		List<List<NumericUpDown^>^> v_num;
		List<TextBox^> ^v_proyectos;
		int num_Proyectos;
		int num_Indicadores;
		int max_random;

		input(void) {
			InitializeComponent();

			num_Proyectos = 6;
			num_Indicadores = 3;
			max_random = 20;

			i_txt = gcnew List<Label^>();
			v_proyectos = gcnew List<TextBox^>();

			navComponentsInit();
			changeVisible();

			//valores iniciales de ejemplos
			v_num[0][0]->Value = Decimal::ToInt32(6);
			v_num[1][0]->Value = Decimal::ToInt32(2);
			v_num[2][0]->Value = Decimal::ToInt32(5);
			v_num[0][1]->Value = Decimal::ToInt32(5);
			v_num[1][1]->Value = Decimal::ToInt32(2);
			v_num[2][1]->Value = Decimal::ToInt32(3);
			v_num[0][2]->Value = Decimal::ToInt32(7);
			v_num[1][2]->Value = Decimal::ToInt32(3);
			v_num[2][2]->Value = Decimal::ToInt32(5);
			v_num[0][3]->Value = Decimal::ToInt32(4);
			v_num[1][3]->Value = Decimal::ToInt32(6);
			v_num[2][3]->Value = Decimal::ToInt32(2);
			v_num[0][4]->Value = Decimal::ToInt32(3);
			v_num[1][4]->Value = Decimal::ToInt32(1);
			v_num[2][4]->Value = Decimal::ToInt32(6);
			v_num[0][5]->Value = Decimal::ToInt32(6);
			v_num[1][5]->Value = Decimal::ToInt32(4);
			v_num[2][5]->Value = Decimal::ToInt32(5);
		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~input() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  box1;
	private: System::Windows::Forms::GroupBox^  box2;

	private: System::Windows::Forms::NumericUpDown^  nProyectos;
	private: System::Windows::Forms::Label^  label_nIndicadores;
	private: System::Windows::Forms::Label^  label_nProyectos;
	private: System::Windows::Forms::NumericUpDown^  nIndicadores;
	private: System::Windows::Forms::Button^  btnRandVal;
	private: System::Windows::Forms::Label^  txt_maxrand;
	private: System::Windows::Forms::Label^  txt_proyectolist;
	private: System::Windows::Forms::NumericUpDown^  nMaxRand;
	private: System::Windows::Forms::Label^  txt_line;
	private: System::Windows::Forms::Button^  button1;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		void navComponentsInit(void) {
			this->box2->SuspendLayout();
			this->SuspendLayout();
			for (int i = 0; i < C::OTROS::MAXI; i++) {
				Label ^L = gcnew Label();
				this->box2->Controls->Add(L);
				L->AutoSize = true;
				L->Location = System::Drawing::Point(C::FI::itxt_x + (C::FI::i_dx*i), C::FI::itxt_y);
				L->Name = L"i_txt";
				L->Name = L->Name + i;
				L->Size = System::Drawing::Size(100, 100);
				L->TabIndex = 16;
				L->Text = L"i";
				L->Text = L->Text + gcnew String(to_string(i).c_str());
				i_txt->Add(L);
			}

			for (int n = 0; n < C::OTROS::MAXI; n++) {
				List<NumericUpDown^> ^tempv = gcnew List<NumericUpDown^>();
				for (int m = 0; m < C::OTROS::MAXP; m++) {
					NumericUpDown ^N = gcnew NumericUpDown();
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(N))->BeginInit();
					this->box2->Controls->Add(N);
					N->Location = System::Drawing::Point(C::FI::in_x + (C::FI::i_dx*n), C::FI::in_y + (C::FI::p_dy*m));
					N->Maximum = System::Decimal(200);
					N->Minimum = System::Decimal(-200);
					N->Name = L"in";
					N->Name = N->Name + m;
					N->Size = System::Drawing::Size(39, 20);
					N->TabIndex = 6;
					N->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 0, 0, 0, 0 });
					(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(N))->EndInit();
					tempv->Add(N);
				}
				v_num.Add(tempv);
			}

			for (int j = 0; j < C::OTROS::MAXP; j++) {
				TextBox ^T = gcnew TextBox();
				this->box2->Controls->Add(T);
				T->Location = System::Drawing::Point(C::FI::p_x, C::FI::p_y + (C::FI::p_dy*j));
				T->Name = L"T";
				T->Name = T->Name + j;
				T->Size = System::Drawing::Size(68, 20);
				T->TabIndex = 0;
				T->Text = L"Proyecto ";
				T->Text = T->Text + gcnew String(to_string(j).c_str());
				v_proyectos->Add(T);
			}

			this->box2->ResumeLayout(false);
			this->box2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

		void changeVisible() {
			this->box2->SuspendLayout();
			this->SuspendLayout();
			for (int p = 0; p < C::OTROS::MAXP; p++) {
				v_proyectos[p]->Visible = (p < num_Proyectos) ? true : false;
				for (int i = 0; i < C::OTROS::MAXI; i++) {
					v_num[i][p]->Visible = (i < num_Indicadores && p < num_Proyectos) ? true : false;
				}
			}
			for (int i = 0; i < C::OTROS::MAXI; i++) {
				i_txt[i]->Visible = i < (num_Indicadores) ? true : false;
			}
			this->box2->ResumeLayout(false);
			this->box2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->box1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_nIndicadores = (gcnew System::Windows::Forms::Label());
			this->label_nProyectos = (gcnew System::Windows::Forms::Label());
			this->nIndicadores = (gcnew System::Windows::Forms::NumericUpDown());
			this->nProyectos = (gcnew System::Windows::Forms::NumericUpDown());
			this->box2 = (gcnew System::Windows::Forms::GroupBox());
			this->txt_line = (gcnew System::Windows::Forms::Label());
			this->txt_proyectolist = (gcnew System::Windows::Forms::Label());
			this->nMaxRand = (gcnew System::Windows::Forms::NumericUpDown());
			this->txt_maxrand = (gcnew System::Windows::Forms::Label());
			this->btnRandVal = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->box1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nIndicadores))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nProyectos))->BeginInit();
			this->box2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nMaxRand))->BeginInit();
			this->SuspendLayout();
			// 
			// box1
			// 
			this->box1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->box1->Controls->Add(this->label_nIndicadores);
			this->box1->Controls->Add(this->label_nProyectos);
			this->box1->Controls->Add(this->nIndicadores);
			this->box1->Controls->Add(this->nProyectos);
			this->box1->Location = System::Drawing::Point(29, 23);
			this->box1->Name = L"box1";
			this->box1->Size = System::Drawing::Size(201, 89);
			this->box1->TabIndex = 0;
			this->box1->TabStop = false;
			this->box1->Text = L" 1) Editar proyectos ";
			// 
			// label_nIndicadores
			// 
			this->label_nIndicadores->AutoSize = true;
			this->label_nIndicadores->Location = System::Drawing::Point(16, 52);
			this->label_nIndicadores->Name = L"label_nIndicadores";
			this->label_nIndicadores->Size = System::Drawing::Size(120, 13);
			this->label_nIndicadores->TabIndex = 5;
			this->label_nIndicadores->Text = L"N° Indicadores (max:20)";
			// 
			// label_nProyectos
			// 
			this->label_nProyectos->AutoSize = true;
			this->label_nProyectos->Location = System::Drawing::Point(16, 26);
			this->label_nProyectos->Name = L"label_nProyectos";
			this->label_nProyectos->Size = System::Drawing::Size(112, 13);
			this->label_nProyectos->TabIndex = 4;
			this->label_nProyectos->Text = L"N° Proyectos (max:50)";
			// 
			// nIndicadores
			// 
			this->nIndicadores->Location = System::Drawing::Point(142, 50);
			this->nIndicadores->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->nIndicadores->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nIndicadores->Name = L"nIndicadores";
			this->nIndicadores->Size = System::Drawing::Size(39, 20);
			this->nIndicadores->TabIndex = 3;
			this->nIndicadores->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->nIndicadores->ValueChanged += gcnew System::EventHandler(this, &input::nIndicadores_ValueChanged);
			// 
			// nProyectos
			// 
			this->nProyectos->Location = System::Drawing::Point(142, 24);
			this->nProyectos->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->nProyectos->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->nProyectos->Name = L"nProyectos";
			this->nProyectos->Size = System::Drawing::Size(39, 20);
			this->nProyectos->TabIndex = 2;
			this->nProyectos->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->nProyectos->ValueChanged += gcnew System::EventHandler(this, &input::nProyectos_ValueChanged);
			// 
			// box2
			// 
			this->box2->AutoSize = true;
			this->box2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->box2->Controls->Add(this->txt_line);
			this->box2->Controls->Add(this->txt_proyectolist);
			this->box2->Controls->Add(this->nMaxRand);
			this->box2->Controls->Add(this->txt_maxrand);
			this->box2->Controls->Add(this->btnRandVal);
			this->box2->Location = System::Drawing::Point(29, 118);
			this->box2->Name = L"box2";
			this->box2->Size = System::Drawing::Size(317, 104);
			this->box2->TabIndex = 1;
			this->box2->TabStop = false;
			this->box2->Text = L" 2) Editar pesos ";
			// 
			// txt_line
			// 
			this->txt_line->AutoSize = true;
			this->txt_line->Location = System::Drawing::Point(16, 58);
			this->txt_line->Name = L"txt_line";
			this->txt_line->Size = System::Drawing::Size(295, 13);
			this->txt_line->TabIndex = 15;
			this->txt_line->Text = L"---------------------------------------------------------------------------------"
				L"---------------";
			// 
			// txt_proyectolist
			// 
			this->txt_proyectolist->AutoSize = true;
			this->txt_proyectolist->Location = System::Drawing::Point(16, 75);
			this->txt_proyectolist->Name = L"txt_proyectolist";
			this->txt_proyectolist->Size = System::Drawing::Size(52, 13);
			this->txt_proyectolist->TabIndex = 11;
			this->txt_proyectolist->Text = L"Proyecto:";
			// 
			// nMaxRand
			// 
			this->nMaxRand->Location = System::Drawing::Point(248, 29);
			this->nMaxRand->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->nMaxRand->Name = L"nMaxRand";
			this->nMaxRand->Size = System::Drawing::Size(57, 20);
			this->nMaxRand->TabIndex = 6;
			this->nMaxRand->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->nMaxRand->ValueChanged += gcnew System::EventHandler(this, &input::nMaxRand_ValueChanged);
			// 
			// txt_maxrand
			// 
			this->txt_maxrand->AutoSize = true;
			this->txt_maxrand->Location = System::Drawing::Point(127, 31);
			this->txt_maxrand->Name = L"txt_maxrand";
			this->txt_maxrand->Size = System::Drawing::Size(115, 13);
			this->txt_maxrand->TabIndex = 6;
			this->txt_maxrand->Text = L"Rango max. de rand( ):";
			// 
			// btnRandVal
			// 
			this->btnRandVal->Location = System::Drawing::Point(19, 19);
			this->btnRandVal->Name = L"btnRandVal";
			this->btnRandVal->Size = System::Drawing::Size(100, 36);
			this->btnRandVal->TabIndex = 1;
			this->btnRandVal->Text = L"Llenar con num. del 0 al ->";
			this->btnRandVal->UseVisualStyleBackColor = true;
			this->btnRandVal->Click += gcnew System::EventHandler(this, &input::btnRandVal_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(236, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 89);
			this->button1->TabIndex = 2;
			this->button1->Text = L"COMENZAR!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &input::button1_Click);
			// 
			// input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Gray;
			this->ClientSize = System::Drawing::Size(374, 431);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->box2);
			this->Controls->Add(this->box1);
			this->Name = L"input";
			this->Padding = System::Windows::Forms::Padding(30);
			this->Text = L"input";
			this->box1->ResumeLayout(false);
			this->box1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nIndicadores))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nProyectos))->EndInit();
			this->box2->ResumeLayout(false);
			this->box2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nMaxRand))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void nProyectos_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		num_Proyectos = Decimal::ToInt32(nProyectos->Value);
		changeVisible();
	}
	private: System::Void nIndicadores_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		num_Indicadores = Decimal::ToInt32(nIndicadores->Value);
		changeVisible();
	}
	private: System::Void nMaxRand_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		max_random = Decimal::ToInt32(nMaxRand->Value);
		if (max_random == 0) max_random = 1;
	}
	private: System::Void btnRandVal_Click(System::Object^  sender, System::EventArgs^  e) {
		max_random = (int)Decimal::ToInt32(nMaxRand->Value);
		if (max_random == 0) {
			max_random = 1;
			nMaxRand->Value = 1;
		} else if (max_random > 200) {
			max_random = C::OTROS::RANGO_PESOS;
			nMaxRand->Value = C::OTROS::RANGO_PESOS;
		};

		for (int i = 0; i < num_Indicadores; i++) {
			for (int p = 0; p < num_Proyectos; p++) {
				v_num[i][p]->Value = rand() % Decimal::ToInt32(max_random);
			}
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		vector<int> pesos;
		for (int p = 0; p < num_Proyectos; p++) {
			int pesoi = 0;
			for (int i = 0; i < num_Indicadores; i++) {
				pesoi += Decimal::ToInt32(v_num[i][p]->Value);
			}
			pesos.push_back(pesoi);
		}
		cmatrix *mi = new cmatrix(pesos);
		cmatrix *mC = cmatrixOps::alCuadrado(*mi);
		cmatrix *mF= cmatrixOps::resta(*mi, *mC);
		diagram *dF = new diagram(*mF);


		MyForm ^p1 = gcnew MyForm(*mi, 1);
		MyForm ^p2 = gcnew MyForm(*mC, 2);
		MyForm ^p3 = gcnew MyForm(*mF, 3);
		Diagrama ^d = gcnew Diagrama(*dF, *mF);
		
		d->Show();
		p3->Show();
		p2->Show();
		p1->Show();
		
	}
};
}

