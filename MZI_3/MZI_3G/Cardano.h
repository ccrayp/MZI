#pragma once

namespace MZI3G {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ Cardano
	/// </summary>
	public ref class Cardano : public System::Windows::Forms::Form
	{
	public:
		Cardano(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~Cardano()
		{
			if (components)
			{
				delete components;
			}
		}
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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;




	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->âûáğàòüÔàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
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
			this->âûáğàòüÔàéëToolStripMenuItem->Name = L"âûáğàòüÔàéëToolStripMenuItem";
			this->âûáğàòüÔàéëToolStripMenuItem->Size = System::Drawing::Size(98, 20);
			this->âûáğàòüÔàéëToolStripMenuItem->Text = L"Âûáğàòü ôàéë";
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
			this->çàøèôğîâàòüToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->çàøèôğîâàòüToolStripMenuItem->Text = L"Çàøèôğîâàòü";
			// 
			// ğàñøèôğîâàòüToolStripMenuItem
			// 
			this->ğàñøèôğîâàòüToolStripMenuItem->Name = L"ğàñøèôğîâàòüToolStripMenuItem";
			this->ğàñøèôğîâàòüToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ğàñøèôğîâàòüToolStripMenuItem->Text = L"Ğàñøèôğîâàòü";
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
			// 
			// êëş÷ÍîìåğToolStripMenuItem
			// 
			this->êëş÷ÍîìåğToolStripMenuItem->Name = L"êëş÷ÍîìåğToolStripMenuItem";
			this->êëş÷ÍîìåğToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->êëş÷ÍîìåğToolStripMenuItem->Text = L"Êëş÷ – íîìåğ â ãğóïïå";
			// 
			// êëş÷ToolStripMenuItem
			// 
			this->êëş÷ToolStripMenuItem->Name = L"êëş÷ToolStripMenuItem";
			this->êëş÷ToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->êëş÷ToolStripMenuItem->Text = L"Êëş÷ – ïîãîâîğêà";
			// 
			// êëş÷ÏÑÏToolStripMenuItem
			// 
			this->êëş÷ÏÑÏToolStripMenuItem->Name = L"êëş÷ÏÑÏToolStripMenuItem";
			this->êëş÷ÏÑÏToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->êëş÷ÏÑÏToolStripMenuItem->Text = L"Êëş÷ – ÏÑÏ";
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
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(12, 27);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(612, 642);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(640, 27);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(612, 642);
			this->textBox2->TabIndex = 2;
			// 
			// Cardano
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1920, 1080);
			this->MinimumSize = System::Drawing::Size(1280, 720);
			this->Name = L"Cardano";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cardano";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toolStripComboBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
