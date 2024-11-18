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
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			openFileDialog1->Filter = "Текстовый файл (*.txt)|*.txt|Изображение (*.bmp)|*.bmp|Бинарный файл (*.bin)|*.bin";
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

			this->скрытьКрасныйRКаналToolStripMenuItem->Visible = false;
			this->скрытьЗелёныйGКаналToolStripMenuItem->Visible = false;
			this->скрытьСинийBКаналToolStripMenuItem->Visible = false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;

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
	private: System::Windows::Forms::ToolStripMenuItem^ закрытьПриложениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ настройкаГистрограммыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выключитьСеткуToolStripMenuItem;
	private: int max = 0;

	private: System::Windows::Forms::ToolStripMenuItem^ скрытьКрасныйRКаналToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ скрытьЗелёныйGКаналToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ скрытьСинийBКаналToolStripMenuItem;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->настройкаГистрограммыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выключитьСеткуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->скрытьКрасныйRКаналToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->скрытьЗелёныйGКаналToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->скрытьСинийBКаналToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->закрытьПриложениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			series3->LegendText = L"Количесвто символов в тексте";
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
				this->файлToolStripMenuItem,
					this->настройкаГистрограммыToolStripMenuItem, this->закрытьПриложениеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(1264, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->файлToolStripMenuItem->Text = L"Выбрать файл";
			this->файлToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::файлToolStripMenuItem_Click);
			// 
			// настройкаГистрограммыToolStripMenuItem
			// 
			this->настройкаГистрограммыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->выключитьСеткуToolStripMenuItem,
					this->скрытьКрасныйRКаналToolStripMenuItem, this->скрытьЗелёныйGКаналToolStripMenuItem, this->скрытьСинийBКаналToolStripMenuItem
			});
			this->настройкаГистрограммыToolStripMenuItem->Name = L"настройкаГистрограммыToolStripMenuItem";
			this->настройкаГистрограммыToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->настройкаГистрограммыToolStripMenuItem->Text = L"Настройка гистограммы";
			// 
			// выключитьСеткуToolStripMenuItem
			// 
			this->выключитьСеткуToolStripMenuItem->Name = L"выключитьСеткуToolStripMenuItem";
			this->выключитьСеткуToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->выключитьСеткуToolStripMenuItem->Text = L"Отключить сетку";
			this->выключитьСеткуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выключитьСеткуToolStripMenuItem_Click);
			// 
			// скрытьКрасныйRКаналToolStripMenuItem
			// 
			this->скрытьКрасныйRКаналToolStripMenuItem->Name = L"скрытьКрасныйRКаналToolStripMenuItem";
			this->скрытьКрасныйRКаналToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->скрытьКрасныйRКаналToolStripMenuItem->Text = L"Скрыть красный (R) канал";
			this->скрытьКрасныйRКаналToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::скрытьКрасныйRКаналToolStripMenuItem_Click);
			// 
			// скрытьЗелёныйGКаналToolStripMenuItem
			// 
			this->скрытьЗелёныйGКаналToolStripMenuItem->Name = L"скрытьЗелёныйGКаналToolStripMenuItem";
			this->скрытьЗелёныйGКаналToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->скрытьЗелёныйGКаналToolStripMenuItem->Text = L"Скрыть зелёный (G) канал";
			this->скрытьЗелёныйGКаналToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::скрытьЗелёныйGКаналToolStripMenuItem_Click);
			// 
			// скрытьСинийBКаналToolStripMenuItem
			// 
			this->скрытьСинийBКаналToolStripMenuItem->Name = L"скрытьСинийBКаналToolStripMenuItem";
			this->скрытьСинийBКаналToolStripMenuItem->Size = System::Drawing::Size(219, 22);
			this->скрытьСинийBКаналToolStripMenuItem->Text = L"Скрыть синий (B) канал";
			this->скрытьСинийBКаналToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::скрытьСинийBКаналToolStripMenuItem_Click);
			// 
			// закрытьПриложениеToolStripMenuItem
			// 
			this->закрытьПриложениеToolStripMenuItem->Name = L"закрытьПриложениеToolStripMenuItem";
			this->закрытьПриложениеToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->закрытьПриложениеToolStripMenuItem->Text = L"Закрыть приложение";
			this->закрытьПриложениеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::закрытьПриложениеToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Шаг по оси X (номер символа)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(193, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Шаг по оси Y (количество символов)";
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
			this->label7->Text = L"Количество вхождений данного символа";
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
			this->Text = L"Частотный анализатор";
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

	private: System::Void файлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
				this->скрытьКрасныйRКаналToolStripMenuItem->Text = "Скрыть красный (R) канал";
				this->скрытьЗелёныйGКаналToolStripMenuItem->Text = "Скрыть зелёный (G) канал";
				this->скрытьСинийBКаналToolStripMenuItem->Text = "Скрыть синий (B) канал";
			}
		}
	}

	private: void text()
	{
		this->скрытьКрасныйRКаналToolStripMenuItem->Visible = false;
		this->скрытьЗелёныйGКаналToolStripMenuItem->Visible = false;
		this->скрытьСинийBКаналToolStripMenuItem->Visible = false;

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

		this->textBox1->Text = gcnew String(output_acsii(data).c_str()) + "\r\nЭнтропия файла: " + Convert::ToString(entropy(data));
	}

	private: void binary() {
		this->скрытьКрасныйRКаналToolStripMenuItem->Visible = false;
		this->скрытьЗелёныйGКаналToolStripMenuItem->Visible = false;
		this->скрытьСинийBКаналToolStripMenuItem->Visible = false;

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

		String^ result = "Всего 8-битных чисел в файле: " + Convert::ToString(count) + "\r\n\r\n";
		for (int i = 255; i > 0; i--)
		{
			if (data[i] > -1)
				this->chart1->Series["Series1"]->Points->AddXY(i, data[i]);
		}

		for (int i = 0; i < 256; i++) {
			result += i + ". " + data[i] + "\r\n";
		}

		this->textBox1->Text = result + "\r\nЭнтропия файла: " + Convert::ToString(entropy(data));
	}

	private: void image()
	{
		this->скрытьКрасныйRКаналToolStripMenuItem->Visible = true;
		this->скрытьЗелёныйGКаналToolStripMenuItem->Visible = true;
		this->скрытьСинийBКаналToolStripMenuItem->Visible = true;

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

		this->textBox1->Text = result + "\r\nЭнтропия файла: " + Convert::ToString(entropy(data));
	}

	private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		this->chart1->ChartAreas["ChartArea1"]->AxisY->Interval = this->trackBar2->Value * (max / 20);
	}

	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		this->chart1->ChartAreas["ChartArea1"]->AxisX->Interval = this->trackBar1->Value;
	}

	private: System::Void закрытьПриложениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (MessageBox::Show("Вы уверены, что хотите закрыть приложение?", "Закрыть приложение", MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK)
			this->Close();
	}

	private: System::Void выключитьСеткуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled == false)
		{
			this->выключитьСеткуToolStripMenuItem->Text = "Отключить сетку";
			this->chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = true;
			this->chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = true;
		}
		else
		{
			this->выключитьСеткуToolStripMenuItem->Text = "Включить сетку";
			this->chart1->ChartAreas["ChartArea1"]->AxisX->MajorGrid->Enabled = false;
			this->chart1->ChartAreas["ChartArea1"]->AxisY->MajorGrid->Enabled = false;
		}
	}

	private: System::Void очиститьКоординатнуюПлоскостьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->chart1->Series["Series1"]->Points->Clear();
		this->textBox1->Text = "";
		this->chart1->Series["R"]->Points->Clear();
		this->chart1->Series["G"]->Points->Clear();
		this->chart1->Series["B"]->Points->Clear();
		this->chart1->Series["Series1"]->Points->AddXY(0, 0);
	}

	private: System::Void скрытьКрасныйRКаналToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->скрытьКрасныйRКаналToolStripMenuItem->Text == "Скрыть красный (R) канал")
		{
			this->скрытьКрасныйRКаналToolStripMenuItem->Text = "Показать красный (R) канал";
			this->chart1->Series["R"]->Points->Clear();
			this->chart1->Series["Series1"]->Points->AddXY(0, 0);
		}
		else
		{
			this->скрытьКрасныйRКаналToolStripMenuItem->Text = "Скрыть красный (R) канал";
			for (int i = 255; i > 0; i--)
			{
				this->chart1->Series["R"]->Points->AddXY(i, R[i]);
			}
		}
	}

	private: System::Void скрытьЗелёныйGКаналToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->скрытьЗелёныйGКаналToolStripMenuItem->Text == "Скрыть зелёный (G) канал")
		{
			this->скрытьЗелёныйGКаналToolStripMenuItem->Text = "Показать зелёный (G) канал";
			this->chart1->Series["G"]->Points->Clear();
			this->chart1->Series["Series1"]->Points->AddXY(0, 0);
		}
		else
		{
			this->скрытьЗелёныйGКаналToolStripMenuItem->Text = "Скрыть зелёный (G) канал";
			for (int i = 255; i > 0; i--)
			{
				this->chart1->Series["G"]->Points->AddXY(i, G[i]);
			}
		}
	}

	private: System::Void скрытьСинийBКаналToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->скрытьСинийBКаналToolStripMenuItem->Text == "Скрыть синий (B) канал")
		{
			this->скрытьСинийBКаналToolStripMenuItem->Text = "Показать синий (B) канал";
			this->chart1->Series["B"]->Points->Clear();
			this->chart1->Series["Series1"]->Points->AddXY(0, 0);
		}
		else
		{
			this->скрытьСинийBКаналToolStripMenuItem->Text = "Скрыть синий (B) канал";
			for (int i = 255; i > 0; i--)
			{
				this->chart1->Series["B"]->Points->AddXY(i, B[i]);
			}
		}
	}
	};
}
