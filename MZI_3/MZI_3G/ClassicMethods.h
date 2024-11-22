#pragma once

#include <msclr/marshal.h>
#include "Cardano.h"
#include "init.h"

namespace MZI3G {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;
	using namespace System::Text;
	using namespace	Microsoft::VisualBasic;

	/// <summary>
	/// Сводка для Cardano
	/// </summary>
	public ref class ClassicMethods : public System::Windows::Forms::Form
	{
	public:
		ClassicMethods(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->before_tBox->Dock = System::Windows::Forms::DockStyle::None;
			this->before_tBox->Size = System::Drawing::Size(this->Width / 2 - 20, this->Height - 85);
			this->before_tBox->Location = System::Drawing::Point(10, 40);
			this->after_tBox->Dock = System::Windows::Forms::DockStyle::None;
			this->after_tBox->Size = System::Drawing::Size(this->Width / 2 - 25, this->Height - 85);
			this->after_tBox->Location = System::Drawing::Point(this->Width / 2, 40);
			openFileDialog1->Filter = "Text files (*.txt)|*.txt";
			saveFileDialog1->Filter = "Text files (*.txt)|*.txt";
			openFileDialog1->Title = "Select a File";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ClassicMethods()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ выбратьФайлToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ закрытьПриложениеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ режимРаботыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ зашифроватьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ расшифроватьToolStripMenuItem;




	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TextBox^ before_tBox;
	private: System::Windows::Forms::TextBox^ after_tBox;
	private: System::Windows::Forms::Label^ after_label;
	private: System::Windows::Forms::Label^ before_label;
	private: System::Windows::Forms::ToolStripMenuItem^ открытьФайлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранитВФайлToolStripMenuItem;




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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выбратьФайлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьФайлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитВФайлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->режимРаботыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->зашифроватьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расшифроватьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->закрытьПриложениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->before_tBox = (gcnew System::Windows::Forms::TextBox());
			this->after_tBox = (gcnew System::Windows::Forms::TextBox());
			this->after_label = (gcnew System::Windows::Forms::Label());
			this->before_label = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->выбратьФайлToolStripMenuItem,
					this->режимРаботыToolStripMenuItem, this->закрытьПриложениеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1264, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выбратьФайлToolStripMenuItem
			// 
			this->выбратьФайлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->открытьФайлToolStripMenuItem,
					this->сохранитВФайлToolStripMenuItem
			});
			this->выбратьФайлToolStripMenuItem->Name = L"выбратьФайлToolStripMenuItem";
			this->выбратьФайлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->выбратьФайлToolStripMenuItem->Text = L"Файл";
			// 
			// открытьФайлToolStripMenuItem
			// 
			this->открытьФайлToolStripMenuItem->Name = L"открытьФайлToolStripMenuItem";
			this->открытьФайлToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->открытьФайлToolStripMenuItem->Text = L"Открыть файл";
			this->открытьФайлToolStripMenuItem->Click += gcnew System::EventHandler(this, &ClassicMethods::открытьФайлToolStripMenuItem_Click);
			// 
			// сохранитВФайлToolStripMenuItem
			// 
			this->сохранитВФайлToolStripMenuItem->Name = L"сохранитВФайлToolStripMenuItem";
			this->сохранитВФайлToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->сохранитВФайлToolStripMenuItem->Text = L"Сохранить в файл";
			this->сохранитВФайлToolStripMenuItem->Click += gcnew System::EventHandler(this, &ClassicMethods::сохранитВФайлToolStripMenuItem_Click);
			// 
			// режимРаботыToolStripMenuItem
			// 
			this->режимРаботыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->зашифроватьToolStripMenuItem,
					this->расшифроватьToolStripMenuItem
			});
			this->режимРаботыToolStripMenuItem->Name = L"режимРаботыToolStripMenuItem";
			this->режимРаботыToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->режимРаботыToolStripMenuItem->Text = L"Режим работы";
			// 
			// зашифроватьToolStripMenuItem
			// 
			this->зашифроватьToolStripMenuItem->Name = L"зашифроватьToolStripMenuItem";
			this->зашифроватьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->зашифроватьToolStripMenuItem->Text = L"Зашифровать";
			this->зашифроватьToolStripMenuItem->Click += gcnew System::EventHandler(this, &ClassicMethods::зашифроватьToolStripMenuItem_Click);
			// 
			// расшифроватьToolStripMenuItem
			// 
			this->расшифроватьToolStripMenuItem->Name = L"расшифроватьToolStripMenuItem";
			this->расшифроватьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->расшифроватьToolStripMenuItem->Text = L"Расшифровать";
			this->расшифроватьToolStripMenuItem->Click += gcnew System::EventHandler(this, &ClassicMethods::расшифроватьToolStripMenuItem_Click);
			// 
			// закрытьПриложениеToolStripMenuItem
			// 
			this->закрытьПриложениеToolStripMenuItem->Name = L"закрытьПриложениеToolStripMenuItem";
			this->закрытьПриложениеToolStripMenuItem->Size = System::Drawing::Size(138, 20);
			this->закрытьПриложениеToolStripMenuItem->Text = L"Закрыть приложение";
			this->закрытьПриложениеToolStripMenuItem->Click += gcnew System::EventHandler(this, &ClassicMethods::закрытьПриложениеToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// before_tBox
			// 
			this->before_tBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->before_tBox->Location = System::Drawing::Point(12, 39);
			this->before_tBox->Multiline = true;
			this->before_tBox->Name = L"before_tBox";
			this->before_tBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->before_tBox->Size = System::Drawing::Size(621, 630);
			this->before_tBox->TabIndex = 1;
			// 
			// after_tBox
			// 
			this->after_tBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->after_tBox->Location = System::Drawing::Point(639, 39);
			this->after_tBox->Multiline = true;
			this->after_tBox->Name = L"after_tBox";
			this->after_tBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->after_tBox->Size = System::Drawing::Size(613, 630);
			this->after_tBox->TabIndex = 2;
			// 
			// after_label
			// 
			this->after_label->AutoSize = true;
			this->after_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->after_label->Location = System::Drawing::Point(639, 26);
			this->after_label->Name = L"after_label";
			this->after_label->Size = System::Drawing::Size(0, 20);
			this->after_label->TabIndex = 3;
			// 
			// before_label
			// 
			this->before_label->AutoSize = true;
			this->before_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->before_label->Location = System::Drawing::Point(11, 26);
			this->before_label->Name = L"before_label";
			this->before_label->Size = System::Drawing::Size(0, 20);
			this->before_label->TabIndex = 4;
			// 
			// ClassicMethods
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->before_label);
			this->Controls->Add(this->after_label);
			this->Controls->Add(this->after_tBox);
			this->Controls->Add(this->before_tBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1920, 1080);
			this->MinimumSize = System::Drawing::Size(1280, 720);
			this->Name = L"ClassicMethods";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cardano";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Resize += gcnew System::EventHandler(this, &ClassicMethods::Cardano_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void зашифроватьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (before_tBox->Text == "") {
			MessageBox::Show("Поле ввода текста пустое", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {

			before_label->Text = "Открытый текст";
			after_label->Text = "Зашифрованный текст";
			after_tBox->Clear();
			after_tBox->Text = gcnew String(init(0, msclr::interop::marshal_as<std::string>(before_tBox->Text)).c_str());
		}
	}

	private: System::Void расшифроватьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (before_tBox->Text == "") {
			MessageBox::Show("Поле ввода текста пустое", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
				before_label->Text = "Зашифрованный текст";
				after_label->Text = "Открытый текст";
				after_tBox->Clear();
				after_tBox->Text = gcnew String(init(1, msclr::interop::marshal_as<std::string>(before_tBox->Text)).c_str());
		}
	}

	private: System::Void открытьФайлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filepath = openFileDialog1->FileName;
			try {
				StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName);
				before_tBox->Text = reader->ReadToEnd();
				reader->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка при чтении файла: " + ex->Message);
			}
		}
	}

	private: System::Void сохранитВФайлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "Text files (*.txt)|*.txt";
		saveFileDialog->Title = "Save a File";

		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filePath = saveFileDialog->FileName;

			try {
				StreamWriter^ writer = gcnew StreamWriter(filePath);
				writer->Write(after_tBox->Text);
				writer->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Ошибка при записи в файл: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void закрытьПриложениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult temp = MessageBox::Show("Вы уверены, что хотите закрыть приложение?", "Предупреждение", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
		if (temp == System::Windows::Forms::DialogResult::OK) {
			this->Close();
		}
	}

	private: System::Void Cardano_Resize(System::Object^ sender, System::EventArgs^ e) {
		this->before_tBox->Size = System::Drawing::Size(this->Width / 2 - 20, this->Height - 100);
		this->before_tBox->Location = System::Drawing::Point(10, 55);
		this->before_label->Location = System::Drawing::Point(10, 30);
		this->after_tBox->Size = System::Drawing::Size(this->Width / 2 - 25, this->Height - 100);
		this->after_tBox->Location = System::Drawing::Point(this->Width / 2, 55);
		this->after_label->Location = System::Drawing::Point(this->Width / 2, 30);
	}
};
}
