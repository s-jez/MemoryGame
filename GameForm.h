#pragma once

#include "Memory.h"
#include "Player.h"
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
		Player* player = new Player();
		array<PictureBox^, 2>^ pictureBoxBoard;


	private: System::Windows::Forms::Label^ playerTimeLabel;


	private: System::Windows::Forms::Timer^ gameTimer;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutGameToolStripMenuItem;


	private: System::Windows::Forms::Panel^ panel1;

	public:
		GameForm(String^ playerName)
		{
			InitializeComponent();
			initializeBoard();
			player->setPlayerName(marshal_as<std::string>(playerName));
			String^ playerNameLbl = gcnew String(player->getPlayerName().c_str());
			label1->Text = playerNameLbl;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->appToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->playerNameLbl = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->playerTimeLabel = (gcnew System::Windows::Forms::Label());
			this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->appToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutGameToolStripMenuItem,
					this->closeToolStripMenuItem
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
			// playerTimeLabel
			// 
			this->playerTimeLabel->AutoSize = true;
			this->playerTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->playerTimeLabel->ForeColor = System::Drawing::Color::White;
			this->playerTimeLabel->Location = System::Drawing::Point(592, 59);
			this->playerTimeLabel->Name = L"playerTimeLabel";
			this->playerTimeLabel->Size = System::Drawing::Size(0, 24);
			this->playerTimeLabel->TabIndex = 23;
			// 
			// gameTimer
			// 
			this->gameTimer->Enabled = true;
			this->gameTimer->Interval = 1000;
			this->gameTimer->Tick += gcnew System::EventHandler(this, &GameForm::GameTimer);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->ClientSize = System::Drawing::Size(884, 689);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->playerTimeLabel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->playerNameLbl);
			this->Controls->Add(this->menuStrip1);
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
		pictureBoxBoard = gcnew array<PictureBox^, 2>(memoryGame->rows, memoryGame->cols);
		int indexCard = 0;
		int pbWidth = 120, pbHeight = 140, pbPadding = 10;

		for (int row = 0; row < memoryGame->rows; row++) 
		{
			for (int col = 0; col < memoryGame->cols; col++) 
			{
				PictureBox^ pictureBox = gcnew PictureBox();
				pictureBox->Size = System::Drawing::Size(pbWidth, pbHeight);
				pictureBox->Location = Point(col * (pbWidth + pbPadding), row * (pbHeight + pbPadding));
				pictureBox->BorderStyle = BorderStyle::FixedSingle;
				pictureBox->BackColor = Color::LightBlue;
				pictureBox->Cursor = Cursors::Hand;
				pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
				std::string cardPath = "images/card" + memoryGame->getCardValue(indexCard) + ".png";
				pictureBox->Image = Image::FromFile(marshal_as<System::String^>(cardPath));
				pictureBox->Click += gcnew EventHandler(this, &GameForm::Card_Click);
				this->panel1->Controls->Add(pictureBox);
				pictureBoxBoard[row, col] = pictureBox;
				indexCard++;
			}
		}
		Task::Delay(5000)->ContinueWith(gcnew Action<Task^>(this, &GameForm::CoverAllCards));
		gameTimer->Start();
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
					if (memoryGame->board[i][j].isRevelead() == false) 
					{
						memoryGame->board[i][j].reveal();
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
		String^ cardValue = gcnew String(memoryGame->board[row][col].getValue().c_str());
		if (memoryGame->board[row][col].isRevelead() == true)
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
		int firstSelectedRow = memoryGame->getFirstSelectedCardRow();
		int firstSelectedCol = memoryGame->getFirstSelectedCardCol();
		int secondSelectedRow = memoryGame->getSecondSelectedCardRow();
		int secondSelectedCol = memoryGame->getSecondSelectedCardCol();

		bool isMatched = memoryGame->CheckForMatch(firstSelectedRow, firstSelectedCol, secondSelectedRow, secondSelectedCol);
		if (isMatched)
		{
			pictureBoxBoard[firstSelectedRow, firstSelectedCol]->Visible = false;
			pictureBoxBoard[secondSelectedRow, secondSelectedCol]->Visible = false;	

			// check if the game has ended
			bool gameEnd = true;
			for (int i = 0; i < memoryGame->rows; i++)
			{
				for (int j = 0; j < memoryGame->cols; j++)
				{
					if (memoryGame->board[i][j].isRevelead() == false)
					{
						gameEnd = false;
						break;
					}
				}
			}
			if (gameEnd)
			{
				gameTimer->Stop();
				MessageBox::Show("Congratulations! You have won the game in " + formatTimeForLabel(player->getPlayerTime()));
				this->Close();
			}
		}
		else
		{
			pictureBoxBoard[firstSelectedRow, firstSelectedCol]->Image = nullptr;
			pictureBoxBoard[firstSelectedRow, firstSelectedCol]->BackColor = Color::LightBlue;
			pictureBoxBoard[secondSelectedRow, secondSelectedCol]->Image = nullptr;
			pictureBoxBoard[secondSelectedRow, secondSelectedCol]->BackColor = Color::LightBlue;
			memoryGame->board[firstSelectedRow][firstSelectedCol].hide();
			memoryGame->board[secondSelectedRow][secondSelectedCol].hide();
		}
		memoryGame->resetSelectedCards();
		memoryGame->setProcessingClick(false);
	}
	void CoverAllCards(Task^ t) 
	{
		for each (PictureBox ^ pictureBox in pictureBoxBoard) {
			pictureBox->Image = nullptr;
			pictureBox->BackColor = Color::LightBlue;
		}
		memoryGame->setIsStarted(true);
	}
	void Test(Task^ t)
	{
	}
	private: System::Void GameTimer(System::Object^ sender, System::EventArgs^ e) 
	{
		if (memoryGame->getIsStarted() == false) return;
		player->setPlayerTime(player->getPlayerTime() + 1);
		playerTimeLabel->Text = "Your time: " + formatTimeForLabel(player->getPlayerTime());
	}
	// format time as mm:ss
	String^ formatTimeForLabel(int seconds) 
	{
		return String::Format("{0}:{1:D2}", seconds / 60, seconds % 60);
	}
};
}
