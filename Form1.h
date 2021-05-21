#pragma once
#include <Windows.h>
#include <time.h>
#include <math.h>
#include "Resource.h"
#include "Process.h"
#define INPUTSIZE 3
#define CLASS_COUNT comboBox1->Items->Count
#define MAX_Cycle 1e6


namespace WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->comboBox1->SelectedIndex = 0;
			Size = 0; // Baslangıcta örnek yok.
			random =  gcnew Random();
			randomColor = gcnew Color();
			ClassColorTable = gcnew Hashtable();
			for (int i = 0; i < this->CLASS_COUNT; i++)
			{
				randomColor = Color::FromArgb(random->Next(0, 255), random->Next(0, 255), random->Next(0, 255));
				ClassColorTable->Add(comboBox1->Items[i]->ToString(), randomColor);
				
			}
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			// Collect Garbage: w , p etc.

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		
		Samples* p; // örneklerimizi alıyoruz.
		double **w;
		int Size;
		float c;
		
		Hashtable^ ClassColorTable;
		Random^ random;
		Color^ randomColor;

		// Normalizasyon parametreleri
		float m1, m2;
		float s1, s2;
		


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ initialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomToolStripMenuItem;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ToolStripMenuItem^ traningToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deltaLearningToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ PerceptronLearningToolStripMenuItem;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label3;
	



		
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->initialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->randomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->traningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PerceptronLearningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deltaLearningToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Lavender;
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(448, 421);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(525, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(59, 24);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::Window;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Class 1", L"Class 2" });
			this->comboBox1->Location = System::Drawing::Point(525, 79);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(959, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->initialToolStripMenuItem,
					this->traningToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// initialToolStripMenuItem
			// 
			this->initialToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomToolStripMenuItem });
			this->initialToolStripMenuItem->Name = L"initialToolStripMenuItem";
			this->initialToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->initialToolStripMenuItem->Text = L"initial";
			// 
			// randomToolStripMenuItem
			// 
			this->randomToolStripMenuItem->Name = L"randomToolStripMenuItem";
			this->randomToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->randomToolStripMenuItem->Text = L"random";
			this->randomToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::randomToolStripMenuItem_Click);
			// 
			// traningToolStripMenuItem
			// 
			this->traningToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->PerceptronLearningToolStripMenuItem,
					this->deltaLearningToolStripMenuItem
			});
			this->traningToolStripMenuItem->Name = L"traningToolStripMenuItem";
			this->traningToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->traningToolStripMenuItem->Text = L"Training";
			// 
			// PerceptronLearningToolStripMenuItem
			// 
			this->PerceptronLearningToolStripMenuItem->Name = L"PerceptronLearningToolStripMenuItem";
			this->PerceptronLearningToolStripMenuItem->Size = System::Drawing::Size(238, 22);
			this->PerceptronLearningToolStripMenuItem->Text = L"SingleLayerPerceptronLearning";
			this->PerceptronLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::PerceptronLearningToolStripMenuItem_Click);
			// 
			// deltaLearningToolStripMenuItem
			// 
			this->deltaLearningToolStripMenuItem->Name = L"deltaLearningToolStripMenuItem";
			this->deltaLearningToolStripMenuItem->Size = System::Drawing::Size(238, 22);
			this->deltaLearningToolStripMenuItem->Text = L"SingleLayerDeltaLearning";
			this->deltaLearningToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deltaLearningToolStripMenuItem_Click);
			// 
			
			// button2
			// 
			this->button2->Location = System::Drawing::Point(590, 40);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 24);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Remove";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(522, 133);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Size : ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(522, 161);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Cycle : ";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(727, 65);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(204, 296);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(794, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(51, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"WEIGHT";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(959, 489);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->comboBox1->Items->Add("Class " + (CLASS_COUNT + 1) );

		randomColor = Color::FromArgb(random->Next(0, 255), random->Next(0, 255), random->Next(0, 255));
		ClassColorTable->Add(comboBox1->Items[CLASS_COUNT -1], randomColor);

	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->comboBox1->Items->Remove("Class " + (CLASS_COUNT));

	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			
		//Ana eksen dogruları cizdir.
		Pen^ pen = gcnew Pen(Color::Black, 1.0f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);

	}	

	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {


		Pen^ pen = gcnew Pen((Color)ClassColorTable[comboBox1->SelectedItem], 2.0f);
		
		int temp_x, temp_y;
		float x1, x2;
		temp_x = (System::Convert::ToInt32(e->X));
		temp_y = (System::Convert::ToInt32(e->Y));
		x1 = (float)(temp_x - (pictureBox1->Width / 2));
		x2 = (float)((pictureBox1->Height / 2) - temp_y);

		if (Size == 0)
		{
			p = new Samples[1];
			p[0].x1 = x1;
			p[0].x2 = x2;
			p[0].id = comboBox1->SelectedIndex;
			Size++;
		}
		else
		{
			Samples* temp; //data lar temp de tutuluyor.
			temp = p;
			Size++;
			p = new Samples[Size];

			for (int i = 0; i < Size-1; i++)
			{

				p[i].x1 = temp[i].x1;
				p[i].x2 = temp[i].x2;
				p[i].id = temp[i].id;

			}
			p[Size - 1].x1 = x1;
			p[Size - 1].x2 = x2;
			p[Size - 1].id = comboBox1->SelectedIndex;
			delete temp;

		}
		
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		label1->Text = "Size : " + Convert::ToString(Size);

	}
	
    private: System::Void randomToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Pen^ pen = gcnew Pen(Color::RoyalBlue, 2.0f);

		int min_x, min_y, max_x, max_y;
		
		w = new double*[CLASS_COUNT];
		for (int i = 0; i < CLASS_COUNT; i++)
		{
			w[i] = new double[INPUTSIZE];
		}
		srand(time(0));
		
		for (int i = 0; i < CLASS_COUNT; i++)	//w[nöron][input]  nöron : sınıf sayısı kadar olmalı 
		{
			label3->Text = Convert::ToString(w[i]);
			for (int j = 0; j < INPUTSIZE; j++)						//input : x1, x2, bias olacak.
			{
				w[i][j] = ((double)rand() / (RAND_MAX));
			}
		}
		//SHOW WEIGHT :D
		for (size_t i = 0; i < CLASS_COUNT; i++)
		{
			for (size_t j = 0; j < INPUTSIZE; j++)
			{
				richTextBox1->Text += " w[" + i + "][" + j + "] : " + Convert::ToString(w[i][j] ) + "\n";
			}
			richTextBox1->Text += "\n";
		}
		

		//RAND AYIRTACININ GÖSTERİMİ
		/*min_x = (this->pictureBox1->Width) / (-2);
		max_x = (this->pictureBox1->Width) / 2;
		for (size_t i = 0; i < comboBox1->Items->Count; i++)
		{
			min_y = YPoint(min_x, w[i]);
			max_y = YPoint(max_x, w[i]);
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, 
														 (pictureBox1->Height / 2) - min_y,
														 (pictureBox1->Width / 2) + max_x, 
														 (pictureBox1->Height / 2) - max_y);
		}
		*/
	}

	private: System::Void PerceptronLearningToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		//SINGLE-LAYER PERCEPTRON LEARNING

		// W = rand Mx3
		// y = [x bias]'	----> [ 3x1 ]
		// Net Mx1  = W[M][3] x y[3][1]
		//d1 = [1 -1 -1], d2 = [-1 1 -1] ....  yani d[p[i].id] = 1 olacak şekilde ayarlanmalı.
		// d - o kıyaslaması yapılır ve örtüşmeyen nörondaki ağırlık güncellenir.
		// Ağırlık güncelleme = Wk = 1/2 * c *(d-o)y'
		// cycle tamamlanınca E > 0 ? eğitime devam : eğitim sonlanır.
		
		Pen^ pen = gcnew Pen(Color::Black, 2.0f);
		Graphics^ GFX = pictureBox1->CreateGraphics();

		int min_x, min_y, max_x, max_y;
		min_x = (this->pictureBox1->Width) / (-2);
		max_x = (this->pictureBox1->Width) / 2;

		int* y = new int[INPUTSIZE]; // Input vektörü , Son eleman BIAS
		y[INPUTSIZE - 1] = -1;

		float* net = new float[CLASS_COUNT];
		int* d = new int[CLASS_COUNT];
		int *o = new int[CLASS_COUNT];
	    int*E = new int[CLASS_COUNT];
		int cycle = 0;

		int TotalError = 0;

		c = 0.5;

		while (true)
		{
			// 1. TotalError Sıfırlanacak:
			TotalError = 0;

			// Her bir sample gezilsin
			for (size_t idx = 0; idx < Size; idx++)
			{
				// d vektörünü -1 ile başlat; sonradan uygun yer +1 e eşitlenecek
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					d[i] = -1;
				}
				d[p[idx].id] = 1;

				// 2. Net Hesapla : önce y vektörü yüklenmeli [x y -1]
				y[0] = p[idx].x1;
				y[1] = p[idx].x2;

				//	Net = W*y
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					float sum = 0;
					for (size_t j = 0; j < INPUTSIZE; j++)
					{
						sum += w[i][j] * y[j];
					}
					net[i] = sum;
					o[i] = sgn(net[i]); //
					E[i] = d[i] - o[i];	//
					for (size_t j = 0; j < INPUTSIZE; j++)//		
					{
						w[i][j] += 0.5 * c * E[i] * y[j];
					}
	
				}

				/*// 3. o Hesapla : sgn()
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					o[i] = sgn(net[i]);
				}*/

				/*// 4. E Hesapla : d - o , önce d vektörünü düzenle ( Uygun Yere +1, gerisi -1)
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					E[i] = d[i] - o[i];
				}*/

				/*// 5. W Güncelle : 0.5 * c * (d-o) * y
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					for (size_t j = 0; j < INPUTSIZE; j++)
					{
						w[i][j] += 0.5 * c * E[i] * y[j];
					}
				}*/
				
				TotalError += Sum(E, CLASS_COUNT);
			}                                        

			// Toplam Hata;
			if (TotalError == 0)
			{
				break;
			}
			
			cycle++;	
			if (cycle % 1000 == 0)
			{
				UpDateFeatureSpace();
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					pen->Color = (Color)ClassColorTable[comboBox1->Items[i]];

					min_y = YPoint(min_x, w[i]);
					max_y = YPoint(max_x, w[i]);
					pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x,
						                                         (pictureBox1->Height / 2) - min_y,
						                                         (pictureBox1->Width / 2) + max_x,
						                                         (pictureBox1->Height / 2) - max_y);
				}
			}
			if (cycle > MAX_Cycle)
			{
				MessageBox::Show("max cycle sayısına ulasıldı.");
				break;
			}
				
		}
		UpDateFeatureSpace();

		for (size_t i = 0; i < CLASS_COUNT; i++)
		{
			pen->Color = (Color)ClassColorTable[comboBox1->Items[i]];
			
			min_y = YPoint(min_x, w[i]);
			max_y = YPoint(max_x, w[i]);
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x,
														 (pictureBox1->Height / 2) - min_y,
														 (pictureBox1->Width / 2) + max_x,
														 (pictureBox1->Height / 2) - max_y);
		}

		label2->Text = "cycle : " + Convert::ToString(cycle);
	}

	private: System::Void deltaLearningToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		//SINGLE-LAYER DELTA LEARNING

		// W[ k x 3 ]	k:nöron, 3:giriş--->x1,x2,bias
		//y = [x bias]'	----> [ 3x1 ]
		//net = w*y
		//o = f(net) = sgn()
		//f'(net) = 1/2 (1-o2)
		//Hata: E = -0.5 * ( di - oi ) * (1-o2) * y
		//güncel agırlık = c*( di - oi ) * (1-o2) *y


		Pen^ pen = gcnew Pen(Color::Black, 2.0f);
		Graphics^ GFX = pictureBox1->CreateGraphics();

		int min_x, min_y, max_x, max_y;
		min_x = (this->pictureBox1->Width) / (-2);
		max_x = (this->pictureBox1->Width) / 2;


		int* y = new int[INPUTSIZE];	// Input vektörü 
		y[INPUTSIZE - 1] = -1;			//Son eleman BIAS
		float* net = new float[CLASS_COUNT];

		int* d = new int[CLASS_COUNT];
		float* o = new float[CLASS_COUNT];
		float* E = new float[CLASS_COUNT];

		int cycle = 0;
		float TotalError = 0.0;

		c = 0.5;

		calcMeans();
		calcStds();

		while (true)
		{
			
			// 1. TotalError Sıfırlanacak:
			TotalError = 0.0;
			// Her bir sample gezilsin
			for (size_t idx = 0; idx < Size; idx++)
			{
				// d vektörünü -1 ile başlat; sonradan uygun yer +1 e eşitlenecek
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					d[i] = -1;
				}
				d[p[idx].id] = 1;

				// 2. Net Hesapla : önce y vektörü yüklenmeli (normalize edilerek). [x y -1]
				y[0] = (p[idx].x1 - m1) / s1;
				y[1] = (p[idx].x2 - m2) / s2;

				// Net = W*y
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					float sum = 0;
					for (size_t j = 0; j < INPUTSIZE; j++)
					{
						sum += w[i][j] * y[j];
					}
					net[i] = sum;
					o[i] = SigmoidFunc(net[i]);	//
					E[i] = d[i] - o[i];	//
					for (size_t j = 0; j < INPUTSIZE; j++)	//
					{
						w[i][j] += 0.5 * c * E[i] * (1 - o[i] * o[i]) * y[j];
					}
				}
				
				/*// 3. o Hesapla : SigmoidFunc() : f(net)
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					o[i] = SigmoidFunc(net[i]);
				}*/

				/*// 5. E Hesapla : d - o , önce d vektörünü düzenle ( Uygun Yere +1, gerisi -1)
				//-0.5 * ( di - oi )^2
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					E[i] = d[i] - o[i];	
				}*/

				/*// 6. W Güncelle : c*( di - oi ) * (1-oi^2) *y
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					for (size_t j = 0; j < INPUTSIZE; j++)
					{
						w[i][j] += 0.5 * c * E[i] * (1 - o[i] * o[i]) * y[j];
					}

				}*/
				TotalError += Sum(E, CLASS_COUNT);
				
			}
			// Toplam Hata;
			float Erms = Math::Sqrt(TotalError / (Size * CLASS_COUNT));
			if ( Erms <0.05) 
			{
				break;
			}
			cycle++;

			if (cycle%1000 == 0)
			{
				UpDateFeatureSpace();
				for (size_t i = 0; i < CLASS_COUNT; i++)
				{
					pen->Color = (Color)ClassColorTable[comboBox1->Items[i]];

					min_y = YPoint((min_x - m1) / s1, w[i]) * s2 + m2;
					max_y = YPoint((max_x - m1) / s1, w[i]) * s2 + m2;

					pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x,
																 (pictureBox1->Height / 2) - min_y,
																 (pictureBox1->Width / 2) + max_x,
																 (pictureBox1->Height / 2) - max_y);

				}
			}
			if (cycle > MAX_Cycle)
			{
				MessageBox::Show("max cycle sayısına ulasıldı.");
				break;
			}
			

		}
		UpDateFeatureSpace();
		label2->Text = "cycle : " + Convert::ToString(cycle);

		for (size_t i = 0; i < CLASS_COUNT; i++)
		{
			pen->Color = (Color)ClassColorTable[comboBox1->Items[i]];

			min_y = YPoint((min_x - m1) / s1, w[i]) * s2 + m2;
			max_y = YPoint((max_x - m1) / s1, w[i]) * s2 + m2;
	
			pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x,
				                                         (pictureBox1->Height / 2) - min_y,
				                                         (pictureBox1->Width / 2) + max_x,
				                                         (pictureBox1->Height / 2) - max_y);

		}

	}
	
	public: void UpDateFeatureSpace()
	{
		// Variables:
		Graphics^ GFX = pictureBox1->CreateGraphics();

		// 1 - Kanvası sıfırla sil
		GFX->Clear(pictureBox1->BackColor);

		// 2 - Eksenleri çiz
		Pen^ pen = gcnew Pen(Color::Black, 1.0f);
		int center_width, center_height;
		center_width = (int)(pictureBox1->Width / 2);
		center_height = (int)(pictureBox1->Height / 2);
		GFX->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);
		GFX->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);

		// 3 - Örnekleri çiz (p ile)
		       //SIKINTI BURADA GALİBA
		for (size_t i = 0; i < Size; i++)
		{
			pen->Color = (Color)ClassColorTable[comboBox1->Items[p[i].id]];
			GFX->DrawLine(pen, (pictureBox1->Width / 2) + p[i].x1 - 5, (pictureBox1->Height / 2) - p[i].x2,
							    (pictureBox1->Width / 2) + p[i].x1 + 5, (pictureBox1->Height / 2) - p[i].x2);

			GFX->DrawLine(pen, (pictureBox1->Width / 2) + p[i].x1, (pictureBox1->Height / 2) - p[i].x2 - 5,
							    (pictureBox1->Width / 2) + p[i].x1, (pictureBox1->Height / 2) - p[i].x2 + 5);
		}

		//pictureBox1->Refresh();

	}
	public: void calcMeans()
	{
		float total1, total2;

		for (size_t i = 0; i < Size; i++)
		{
			total1 += p[i].x1;
			total2 += p[i].x2;
		}

		this->m1 = total1 / Size;
		this->m2 = total2 / Size;

	}
	public: void calcStds()
	{
		// m1 , m2 biliniyor...
		/*
		Vi = Xi - m
		V : vektörel

		variance = V'V / N
		std = sqrt(variance)


		*/
		float sqSum1 = 0;
		float sqSum2 = 0;

		for (size_t i = 0; i < Size; i++)
		{
			sqSum1 += (p[i].x1 - m1) * (p[i].x1 - m1);
			sqSum2 += (p[i].x2 - m2) * (p[i].x2 - m2);
		}

		this->s1 = sqrtf(sqSum1) / Size;
		this->s2 = sqrtf(sqSum2) / Size;
	}
	
	
	
};
}
