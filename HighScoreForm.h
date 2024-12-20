#pragma once
#include "AboutForm.h"
#include "Player.h"
#include "Memory.h"

namespace MemoryGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HighScoreForm
	/// </summary>
	public ref class HighScoreForm : public System::Windows::Forms::Form
	{
	private:
		Memory* memoryGame = new Memory(4, 4);

	public:
		HighScoreForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HighScoreForm()
		{
			if (components)
			{
				delete components;
			}
			if (memoryGame)
			{
				delete memoryGame;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ highScoreGridView;
	private: System::Windows::Forms::Label^ label1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HighScoreForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->highScoreGridView = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->highScoreGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->gameToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(884, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutGameToolStripMenuItem,
					this->closeToolStripMenuItem
			});
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->gameToolStripMenuItem->Text = L"Game";
			// 
			// aboutGameToolStripMenuItem
			// 
			this->aboutGameToolStripMenuItem->Name = L"aboutGameToolStripMenuItem";
			this->aboutGameToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->aboutGameToolStripMenuItem->Text = L"About game";
			this->aboutGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &HighScoreForm::aboutGameToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &HighScoreForm::closeToolStripMenuItem_Click);
			// 
			// highScoreGridView
			// 
			this->highScoreGridView->AllowUserToAddRows = false;
			this->highScoreGridView->AllowUserToDeleteRows = false;
			this->highScoreGridView->AllowUserToResizeColumns = false;
			this->highScoreGridView->AllowUserToResizeRows = false;
			this->highScoreGridView->BackgroundColor = System::Drawing::Color::MediumSlateBlue;
			this->highScoreGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->highScoreGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->highScoreGridView->Location = System::Drawing::Point(24, 93);
			this->highScoreGridView->Name = L"highScoreGridView";
			this->highScoreGridView->ReadOnly = true;
			this->highScoreGridView->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->highScoreGridView->Size = System::Drawing::Size(478, 463);
			this->highScoreGridView->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(20, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"High Score";
			// 
			// HighScoreForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->ClientSize = System::Drawing::Size(884, 689);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->highScoreGridView);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"HighScoreForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Memory Game - High Score";
			this->Load += gcnew System::EventHandler(this, &HighScoreForm::HighScoreForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->highScoreGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void closeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void aboutGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AboutForm^ aboutForm = gcnew AboutForm();
		aboutForm->Show();
	}
	private: System::Void HighScoreForm_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			memoryGame->getHighScore()->readHighScores();
			std::vector<Player> scores = memoryGame->getHighScore()->getPlayersScore();

			DataTable^ dt = gcnew DataTable();
			highScoreGridView->RowTemplate->Height = 30;
			highScoreGridView->ColumnHeadersHeight = 30;

			dt->Columns->Add("Player Name");
			dt->Columns->Add("Player Steps");

			for (int i = 0; i < scores.size(); i++) {
				dt->Rows->Add(gcnew cli::array<String^> { gcnew String(scores[i].getPlayerName().c_str()), scores[i].getPlayerStep().ToString() });
			}
			highScoreGridView->DataSource = dt;
		}
		catch (const std::exception& e) {
			MessageBox::Show(gcnew String(e.what()), "Memory Game", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
		}
	}
};
}
