#pragma once

#include "Cardano.h"

namespace MZI3G {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;

	/// <summary>
	/// Ñâîäêà äëÿ Cardano
	/// </summary>
	public ref class CardanoG : public System::Windows::Forms::Form
	{
	public:
		CardanoG(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
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
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~CardanoG()
		{
			if (components)
			{
				delete components;
			}
		}
	private: char method = 0;
	private: String^ key;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ âûáğàòüÔàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ìåòîäToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ çàêğûòüÏğèëîæåíèåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ğåæèìĞàáîòûToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ çàøèôğîâàòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ğàñøèôğîâàòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ áåçÊëş÷àToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ êëş÷ÍîìåğToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ êëş÷ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ êëş÷ÏÑÏToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TextBox^ before_tBox;
	private: System::Windows::Forms::TextBox^ after_tBox;
	private: System::Windows::Forms::Label^ after_label;
	private: System::Windows::Forms::Label^ before_label;
	private: System::Windows::Forms::ToolStripMenuItem^ îòêğûòüÔàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ñîõğàíèòÂÔàéëToolStripMenuItem;
	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->âûáğàòüÔàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüÔàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñîõğàíèòÂÔàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğåæèìĞàáîòûToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàøèôğîâàòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ğàñøèôğîâàòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ìåòîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->áåçÊëş÷àToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->êëş÷ÍîìåğToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->êëş÷ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->êëş÷ÏÑÏToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->âûáğàòüÔàéëToolStripMenuItem,
					this->ğåæèìĞàáîòûToolStripMenuItem, this->ìåòîäToolStripMenuItem, this->çàêğûòüÏğèëîæåíèåToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1264, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// âûáğàòüÔàéëToolStripMenuItem
			// 
			this->âûáğàòüÔàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->îòêğûòüÔàéëToolStripMenuItem,
					this->ñîõğàíèòÂÔàéëToolStripMenuItem
			});
			this->âûáğàòüÔàéëToolStripMenuItem->Name = L"âûáğàòüÔàéëToolStripMenuItem";
			this->âûáğàòüÔàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->âûáğàòüÔàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// îòêğûòüÔàéëToolStripMenuItem
			// 
			this->îòêğûòüÔàéëToolStripMenuItem->Name = L"îòêğûòüÔàéëToolStripMenuItem";
			this->îòêğûòüÔàéëToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->îòêğûòüÔàéëToolStripMenuItem->Text = L"Îòêğûòü ôàéë";
			this->îòêğûòüÔàéëToolStripMenuItem->Click += gcnew System::EventHandler(this, &CardanoG::îòêğûòüÔàéëToolStripMenuItem_Click);
			// 
			// ñîõğàíèòÂÔàéëToolStripMenuItem
			// 
			this->ñîõğàíèòÂÔàéëToolStripMenuItem->Name = L"ñîõğàíèòÂÔàéëToolStripMenuItem";
			this->ñîõğàíèòÂÔàéëToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->ñîõğàíèòÂÔàéëToolStripMenuItem->Text = L"Ñîõğàíèòü â ôàéë";
			this->ñîõğàíèòÂÔàéëToolStripMenuItem->Click += gcnew System::EventHandler(this, &CardanoG::ñîõğàíèòÂÔàéëToolStripMenuItem_Click);
			// 
			// ğåæèìĞàáîòûToolStripMenuItem
			// 
			this->ğåæèìĞàáîòûToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->çàøèôğîâàòüToolStripMenuItem,
					this->ğàñøèôğîâàòüToolStripMenuItem
			});
			this->ğåæèìĞàáîòûToolStripMenuItem->Name = L"ğåæèìĞàáîòûToolStripMenuItem";
			this->ğåæèìĞàáîòûToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->ğåæèìĞàáîòûToolStripMenuItem->Text = L"Ğåæèì ğàáîòû";
			// 
			// çàøèôğîâàòüToolStripMenuItem
			// 
			this->çàøèôğîâàòüToolStripMenuItem->Name = L"çàøèôğîâàòüToolStripMenuItem";
			this->çàøèôğîâàòüToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->çàøèôğîâàòüToolStripMenuItem->Text = L"Çàøèôğîâàòü";
			this->çàøèôğîâàòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &CardanoG::çàøèôğîâàòüToolStripMenuItem_Click);
			// 
			// ğàñøèôğîâàòüToolStripMenuItem
			// 
			this->ğàñøèôğîâàòüToolStripMenuItem->Name = L"ğàñøèôğîâàòüToolStripMenuItem";
			this->ğàñøèôğîâàòüToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->ğàñøèôğîâàòüToolStripMenuItem->Text = L"Ğàñøèôğîâàòü";
			this->ğàñøèôğîâàòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &CardanoG::ğàñøèôğîâàòüToolStripMenuItem_Click);
			// 
			// ìåòîäToolStripMenuItem
			// 
			this->ìåòîäToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->áåçÊëş÷àToolStripMenuItem,
					this->êëş÷ÍîìåğToolStripMenuItem, this->êëş÷ToolStripMenuItem, this->êëş÷ÏÑÏToolStripMenuItem
			});
			this->ìåòîäToolStripMenuItem->Name = L"ìåòîäToolStripMenuItem";
			this->ìåòîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->ìåòîäToolStripMenuItem->Text = L"Ìåòîä";
			// 
			// áåçÊëş÷àToolStripMenuItem
			// 
			this->áåçÊëş÷àToolStripMenuItem->Name = L"áåçÊëş÷àToolStripMenuItem";
			this->áåçÊëş÷àToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->áåçÊëş÷àToolStripMenuItem->Text = L"Áåç êëş÷à";
			this->áåçÊëş÷àToolStripMenuItem->Click += gcnew System::EventHandler(this, &CardanoG::áåçÊëş÷àToolStripMenuItem_Click);
			// 
			// êëş÷ÍîìåğToolStripMenuItem
			// 
			this->êëş÷ÍîìåğToolStripMenuItem->Name = L"êëş÷ÍîìåğToolStripMenuItem";
			this->êëş÷ÍîìåğToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->êëş÷ÍîìåğToolStripMenuItem->Text = L"Êëş÷ – íîìåğ â ãğóïïå";
			this->êëş÷ÍîìåğToolStripMenuItem->Click += gcnew System::EventHandler(this, &CardanoG::êëş÷ÍîìåğToolStripMenuItem_Click);
			// 
			// êëş÷ToolStripMenuItem
			// 
			this->êëş÷ToolStripMenuItem->Name = L"êëş÷ToolStripMenuItem";
			this->êëş÷ToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->êëş÷ToolStripMenuItem->Text = L"Êëş÷ – ïîãîâîğêà";
			this->êëş÷ToolStripMenuItem->Click += gcnew System::EventHandler(this, &CardanoG::êëş÷ToolStripMenuItem_Click);
			// 
			// êëş÷ÏÑÏToolStripMenuItem
			// 
			this->êëş÷ÏÑÏToolStripMenuItem->Name = L"êëş÷ÏÑÏToolStripMenuItem";
			this->êëş÷ÏÑÏToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->êëş÷ÏÑÏToolStripMenuItem->Text = L"Êëş÷ – ÏÑÏ";
			this->êëş÷ÏÑÏToolStripMenuItem->Click += gcnew System::EventHandler(this, &CardanoG::êëş÷ÏÑÏToolStripMenuItem_Click);
			// 
			// çàêğûòüÏğèëîæåíèåToolStripMenuItem
			// 
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Name = L"çàêğûòüÏğèëîæåíèåToolStripMenuItem";
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Size = System::Drawing::Size(138, 20);
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Text = L"Çàêğûòü ïğèëîæåíèå";
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
			// CardanoG
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
			this->Name = L"CardanoG";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cardano";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Resize += gcnew System::EventHandler(this, &CardanoG::Cardano_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		std::string sysToStd(String^ str) {
			msclr::interop::marshal_context context;
			return context.marshal_as<std::string>(str);
		}

		String^ stdToSys(std::string str) {
			return msclr::interop::marshal_as<String^>(str);
		}

	private: System::Void toolStripComboBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void Cardano_Resize(System::Object^ sender, System::EventArgs^ e) {
		this->before_tBox->Size = System::Drawing::Size(this->Width / 2 - 20, this->Height - 100);
		this->before_tBox->Location = System::Drawing::Point(10, 55);
		this->before_label->Location = System::Drawing::Point(10, 30);
		this->after_tBox->Size = System::Drawing::Size(this->Width / 2 - 25, this->Height - 100);
		this->after_tBox->Location = System::Drawing::Point(this->Width / 2, 55);
		this->after_label->Location = System::Drawing::Point(this->Width / 2, 30);
	}

	private: System::Void çàøèôğîâàòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!method) {
			MessageBox::Show("Íå âûáğàí ìåòîä äëÿ øèôğîâàíèÿ", "Ïğåäóïğåæäåíèå", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (before_tBox->Text == "") {
			MessageBox::Show("Ïîëå ââîäà òåêñòà ïóñòîå", "Ïğåäóïğåæäåíèå", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			before_label->Text = "Îòêğûòûé òåêñò";
			after_label->Text = "Çàøèôğîâàííûé òåêñò";
			after_tBox->Clear();
			after_tBox->Text = stdToSys(init(method, 0, sysToStd(before_tBox->Text)));
		}
	}

	private: System::Void ğàñøèôğîâàòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!method) {
			MessageBox::Show("Íå âûáğàí ìåòîä äëÿ øèôğîâàíèÿ", "Ïğåäóïğåæäåíèå", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (before_tBox->Text == "") {
			MessageBox::Show("Ïîëå ââîäà òåêñòà ïóñòîå", "Ïğåäóïğåæäåíèå", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			before_label->Text = "Çàøèôğîâàííûé òåêñò";
			after_label->Text = "Îòêğûòûé òåêñò";
			after_tBox->Clear();
			after_tBox->Text = stdToSys(init(method, 1, sysToStd(before_tBox->Text)));
		}
	}

	private: System::Void îòêğûòüÔàéëToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Îòîáğàæåíèå âûáğàííîãî ïóòè ê ôàéëó â òåêñòîâîì ïîëå
			String^ filepath = openFileDialog1->FileName;

			// ×òåíèå ñîäåğæèìîãî ôàéëà
			try {
				StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName);
				before_tBox->Text = reader->ReadToEnd();
				reader->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Îøèáêà ïğè ÷òåíèè ôàéëà: " + ex->Message);
			}
		}
	}

	private: System::Void ñîõğàíèòÂÔàéëToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
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
				MessageBox::Show("Îøèáêà ïğè çàïèñè â ôàéë: " + ex->Message, "Îøèáêà", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	// Ìåòîä áåç êëş÷à
	private: System::Void áåçÊëş÷àToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		method = 1;
		áåçÊëş÷àToolStripMenuItem->Enabled = false;
		êëş÷ÍîìåğToolStripMenuItem->Enabled = true;
		êëş÷ToolStripMenuItem->Enabled = true;
		êëş÷ÏÑÏToolStripMenuItem->Enabled = true;
	}
	
	// Ìåòîä êëş÷ íîìåğ â ñïèñêå
	private: System::Void êëş÷ÍîìåğToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		method = 2;
		áåçÊëş÷àToolStripMenuItem->Enabled = true;
		êëş÷ÍîìåğToolStripMenuItem->Enabled = false;
		êëş÷ToolStripMenuItem->Enabled = true;
		êëş÷ÏÑÏToolStripMenuItem->Enabled = true;
	}
	
	// Ìåòîä êëş÷ ïîãîâîğêà
	private: System::Void êëş÷ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		method = 3;
		áåçÊëş÷àToolStripMenuItem->Enabled = true;
		êëş÷ÍîìåğToolStripMenuItem->Enabled = true;
		êëş÷ToolStripMenuItem->Enabled = false;
		êëş÷ÏÑÏToolStripMenuItem->Enabled = true;
	}

	// Ìåòîä êëş÷ ÏÑÏ
	private: System::Void êëş÷ÏÑÏToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		method = 4;
		áåçÊëş÷àToolStripMenuItem->Enabled = true;
		êëş÷ÍîìåğToolStripMenuItem->Enabled = true;
		êëş÷ToolStripMenuItem->Enabled = true;
		êëş÷ÏÑÏToolStripMenuItem->Enabled = false;
	}
};
}
