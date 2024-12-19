#pragma once

#include "Memory.h"
#include "AboutForm.h"
#include "HighScoreForm.h"
#include <random>
#include <msclr/marshal_cppstd.h>
#include <map>

namespace MemoryGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace msclr::interop;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	private:
		Memory* memoryGame = new Memory(4, 4);
		array<PictureBox^, 2>^ pictureBoxBoard;

	private: System::Windows::Forms::Label^ playerStepLabel;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ highScoreToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel1;

	public:
		GameForm(String^ playerName)
		{
			InitializeComponent();
			initializeBoard();
			memoryGame->getPlayer()->setPlayerName(marshal_as<std::string>(playerName));
			label1->Text = gcnew String(memoryGame->getPlayer()->getPlayerName().c_str());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameForm()
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
	private: System::Windows::Forms::ToolStripMenuItem^ appToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeToolStripMenuItem;
	private: System::Windows::Forms::Label^ playerNameLbl;

	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->appToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->highScoreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->playerNameLbl = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->playerStepLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->appToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(884, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// appToolStripMenuItem
			// 
			this->appToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->aboutGameToolStripMenuItem,
					this->highScoreToolStripMenuItem, this->closeToolStripMenuItem
			});
			this->appToolStripMenuItem->Name = L"appToolStripMenuItem";
			this->appToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->appToolStripMenuItem->Text = L"Game";
			// 
			// aboutGameToolStripMenuItem
			// 
			this->aboutGameToolStripMenuItem->Name = L"aboutGameToolStripMenuItem";
			this->aboutGameToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->aboutGameToolStripMenuItem->Text = L"About game";
			this->aboutGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::aboutGameToolStripMenuItem_Click);
			// 
			// highScoreToolStripMenuItem
			// 
			this->highScoreToolStripMenuItem->Name = L"highScoreToolStripMenuItem";
			this->highScoreToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->highScoreToolStripMenuItem->Text = L"High score";
			this->highScoreToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::highScoreToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::closeToolStripMenuItem_Click);
			// 
			// playerNameLbl
			// 
			this->playerNameLbl->AutoSize = true;
			this->playerNameLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->playerNameLbl->ForeColor = System::Drawing::Color::White;
			this->playerNameLbl->Location = System::Drawing::Point(87, 47);
			this->playerNameLbl->Name = L"playerNameLbl";
			this->playerNameLbl->Size = System::Drawing::Size(0, 24);
			this->playerNameLbl->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(25, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 24);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Player";
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(23, 81);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(537, 577);
			this->panel1->TabIndex = 22;
			// 
			// playerStepLabel
			// 
			this->playerStepLabel->AutoSize = true;
			this->playerStepLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->playerStepLabel->ForeColor = System::Drawing::Color::White;
			this->playerStepLabel->Location = System::Drawing::Point(593, 47);
			this->playerStepLabel->Name = L"playerStepLabel";
			this->playerStepLabel->Size = System::Drawing::Size(0, 24);
			this->playerStepLabel->TabIndex = 23;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->ClientSize = System::Drawing::Size(884, 689);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->playerStepLabel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->playerNameLbl);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GameForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Memory Game";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
    private: System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e) 
    {
    }
	private: System::Void closeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Application::Exit();
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
	}
	private: void initializeBoard() 
	{
		pictureBoxBoard = gcnew array<PictureBox^, 2>(memoryGame->getRows(), memoryGame->getCols());
		int pbWidth = 120, pbHeight = 140, pbPadding = 10;
		for (int row = 0; row < memoryGame->getRows(); row++) 
		{
			for (int col = 0; col < memoryGame->getCols(); col++) 
			{
				PictureBox^ pictureBox = gcnew PictureBox();
				pictureBox->Size = System::Drawing::Size(pbWidth, pbHeight);
				pictureBox->Location = Point(col * (pbWidth + pbPadding), row * (pbHeight + pbPadding));
				pictureBox->BorderStyle = BorderStyle::FixedSingle;
				pictureBox->BackColor = Color::LightBlue;
				pictureBox->Cursor = Cursors::Hand;
				pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
				std::string cardPath = "images/card" + memoryGame->getCard(row, col).getValue() + ".png";
				pictureBox->Image = Image::FromFile(marshal_as<System::String^>(cardPath));
				pictureBox->Click += gcnew EventHandler(this, &GameForm::Card_Click);
				this->panel1->Controls->Add(pictureBox);
				pictureBoxBoard[row, col] = pictureBox;
			}
		}
		Task::Delay(5000)->ContinueWith(gcnew Action<Task^>(this, &GameForm::CoverAllCards));
	}
	void Card_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (memoryGame->getProcessingClick() == true) return;
		if (memoryGame->getIsStarted() == false) return;

		PictureBox^ clickedPictureBox = dynamic_cast<PictureBox^>(sender);
		for (int i = 0; i < pictureBoxBoard->GetLength(0); i++)
		{
			for (int j = 0; j < pictureBoxBoard->GetLength(1); j++) 
			{
				if (pictureBoxBoard[i, j] == clickedPictureBox)
				{
					if (memoryGame->getCard(i, j).isRevelead() == false)
					{
						memoryGame->getCard(i, j).reveal();
						ShowPictureBox(i, j);
						bool firstCardSelected = memoryGame->getFirstSelectedCardRow() == -1 && memoryGame->getFirstSelectedCardCol() == -1;
						if (firstCardSelected)
						{
							memoryGame->setFirstSelectedCardRow(i);
							memoryGame->setFirstSelectedCardCol(j);
						}
						else
						{
							memoryGame->setProcessingClick(true);
							memoryGame->setSecondSelectedCardRow(i);
							memoryGame->setSecondSelectedCardCol(j);
							Task::Delay(1000)->ContinueWith(gcnew Action<Task^>(this, &GameForm::HandleSecondCard));
						}
					}
					return;
				}
			}
		}
	}
	void ShowPictureBox(int row, int col) 
	{
		String^ cardValue = gcnew String(memoryGame->getCard(row, col).getValue().c_str());
		if (memoryGame->getCard(row, col).isRevelead() == true)
		{
			pictureBoxBoard[row, col]->Image = Image::FromFile("images/card" + cardValue + ".png");
		}
		else
		{
			pictureBoxBoard[row, col]->Image = nullptr;
		}
	}
	void HandleSecondCard(Task ^t)
	{
		if (this->InvokeRequired)
		{
			this->Invoke(gcnew Action<Task^>(this, &GameForm::HandleSecondCard), t);
			return;
		}
		int firstSelectedRow = memoryGame->getFirstSelectedCardRow();
		int firstSelectedCol = memoryGame->getFirstSelectedCardCol();
		int secondSelectedRow = memoryGame->getSecondSelectedCardRow();
		int secondSelectedCol = memoryGame->getSecondSelectedCardCol();

		int step = memoryGame->getPlayer()->getPlayerStep() + 1;
		memoryGame->getPlayer()->setPlayerStep(step);
		playerStepLabel->Text = "Step " + memoryGame->getPlayer()->getPlayerStep().ToString();
		bool isMatched = memoryGame->CheckForMatch(firstSelectedRow, firstSelectedCol, secondSelectedRow, secondSelectedCol);
		if (isMatched)
		{
			pictureBoxBoard[firstSelectedRow, firstSelectedCol]->Visible = false;
			pictureBoxBoard[secondSelectedRow, secondSelectedCol]->Visible = false;	
			if (memoryGame->checkForEnd())
			{
				MessageBox::Show(gcnew String(memoryGame->getPlayer()->getPlayerName().c_str()) + " won the game in " + memoryGame->getPlayer()->getPlayerStep() + " steps", "Memory Game", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
		}
		else
		{
			pictureBoxBoard[firstSelectedRow, firstSelectedCol]->Image = nullptr;
			pictureBoxBoard[firstSelectedRow, firstSelectedCol]->BackColor = Color::LightBlue;
			pictureBoxBoard[secondSelectedRow, secondSelectedCol]->Image = nullptr;
			pictureBoxBoard[secondSelectedRow, secondSelectedCol]->BackColor = Color::LightBlue;
			memoryGame->getCard(firstSelectedRow, firstSelectedCol).hide();
			memoryGame->getCard(secondSelectedRow, secondSelectedCol).hide();
		}
		memoryGame->resetSelectedCards();
		memoryGame->setProcessingClick(false);
	}
	void CoverAllCards(Task^ t)
	{
		for (int i = 0; i < memoryGame->getRows(); i++)
		{
			for (int j = 0; j < memoryGame->getCols(); j++)
			{
				pictureBoxBoard[i, j]->Image = nullptr;
				pictureBoxBoard[i, j]->BackColor = Color::LightBlue;
			}
		}
		memoryGame->setIsStarted(true);
	}
	private: System::Void aboutGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		AboutForm^ aboutForm = gcnew AboutForm();
		aboutForm->Show();
	}
	private: System::Void highScoreToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		HighScoreForm^ highScoreForm = gcnew HighScoreForm();
		highScoreForm->Show();
	}
};
}
