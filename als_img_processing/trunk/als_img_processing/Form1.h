#pragma once



#include <vcclr.h>
#include <msclr/marshal.h>
#include "n_spe.h"


using namespace msclr::interop;

namespace als_img_processing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;

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
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label1;



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox2;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox3;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox5;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox6;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox7;
	private: System::Windows::Forms::Button^  button13;

	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox5 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox6 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox7 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->AutoSize = false;
			this->toolStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->toolStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripButton1, 
				this->toolStripLabel1, this->toolStripLabel2, this->toolStripButton2});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(695, 64);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(103, 61);
			this->toolStripButton1->Text = L"Load image list";
			this->toolStripButton1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(61, 61);
			this->toolStripLabel1->Text = L"0/0";
			// 
			// toolStripLabel2
			// 
			this->toolStripLabel2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->toolStripLabel2->Name = L"toolStripLabel2";
			this->toolStripLabel2->Size = System::Drawing::Size(33, 61);
			this->toolStripLabel2->Text = L"0";
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(89, 61);
			this->toolStripButton2->Text = L"AUTO";
			this->toolStripButton2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightBlue;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(609, 558);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(83, 79);
			this->button1->TabIndex = 1;
			this->button1->Text = L">";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightBlue;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Cambria", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(3, 558);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 79);
			this->button2->TabIndex = 2;
			this->button2->Text = L"<";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(91, 125);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(512, 512);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightBlue;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(614, 324);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(27, 29);
			this->button3->TabIndex = 4;
			this->button3->Text = L"+";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			this->button3->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button3_MouseWheel);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightBlue;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(614, 424);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(27, 29);
			this->button4->TabIndex = 5;
			this->button4->Text = L"-";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			this->button4->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button3_MouseWheel);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LightBlue;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button5->Location = System::Drawing::Point(247, 642);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(27, 29);
			this->button5->TabIndex = 7;
			this->button5->Text = L"-";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			this->button5->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button5_MouseWheel);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::LightBlue;
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button6->Location = System::Drawing::Point(436, 642);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(27, 29);
			this->button6->TabIndex = 6;
			this->button6->Text = L"+";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			this->button6->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::button5_MouseWheel);
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"A/B", L"A-B", L"A+B", L"A*B", L"(A-B)/(A+B)"});
			this->listBox1->Location = System::Drawing::Point(92, 85);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(168, 36);
			this->listBox1->TabIndex = 8;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(89, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Operation:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 709);
			this->label2->Name = L"label2";
			this->label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Right image";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 687);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Left image";
			// 
			// listBox2
			// 
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 16;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Mixed", L"Left", L"Right"});
			this->listBox2->Location = System::Drawing::Point(266, 85);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(168, 36);
			this->listBox2->TabIndex = 15;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox2_SelectedIndexChanged);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::LightBlue;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(528, 96);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 16;
			this->button7->Text = L"Save image";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::LightBlue;
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(528, 67);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 17;
			this->button8->Text = L"Save DAT";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(614, 359);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(72, 20);
			this->maskedTextBox1->TabIndex = 18;
			this->maskedTextBox1->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBox1_MaskInputRejected);
			this->maskedTextBox1->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox1_Validated);
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Location = System::Drawing::Point(615, 398);
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(72, 20);
			this->maskedTextBox2->TabIndex = 19;
			this->maskedTextBox2->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox2_Validated);
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->Location = System::Drawing::Point(280, 648);
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->Size = System::Drawing::Size(72, 20);
			this->maskedTextBox3->TabIndex = 20;
			this->maskedTextBox3->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox3_Validated);
			// 
			// maskedTextBox4
			// 
			this->maskedTextBox4->Location = System::Drawing::Point(358, 648);
			this->maskedTextBox4->Name = L"maskedTextBox4";
			this->maskedTextBox4->Size = System::Drawing::Size(72, 20);
			this->maskedTextBox4->TabIndex = 21;
			this->maskedTextBox4->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox4_Validated);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(612, 382);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Step";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(358, 671);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Step";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 204);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 13);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Step";
			// 
			// maskedTextBox5
			// 
			this->maskedTextBox5->Location = System::Drawing::Point(3, 281);
			this->maskedTextBox5->Name = L"maskedTextBox5";
			this->maskedTextBox5->Size = System::Drawing::Size(85, 20);
			this->maskedTextBox5->TabIndex = 27;
			this->maskedTextBox5->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox5_Validated);
			// 
			// maskedTextBox6
			// 
			this->maskedTextBox6->Location = System::Drawing::Point(3, 385);
			this->maskedTextBox6->Name = L"maskedTextBox6";
			this->maskedTextBox6->Size = System::Drawing::Size(85, 20);
			this->maskedTextBox6->TabIndex = 26;
			this->maskedTextBox6->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox6_Validated);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::LightBlue;
			this->button9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button9->Location = System::Drawing::Point(58, 307);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(27, 29);
			this->button9->TabIndex = 25;
			this->button9->Text = L"-";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::LightBlue;
			this->button10->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button10->Location = System::Drawing::Point(58, 246);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(27, 29);
			this->button10->TabIndex = 24;
			this->button10->Text = L"+";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::LightBlue;
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button11->Location = System::Drawing::Point(58, 350);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(27, 29);
			this->button11->TabIndex = 29;
			this->button11->Text = L"+";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::LightBlue;
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button12->Location = System::Drawing::Point(58, 411);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(27, 29);
			this->button12->TabIndex = 30;
			this->button12->Text = L"-";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// maskedTextBox7
			// 
			this->maskedTextBox7->Location = System::Drawing::Point(3, 220);
			this->maskedTextBox7->Name = L"maskedTextBox7";
			this->maskedTextBox7->Size = System::Drawing::Size(85, 20);
			this->maskedTextBox7->TabIndex = 31;
			this->maskedTextBox7->Validated += gcnew System::EventHandler(this, &Form1::maskedTextBox7_Validated);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::LightBlue;
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(447, 96);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(75, 23);
			this->button13->TabIndex = 32;
			this->button13->Text = L"Save SPE";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(469, 648);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(161, 17);
			this->checkBox1->TabIndex = 34;
			this->checkBox1->Text = L"Nearest neighbour upsample";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(263, 69);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(62, 13);
			this->label7->TabIndex = 35;
			this->label7->Text = L"View mode:";
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::LightBlue;
			this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(3, 125);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(84, 46);
			this->button14->TabIndex = 37;
			this->button14->Text = L"Load Left";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::LightBlue;
			this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DeepSkyBlue;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(609, 125);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(83, 46);
			this->button15->TabIndex = 38;
			this->button15->Text = L"Load right";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"BW", L"COLOR"});
			this->listBox3->Location = System::Drawing::Point(609, 208);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(83, 69);
			this->listBox3->TabIndex = 39;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox3_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(609, 189);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(34, 13);
			this->label9->TabIndex = 40;
			this->label9->Text = L"Scale";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 265);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(46, 13);
			this->label10->TabIndex = 41;
			this->label10->Text = L"DR Max";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 369);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(43, 13);
			this->label11->TabIndex = 42;
			this->label11->Text = L"DR Min";
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::DarkSalmon;
			this->button16->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button16->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button16->Location = System::Drawing::Point(609, 67);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(83, 54);
			this->button16->TabIndex = 43;
			this->button16->Text = L"REPORT BUG";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::Tomato;
			this->button17->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Red;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button17->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button17->Location = System::Drawing::Point(649, 12);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(34, 41);
			this->button17->TabIndex = 44;
			this->button17->Text = L"X";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(695, 722);
			this->ControlBox = false;
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->maskedTextBox7);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->maskedTextBox5);
			this->Controls->Add(this->maskedTextBox6);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->maskedTextBox4);
			this->Controls->Add(this->maskedTextBox3);
			this->Controls->Add(this->maskedTextBox2);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->toolStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Image Aligment Tool (c) 2011-2012 Mykola Dvornik";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: static array<String^>^ bpe_cont;
	private: static long bpe_pairs = 0;
	private: static long bpe_current = 0;
	private: static bool is_bpe_list_loaded = false;

	private: static String^ nleft="";
	private: static String^ nright="";

	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog^ open = gcnew OpenFileDialog();
				 open->Title = L"Open SPE images batch file";
				 open->Filter = "Batch file of pairs of images (*.bpe)|*.bpe|All files (*.*)|*.*";
				 open->Multiselect = false;
				 if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {

					 //pin_ptr<const wchar_t> wch = PtrToStringChars(open->FileName);
					 //size_t convertedChars = 0;
					 //size_t  sizeInBytes = ((open->FileName->Length + 1) * 2);
					 //errno_t err = 0;
					 //bpe_filename = (char *)malloc(sizeInBytes);

					 //err = wcstombs_s(&convertedChars, 
						//			bpe_filename, sizeInBytes,
						//			wch, sizeInBytes);


					 StreamReader^ sr = gcnew StreamReader(open->FileName);
					 // Get number of lines
					 long lines = 0;
					 while ( sr->Peek() >= 0)
					 {
						sr->ReadLine();
						lines++;
					 }
					 delete sr;

					 StreamReader^ sr1 = gcnew StreamReader(open->FileName);
					 bpe_pairs = lines;
					 bpe_cont = gcnew array<String^>(lines); 
					 long index = 0;
					 while ( sr1->Peek() >= 0)
					 {
						bpe_cont[index] = sr1->ReadLine();		
						index++;
					 }
					  delete sr;
					  toolStripLabel1->Text = Convert::ToString(bpe_current + 1) + "/" + Convert::ToString(bpe_pairs);
					  is_bpe_list_loaded = true;
				 }
				 ProcessPair();
			 }
	private: static Bitmap^ mimage;
	private: System::Void ProcessPair()
			 {
				 if (!is_bpe_list_loaded) return;
				// Get the file names
				 array<wchar_t>^ del = gcnew array<wchar_t>{L' ',L','};
				 array<String^>^ bpe_pair = bpe_cont[bpe_current]->Split(del);
				 String^ left_name = bpe_pair[0];
				 String^ right_name = bpe_pair[1];

				 nleft = String::Copy(left_name);
				 nright = String::Copy(right_name);

				 array<wchar_t>^ deln = gcnew array<wchar_t>{L'\\\\'};

				 array<String^>^ left_redu = left_name->Split(deln);
				 array<String^>^ right_redu = right_name->Split(deln);

				 label3->Text = left_redu[(left_redu->GetLength(0))-1];
				 label2->Text = right_redu[(right_redu->GetLength(0))-1];


				 // Get native representation
				 //Left
				//pin_ptr<const wchar_t> wch = PtrToStringChars(left_name);
				//size_t convertedChars = 0;
				//size_t  sizeInBytes = ((left_name->Length + 1) * 2);
				//errno_t err = 0;
				////bpe_filename_left = (char *)malloc(sizeInBytes);
				//err = wcstombs_s(&convertedChars, 
				//		(char*)bpe_filename_left, sizeInBytes,
				//		wch, sizeInBytes);
				////Rigth
				//wch = PtrToStringChars(right_name);
				//convertedChars = 0;
				//sizeInBytes = ((right_name->Length + 1) * 2);
				//err = 0;
				////bpe_filename_right = (char *)malloc(sizeInBytes);
				//err = wcstombs_s(&convertedChars, 
				//		(char*)bpe_filename_right, sizeInBytes,
				//		wch, sizeInBytes);

				 //Left
				 marshal_context ^ context = gcnew marshal_context();
				 cspe::bpe_filename_left = context->marshal_as<const char*>(left_name);
				 cspe::bpe_filename_right = context->marshal_as<const char*>(right_name);
				 
				 // Get mode 1-Left, 2-Rigth, 0 - Mixed
				 cspe::mode = listBox2->SelectedIndex;
				 // Get operation to be performed on image
				 cspe::op = listBox1->SelectedIndex;

				 cspe::process(cspe::bpe_filename_left, cspe::bpe_filename_right);
				 delete mimage;
				 mimage = gcnew Bitmap(cspe::sizex_ups, cspe::sizey_ups, System::Drawing::Imaging::PixelFormat::Format24bppRgb);

				//plot xy

				 System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,mimage->Width,mimage->Height);	
				 System::Drawing::Imaging::BitmapData^ bmpData = mimage->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mimage->PixelFormat );
				 IntPtr ptr = bmpData->Scan0;
				 int bytes = bmpData->Stride * mimage->Height;
				 cspe::map_to_bitmap((unsigned char*)ptr.ToPointer(), bmpData->Stride);
				 mimage->UnlockBits(bmpData);
				 delete context;
				 pictureBox1->Image = mimage;

			 }
	private: System::Void ProcessPairSolo()
	{
		if (nleft->Length == 0 || nright->Length == 0) return;
		// Get the file names
				 
		String^ left_name = String::Copy(nleft);
		String^ right_name = String::Copy(nright);

		array<wchar_t>^ deln = gcnew array<wchar_t>{L'\\\\'};

		array<String^>^ left_redu = left_name->Split(deln);
		array<String^>^ right_redu = right_name->Split(deln);

		label3->Text = left_redu[(left_redu->GetLength(0))-1];
		label2->Text = right_redu[(right_redu->GetLength(0))-1];


		// Get native representation
		//Left
	//pin_ptr<const wchar_t> wch = PtrToStringChars(left_name);
	//size_t convertedChars = 0;
	//size_t  sizeInBytes = ((left_name->Length + 1) * 2);
	//errno_t err = 0;
	////bpe_filename_left = (char *)malloc(sizeInBytes);
	//err = wcstombs_s(&convertedChars, 
	//		(char*)bpe_filename_left, sizeInBytes,
	//		wch, sizeInBytes);
	////Rigth
	//wch = PtrToStringChars(right_name);
	//convertedChars = 0;
	//sizeInBytes = ((right_name->Length + 1) * 2);
	//err = 0;
	////bpe_filename_right = (char *)malloc(sizeInBytes);
	//err = wcstombs_s(&convertedChars, 
	//		(char*)bpe_filename_right, sizeInBytes,
	//		wch, sizeInBytes);

		//Left
		marshal_context ^ context = gcnew marshal_context();
		cspe::bpe_filename_left = context->marshal_as<const char*>(left_name);
		cspe::bpe_filename_right = context->marshal_as<const char*>(right_name);
				 
		// Get mode 1-Left, 2-Rigth, 0 - Mixed
		cspe::mode = listBox2->SelectedIndex;
		// Get operation to be performed on image
		cspe::op = listBox1->SelectedIndex;

		cspe::process(cspe::bpe_filename_left, cspe::bpe_filename_right);
		delete mimage;
		mimage = gcnew Bitmap(cspe::sizex_ups, cspe::sizey_ups, System::Drawing::Imaging::PixelFormat::Format24bppRgb);

	//plot xy

		System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,mimage->Width,mimage->Height);	
		System::Drawing::Imaging::BitmapData^ bmpData = mimage->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mimage->PixelFormat );
		IntPtr ptr = bmpData->Scan0;
		int bytes = bmpData->Stride * mimage->Height;
		cspe::map_to_bitmap((unsigned char*)ptr.ToPointer(), bmpData->Stride);
		mimage->UnlockBits(bmpData);
		delete context;
		pictureBox1->Image = mimage;

	}
	private: System::Void OverlapPair()
			 {
				 if (!is_bpe_list_loaded && nleft->Length == 0 && nright->Length == 0) return;
				 // Get mode 1-Left, 2-Rigth, 0 - Mixed
				 cspe::mode = listBox2->SelectedIndex;
				 // Get operation to be performed on image
				 cspe::op = listBox1->SelectedIndex;

				 cspe::overlap(); 
				 //get entropy
				 //cspe::getEntropy();
				 //System::Double dS = Convert::ToDouble(cspe::S);
				 //toolStripLabel2->Text = dS::ToString("%.3f");
				//plot xy
				 System::Drawing::Rectangle rect = System::Drawing::Rectangle(0,0,mimage->Width,mimage->Height);	
				 System::Drawing::Imaging::BitmapData^ bmpData = mimage->LockBits( rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, mimage->PixelFormat );
				 IntPtr ptr = bmpData->Scan0;
				 int bytes = bmpData->Stride * mimage->Height;
				 cspe::map_to_bitmap((unsigned char*)ptr.ToPointer(), bmpData->Stride);
				 mimage->UnlockBits(bmpData);
				 pictureBox1->Image = mimage;
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 listBox1->SelectedIndex = 0;
			 listBox2->SelectedIndex = 0;
			 maskedTextBox2->Text = Convert::ToString(cspe::step_y);
			 maskedTextBox4->Text = Convert::ToString(cspe::step_x);

			 maskedTextBox1->Text = Convert::ToString(cspe::offset_y);
			 maskedTextBox3->Text = Convert::ToString(cspe::offset_x);
			 maskedTextBox7->Text = Convert::ToString(cspe::dr_step);
			 maskedTextBox7->Text = Convert::ToString(cspe::dr_step);
			 maskedTextBox6->Text = Convert::ToString(cspe::dr_low);
			 maskedTextBox5->Text = Convert::ToString(cspe::dr_high);
			 listBox3->SelectedIndex = cspe::scale - 1;
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 cspe::offset_y += cspe::step_y;
			 maskedTextBox1->Text = Convert::ToString(cspe::offset_y);
			 OverlapPair();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 cspe::offset_y -= cspe::step_y;
			 maskedTextBox1->Text = Convert::ToString(cspe::offset_y);
			 OverlapPair();
		 }
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 cspe::offset_x += cspe::step_x;
			 maskedTextBox3->Text = Convert::ToString(cspe::offset_x);
			 OverlapPair();
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 cspe::offset_x -= cspe::step_x;
			 maskedTextBox3->Text = Convert::ToString(cspe::offset_x);
			 OverlapPair();
		 }
private: System::Void maskedTextBox2_Validated(System::Object^  sender, System::EventArgs^  e) {
			 cspe::step_y = Convert::ToInt32(maskedTextBox2->Text);
		 }
private: System::Void maskedTextBox4_Validated(System::Object^  sender, System::EventArgs^  e) {
			 cspe::step_x = Convert::ToInt32(maskedTextBox4->Text);
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (bpe_current < bpe_pairs - 1) bpe_current++;
			 toolStripLabel1->Text = Convert::ToString(bpe_current + 1) + "/" + Convert::ToString(bpe_pairs);
			 ProcessPair();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (bpe_current > 0) bpe_current--;
			 toolStripLabel1->Text = Convert::ToString(bpe_current + 1) + "/" + Convert::ToString(bpe_pairs);
			 ProcessPair();
		 }
private: System::Void listBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 OverlapPair();
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 cspe::dr_high += cspe::dr_step;
			 maskedTextBox5->Text = Convert::ToString(cspe::dr_high);
			 switch (listBox1->SelectedIndex)
			 {
			 case 0:
				 cspe::dr_high_AdB = cspe::dr_high;
				 break;
			 case 4:
				 cspe::dr_high_AmBdApB = cspe::dr_high;
				 break;
			 }
			 OverlapPair();
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (cspe::dr_high == 0.0f) return;
			 cspe::dr_high -= cspe::dr_step;
			 maskedTextBox5->Text = Convert::ToString(cspe::dr_high);
			 switch (listBox1->SelectedIndex)
			 {
			 case 0:
				 cspe::dr_high_AdB = cspe::dr_high;
				 break;
			 case 4:
				 cspe::dr_high_AmBdApB = cspe::dr_high;
				 break;
			 }
			 OverlapPair();
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 cspe::dr_low += cspe::dr_step;
			 maskedTextBox6->Text = Convert::ToString(cspe::dr_low);
			 switch (listBox1->SelectedIndex)
			 {
			 case 0:
			     cspe::dr_low_AdB = cspe::dr_low;
				 break;
			 case 4:
				 cspe::dr_low_AmBdApB = cspe::dr_low;
				 break;
			 }
			 OverlapPair();
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (cspe::dr_low == 0.0f) return;
			 cspe::dr_low -= cspe::dr_step;
			 maskedTextBox6->Text = Convert::ToString(cspe::dr_low);
			 switch (listBox1->SelectedIndex)
			 {
			 case 0:
			     cspe::dr_low_AdB = cspe::dr_low;
				 break;
			 case 4:
				 cspe::dr_low_AmBdApB = cspe::dr_low;
				 break;
			 }
			 OverlapPair();
		 }
private: System::Void maskedTextBox1_Validated(System::Object^  sender, System::EventArgs^  e) {
			 cspe::offset_y = Convert::ToInt32(maskedTextBox1->Text);
			 OverlapPair();
		 }
private: System::Void maskedTextBox3_Validated(System::Object^  sender, System::EventArgs^  e) {
			 cspe::offset_x = Convert::ToInt32(maskedTextBox3->Text);
			 OverlapPair();
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ si = gcnew SaveFileDialog();
			 si->Title = "Save processed TIFF image...";
			 si->Filter = "TIFF (*.tif)|*.tif";
			 si->FileName = "-ox"+Convert::ToString(cspe::offset_x) + "-oy" +Convert::ToString(cspe::offset_y);
			 if (si->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 mimage->Save(si->FileName,System::Drawing::Imaging::ImageFormat::Tiff);
			 }
		 }
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 try
			 {
				Process::Start("mailto:mad211@ex.ac.uk");
			 }
			 catch (Win32Exception^ e)
			 {
				 MessageBox::Show(e->Message);
			 }
		 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ si = gcnew SaveFileDialog();
			 si->Title = "Save processed SPE image...";
			 si->Filter = "SPE (*.spe)|*.spe";
			 si->FileName = "-ox"+Convert::ToString(cspe::offset_x) + "-oy" +Convert::ToString(cspe::offset_y);
			 if (si->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 marshal_context ^ context = gcnew marshal_context();
				 const char* nfn = context->marshal_as<const char*>(si->FileName);
				 cspe::spe_save(nfn);
				 delete context;
			 }
		 }
private: System::Void SetUpsMode()
		 {
			 if (checkBox1->Checked)
			 {
				cspe::ups = 1;
				cspe::offset_x *= 2;
				cspe::offset_y *= 2;
			 }
			 else 
			 {
				cspe::ups = 0;
				cspe::offset_x /= 2;
				cspe::offset_y /= 2;
			 }
			 UpdateForm();

		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 SetUpsMode();
			 ProcessPair();
		 }
private: System::Void UpdateForm()
		 {
			 maskedTextBox1->Text = Convert::ToString(cspe::offset_y);
			 maskedTextBox3->Text = Convert::ToString(cspe::offset_x);
		 }
private: System::Void button3_MouseWheel(Object^ /*sender*/, System::Windows::Forms::MouseEventArgs^ e )
		 {
			 int numberOfPixelsToMove = e->Delta * SystemInformation::MouseWheelScrollLines / 360;
			 cspe::offset_y += numberOfPixelsToMove;
			 UpdateForm();
			 OverlapPair();
		 }
private: System::Void button5_MouseWheel(Object^ /*sender*/, System::Windows::Forms::MouseEventArgs^ e )
		 {
			 int numberOfPixelsToMove = e->Delta * SystemInformation::MouseWheelScrollLines / 360;
			 cspe::offset_x += numberOfPixelsToMove;
			 UpdateForm();
			 OverlapPair();
		 }

private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
			OpenFileDialog^ open = gcnew OpenFileDialog();
			open->Title = L"Please choose left image...";
			open->Filter = "Batch file of pairs of images (*.SPE)|*.spe|All files (*.*)|*.*";
			open->Multiselect = false;
			if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				nleft = String::Copy(open->FileName);
				label3->Text = nleft;
				if (nright->Length) ProcessPairSolo();
			}
		 }
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
			OpenFileDialog^ open = gcnew OpenFileDialog();
			open->Title = L"Please choose left image...";
			open->Filter = "RAW image (*.SPE)|*.spe|All files (*.*)|*.*";
			open->Multiselect = false;
			if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				nright = String::Copy(open->FileName);
				label2->Text = nright;
				if (nleft->Length) ProcessPairSolo();
			}
		 }
private: System::Void maskedTextBox7_Validated(System::Object^  sender, System::EventArgs^  e) {
			 cspe::dr_step = Convert::ToSingle(maskedTextBox7->Text);
		 }
private: System::Void listBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 cspe::scale = Convert::ToInt32(listBox3->SelectedIndex) + 1;
			 OverlapPair();
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 switch (listBox1->SelectedIndex)
			{
			case 0:
				cspe::dr_high = cspe::dr_high_AdB;
				cspe::dr_low = cspe::dr_low_AdB;	
				break;
			case 4:
				cspe::dr_high = cspe::dr_high_AmBdApB;
				cspe::dr_low = cspe::dr_low_AmBdApB;
				break;
			}
			 maskedTextBox5->Text = Convert::ToString(cspe::dr_high);
			maskedTextBox6->Text = Convert::ToString(cspe::dr_low);
			 OverlapPair();
		 }
private: System::Void maskedTextBox5_Validated(System::Object^  sender, System::EventArgs^  e) {
			cspe::dr_high = Convert::ToSingle(maskedTextBox5->Text);
			OverlapPair();
			switch (listBox1->SelectedIndex)
			{
			case 0:
				cspe::dr_high_AdB = cspe::dr_high;
				break;
			case 4:
				cspe::dr_high_AmBdApB = cspe::dr_high;
				break;
			}
		 }
private: System::Void maskedTextBox6_Validated(System::Object^  sender, System::EventArgs^  e) {
			cspe::dr_low = Convert::ToSingle(maskedTextBox6->Text);
			switch (listBox1->SelectedIndex)
			{
			case 0:
				cspe::dr_low_AdB = cspe::dr_low;
				break;
			case 4:
				cspe::dr_low_AmBdApB = cspe::dr_low;
				break;
			}
			OverlapPair();
		 }
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 //OverlapPair();
			 //cspe::getCC();
			 cspe::doAutoOverlapCCA();
			 maskedTextBox1->Text = Convert::ToString(cspe::offset_y);
			 maskedTextBox3->Text = Convert::ToString(cspe::offset_x);
			 OverlapPair();
		 }
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::Windows::Forms::Application::Exit();

		 }
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
			 try
			 {
				Process::Start("mailto:mykola.dvornik@gmail.com");
			 }
			 catch (Win32Exception^ e)
			 {
				 MessageBox::Show(e->Message);
			 }
		 }
};
}

