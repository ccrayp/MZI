#pragma once
#include "Analisys.h"
#include <msclr\marshal_cppstd.h>

std::unordered_map<int, int> R, G, B;

namespace FreaquencyAnalisys {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			openFileDialog1->Filter = "��������� ���� (*.txt)|*.txt|����������� (*.bmp)|*.bmp|�������� ���� (*.bin)|*.bin";
			this->chart1->Series["Series1"]->Points->AddXY(0, 0);
			this->chart1->ChartAreas[0]->AxisX->ScaleView->Zoomable = true;
			this->chart1->ChartAreas[0]->AxisY->ScaleView->Zoomable = true;
			this->trackBar1->Value = 5;
			this->trackBar2->Value = 10;

			this->chart1->Series->Add("R");
			this->chart1->Series["R"]->Color = System::Drawing::Color::Red;

			this->chart1->Series->Add("G");
			this->chart1->Series["G"]->Color = System::Drawing::Color::Green;

			this->chart1->Series->Add("B");
			this->chart1->Series["B"]->Color = System::Drawing::Color::Blue;

			this->�������������R�����ToolStripMenuItem->Visible = false;
			this->������������G�����ToolStripMenuItem->Visible = false;
			this->�����������B�����ToolStripMenuItem->Visible = false;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: int max = 0;

	private: System::Windows::Forms::ToolStripMenuItem^ �������������R�����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������G�����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������B�����ToolStripMenuItem;

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������R�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������G�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������B�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea3->AlignmentOrientation = System::Windows::Forms::DataVisualization::Charting::AreaAlignmentOrientations::None;
			chartArea3->AxisX->Maximum = 255;
			chartArea3->AxisY->IsLabelAutoFit = false;
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			legend3->AutoFitMinFontSize = 14;
			legend3->Enabled = false;
			legend3->Name = L"Legend1";
			this->chart1->Legends->Add(legend3);
			this->chart1->Location = System::Drawing::Point(412, 27);
			this->chart1->Name = L"chart1";
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"Legend1";
			series3->LegendText = L"���������� �������� � ������";
			series3->Name = L"Series1";
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(852, 652);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����ToolStripMenuItem,
					this->���������������������ToolStripMenuItem, this->�����������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(1264, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->����ToolStripMenuItem->Text = L"������� ����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����ToolStripMenuItem_Click);
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->��������������ToolStripMenuItem,
					this->�������������R�����ToolStripMenuItem, this->������������G�����ToolStripMenuItem, this->�����������B�����ToolStripMenuItem
			});
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->���������������������ToolStripMenuItem->Text = L"��������� �����������";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->��������������ToolStripMenuItem->Text = L"��������� �����";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������������ToolStripMenuItem_Click);
			// 
			// �������������R�����ToolStripMenuItem
			// 
			this->�������������R�����ToolStripMenuItem->Name = L"�������������R�����ToolStripMenuItem";
			this->�������������R�����ToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->�������������R�����ToolStripMenuItem->Text = L"������ ������� (R) �����";
			this->�������������R�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������������R�����ToolStripMenuItem_Click);
			// 
			// ������������G�����ToolStripMenuItem
			// 
			this->������������G�����ToolStripMenuItem->Name = L"������������G�����ToolStripMenuItem";
			this->������������G�����ToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->������������G�����ToolStripMenuItem->Text = L"������ ������ (G) �����";
			this->������������G�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������������G�����ToolStripMenuItem_Click);
			// 
			// �����������B�����ToolStripMenuItem
			// 
			this->�����������B�����ToolStripMenuItem->Name = L"�����������B�����ToolStripMenuItem";
			this->�����������B�����ToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->�����������B�����ToolStripMenuItem->Text = L"������ ����� (B) �����";
			this->�����������B�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����������B�����ToolStripMenuItem_Click);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->�����������������ToolStripMenuItem->Text = L"������� ����������";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����������������ToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"��� �� ��� X (����� �������)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(193, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"��� �� ��� Y (���������� ��������)";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(16, 44);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(390, 45);
			this->trackBar1->TabIndex = 4;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(16, 107);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(390, 45);
			this->trackBar2->TabIndex = 5;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(16, 177);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(390, 492);
			this->textBox1->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(22, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(22, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(380, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(25, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"100";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(385, 76);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"20";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 161);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(215, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"���������� ��������� ������� �������";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1920, 1080);
			this->MinimumSize = System::Drawing::Size(1276, 662);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��������� ����������";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->chart1->Series["Series1"]->Points->Clear();

			if (openFileDialog1->FileName->Contains(".txt"))
				text();
			else if (openFileDialog1->FileName->Contains(".bin")) {
				binary();
			}
			else if (openFileDialog1->FileName->Contains(".bmp"))
			{
				this->chart1->Series["R"]->Points->Clear();
				this->chart1->Series["G"]->Points->Clear();
				this->chart1->Series["B"]->Points->Clear();
				image();
				this->�������������R�����ToolStripMenuItem->Text = "������ ������� (R) �����";
				this->������������G�����ToolStripMenuItem->Text = "������ ������ (G) �����";
				this->�����������B�����ToolStripMenuItem->Text = "������ ����� (B) �����";
			}
		}
	}

	private: void text()
	{
		this->�������������R�����ToolStripMenuItem->Visible = false;
		this->������������G�����ToolStripMenuItem->Visible = false;
		this->�����������B�����ToolStripMenuItem->Visible = false;

		std::unordered_map<char, int> data;
		String^ path = System::Convert::ToString(openFileDialog1->FileName);
		text_to_diagram(msclr::interop::marshal_as<std::string>(path), data);
		int max_value = find_max(data);
		max = max_value;

		this->chart1->ChartAreas["ChartArea1"]->AxisY->Maximum = max_value + (max_value * 0.1);
		this->chart1->ChartAreas["ChartArea1"]->AxisX->Maximum = 255;

		this->trackBar1->Value = 5;
		this->trackBar2->Value = 10;

		this->chart1->ChartAreas["ChartArea1"]->AxisY->Interval = this->trackBar2->Value * (max / 100);
		this->chart1->ChartAreas["ChartArea1"]->AxisX->Interval = this->trackBar1->Value;

		this->trackBar2->Maximum = 20;
		this->trackBar2->Minimum = 1;
		this->trackBar1->Maximum = 20;
		this->trackBar1->Minimum = 1;

		this->label4->Text = Convert::ToString(max / 20);
		this->label5->Text = Convert::ToString(Convert::ToInt32(this->label4->Text) * 20);

		for (int i = 255; i > 0; i--)
		{
			if (data[(char)i] > -1)
				this->chart1->Series["Series1"]->Points->AddXY(i, data[(char)i]);
		}

		this->textBox1->Text = gcnew String(output_acsii(data).c_str()) + "\r\n�������� �����: " + Convert::ToString(entropy(data));
	}

	private: void binary() {
		this->�������������R�����ToolStripMenuItem->Visible = false;
		this->������������G�����ToolStripMenuItem->Visible = false;
		this->�����������B�����ToolStripMenuItem->Visible = false;

		std::unordered_map<uint8_t, int> data;
		String^ path = System::Convert::ToString(openFileDialog1->FileName);
		int count = 0;
		binary_to_diagram(msclr::interop::marshal_as<std::string>(path), data, count);
		int max_value = find_max(data);
		max = max_value;

		this->chart1->ChartAreas["ChartArea1"]->AxisY->Maximum = max_value + (max_value * 0.1);
		this->chart1->ChartAreas["ChartArea1"]->AxisX->Maximum = 255;

		this->trackBar1->Value = 5;
		this->trackBar2->Value = 10;

		this->chart1->ChartAreas["ChartArea1"]->AxisY->Interval = this->trackBar2->Value * (max / 100);
		this->chart1->ChartAreas["ChartArea1"]->AxisX->Interval = this->trackBar1->Value;

		this->trackBar2->Maximum = 20;
		this->trackBar2->Minimum = 1;
		this->trackBar1->Maximum = 20;
		this->trackBar1->Minimum = 1;

		this->label4->Text = Convert::ToString(max / 20);
		this->label5->Text = Convert::ToString(Convert::ToInt32(this->label4->Text) * 20);

		String^ result = "����� 8-������ ����� � �����: " + Convert::ToString(count) + "\r\n\r\n";
		for (int i = 255; i > 0; i--)
		{
			if (data[i] > -1)
				this->chart1->Series["Series1"]->Points->AddXY(i, data[i]);
		}

		for (int i = 0; i < 256; i++) {
			result += i + ". " + data[i] + "\r\n";
		}

		this->textBox1->Text = result + "\r\n�������� �����: " + Convert::ToString(entropy(data));
	}

	private: void image()
	{
		this->�������������R�����ToolStripMenuItem->Visible = true;
		this->������������G�����ToolStripMenuItem->Visible = true;
		this->�����������B�����ToolStripMenuItem->Visible = true;

		String^ path = System::Convert::ToString(openFileDialog1->FileName);
		ReadBMP(msclr::interop::marshal_as<std::string>(path), R, G, B);

		int max_value = find_max(R);
		if (find_max(G) > max_value)
			max_value = find_max(G);
		if (find_max(B) > max_value)
			max_value = find_max(B);
		max = max_value;

		this->chart1->ChartAreas["ChartArea1"]->AxisY->Maximum = max_value + (max_value * 0.1);
		this->chart1->ChartAreas["ChartArea1"]->AxisX->Maximum = 255;

		this->trackBar1->Value = 5;
		this->trackBar2->Value = 10;

		this->label4->Text = Convert::ToString(max / 20);
		this->label5->Text = Convert::ToString(Convert::ToInt32(this->label4->Text) * 20);

		this->chart1->ChartAreas["ChartArea1"]->AxisY->Interval = this->trackBar2->Value * (max / 20);
		this->chart1->ChartAreas["ChartArea1"]->AxisX->Interval = this->trackBar1->Value;

		this->trackBar2->Maximum = 20;
		this->trackBar2->Minimum = 1;
		this->trackBar1->Maximum = 20;
		this->trackBar1->Minimum = 1;

		std::unordered_map<int, int> data = init_map_RGB();

		for (int i = 255; i > 0; i--)
		{
			int temp = 0;
			if (R[i] > -1)
			{
				this->chart1->Series["R"]->Points->AddXY(i, R[i]);
				temp += R[i];
			}
			if (G[i] > -1)
			{
				this->chart1->Series["G"]->Points->AddXY(i, G[i]);
				temp += G[i];
			}
			if (B[i] > -1)
			{
				this->chart1->Series["B"]->Points->AddXY(i, B[i]);
				temp += B[i];
			}

			data[i] = temp;
		}

		String^ result = "";

		for (int i = 0; i < 256; i++)
		{
			result += i + ". " + data[i] + "\r\n";
		}

		this->textBox1->Text = result + "\r\n�������� �����: " + Convert::ToString(entropy(data));
	}

	private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		this->chart1->ChartAreas["ChartArea1"]->AxisY->Interval = this->trackBar2->Value * (max / 20);
	}

	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		this->chart1->ChartAreas["ChartArea1"]->AxisX->Interval = this->trackBar1->Value;
	}

	private: System::Void �����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (MessageBox::Show("�� �������, ��� ������ ������� ����������?", "������� ����������", MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
			this->Close();
	}

	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled == false)
		{
			this->��������������ToolStripMenuItem->Text = "��������� �����";
			this->chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = true;
			this->chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = true;
		}
		else
		{
			this->��������������ToolStripMenuItem->Text = "�������� �����";
			this->chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
			this->chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
		}
	}

	private: System::Void �����������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->chart1->Series["Series1"]->Points->Clear();
		this->textBox1->Text = "";
		this->chart1->Series["R"]->Points->Clear();
		this->chart1->Series["G"]->Points->Clear();
		this->chart1->Series["B"]->Points->Clear();
		this->chart1->Series["Series1"]->Points->AddXY(0, 0);
	}

	private: System::Void �������������R�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->�������������R�����ToolStripMenuItem->Text == "������ ������� (R) �����")
		{
			this->�������������R�����ToolStripMenuItem->Text = "�������� ������� (R) �����";
			this->chart1->Series["R"]->Points->Clear();
			this->chart1->Series["Series1"]->Points->AddXY(0, 0);
		}
		else
		{
			this->�������������R�����ToolStripMenuItem->Text = "������ ������� (R) �����";
			for (int i = 255; i > 0; i--)
			{
				this->chart1->Series["R"]->Points->AddXY(i, R[i]);
			}
		}
	}

	private: System::Void ������������G�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->������������G�����ToolStripMenuItem->Text == "������ ������ (G) �����")
		{
			this->������������G�����ToolStripMenuItem->Text = "�������� ������ (G) �����";
			this->chart1->Series["G"]->Points->Clear();
			this->chart1->Series["Series1"]->Points->AddXY(0, 0);
		}
		else
		{
			this->������������G�����ToolStripMenuItem->Text = "������ ������ (G) �����";
			for (int i = 255; i > 0; i--)
			{
				this->chart1->Series["G"]->Points->AddXY(i, G[i]);
			}
		}
	}

	private: System::Void �����������B�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->�����������B�����ToolStripMenuItem->Text == "������ ����� (B) �����")
		{
			this->�����������B�����ToolStripMenuItem->Text = "�������� ����� (B) �����";
			this->chart1->Series["B"]->Points->Clear();
			this->chart1->Series["Series1"]->Points->AddXY(0, 0);
		}
		else
		{
			this->�����������B�����ToolStripMenuItem->Text = "������ ����� (B) �����";
			for (int i = 255; i > 0; i--)
			{
				this->chart1->Series["B"]->Points->AddXY(i, B[i]);
			}
		}
	}
	};
}
