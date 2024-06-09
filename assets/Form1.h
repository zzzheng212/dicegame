#pragma once
#include <iostream>
#include <fstream>
#include <chrono> // For std::chrono
#include<time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "data_format.h"

#define PI 3.14
int system_counter = 0;
float X = 0;
float Y = 0;
float Theta = 5;
float V = 0;
float W = 0;
float dt = 0.1;
struct enemy_profile obs[500];
struct dice_profile dice[10];
struct dice_weapon_profile wea[10];
struct freeze_dice_profile frez;
struct freeze_bullet_profile wea1;
struct nuclear_dice_profile nuc;
struct nuclear_weapon_profile wea2;
AOE_dice_profile AOEdice;
AOEdice_weapon_profile AOE_wea;

int Lead_obs = 0;
int obs_distance = 15;
int obs_x_velocity = 10;
int obs_y_velocity = 10;
bool need_gameover_display = true;
bool needmap = true;

namespace CppCLRWinFormsProjekt {

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
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
#pragma region Windows Form Designer generated code
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;




	protected:
	private: System::ComponentModel::IContainer^ components;

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(3, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 80);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add Dice!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 38);
			this->progressBar1->Maximum = 10000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(372, 23);
			this->progressBar1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Green;
			this->label1->Location = System::Drawing::Point(12, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"energy bad";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(3, 80);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 52);
			this->button2->TabIndex = 3;
			this->button2->Text = L"power!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(3, 33);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 43);
			this->button3->TabIndex = 4;
			this->button3->Text = L"speed!";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(84, 35);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 80);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Add freeze dice!";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button5->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button5->Location = System::Drawing::Point(165, 35);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 80);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Add nuclear dice!";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(246, 34);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 81);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Add AOE dice!";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Location = System::Drawing::Point(390, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(325, 155);
			this->panel1->TabIndex = 9;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Snap ITC", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Green;
			this->label9->Location = System::Drawing::Point(252, 117);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(63, 34);
			this->label9->TabIndex = 16;
			this->label9->Text = L"energy:\r\n  100";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Snap ITC", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Green;
			this->label8->Location = System::Drawing::Point(172, 117);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(69, 34);
			this->label8->TabIndex = 15;
			this->label8->Text = L"energy: \r\n 500";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Snap ITC", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Green;
			this->label7->Location = System::Drawing::Point(91, 118);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 34);
			this->label7->TabIndex = 14;
			this->label7->Text = L"energy: \r\n 100";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Snap ITC", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Green;
			this->label6->Location = System::Drawing::Point(9, 118);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 34);
			this->label6->TabIndex = 13;
			this->label6->Text = L"energy: \r\n 20";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->ImageKey = L"(無)";
			this->label2->Location = System::Drawing::Point(126, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 18);
			this->label2->TabIndex = 9;
			this->label2->Text = L"ADD DICE!";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Snap ITC", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(82, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 17);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Velasity：100";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Snap ITC", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(82, 98);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 19);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Power：10";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->label3);
			this->panel2->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->panel2->Location = System::Drawing::Point(721, 6);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(210, 155);
			this->panel2->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label5->Location = System::Drawing::Point(44, 11);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(126, 18);
			this->label5->TabIndex = 12;
			this->label5->Text = L"enhance skill!";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 595);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
		void Motion_model(void)
		{
			for (int i = 0; i < 500; i++)
			{
				if (obs[i].enable == 1)
				{

					obs[i].pos.X = obs[i].pos.X + obs[i].V.Vx * dt;
					obs[i].pos.Y = obs[i].pos.Y + obs[i].V.Vy * dt;

				}
				if (obs[i].pos.X == -175 && obs[i].pos.Y >= obs_distance)
				{
					obs[i + 1].enable = 1;
				}

				else if (obs[i].pos.X == -175 && obs[i].pos.Y == 200)
				{
					obs[i].V.Vy = 0;
					obs[i].V.Vx = obs_x_velocity;
				}
				else if (obs[i].pos.X == 480 && obs[i].pos.Y == 200)
				{
					obs[i].V.Vy = -obs_y_velocity;
					obs[i].V.Vx = 0;
				}
			}
			for (int i = 0; i < 10; i++)
			{
				if (dice[i].enable == 1)
				{
					dice[i].pos.X = dice[i].pos.X;
					dice[i].pos.Y = dice[i].pos.Y;
				}

			}
			if (need_gameover_display) {
				if (obs[Lead_obs].pos.X >= 480 && obs[Lead_obs].pos.Y <= -20)
				{
					need_gameover_display = false;
					System::Windows::Forms::DialogResult result = MessageBox::Show("你輸了，遊戲結束", "Gameover", MessageBoxButtons::OK);
					if (result == System::Windows::Forms::DialogResult::OK)
					{
						System::Windows::Forms::Application::Exit();
					}
				}
			}
		};
		
		void plot_HMI(void)
		{
			Bitmap^ buffer = gcnew Bitmap(this->Width, this->Height);
			Graphics^ e1 = Graphics::FromImage(buffer);

			e1->Clear(Color::WhiteSmoke);
			
			Pen^ pen_B = gcnew Pen(Color::Black, 2);

			int R_size = 20;
			int grid_width = 400;
			int grid_height = 400;
			int grid_resolution = 1;
			int shift_x = (grid_width / 2); //
			int shift_y = (grid_height)+0;
			int Y_shift = 0;
			
			e1->DrawLine(pen_B, 80, 240, 650, 240);
			e1->DrawLine(pen_B, 0, 180, 737, 180);
			e1->DrawLine(pen_B, 0, 180, 0, 480);
			e1->DrawLine(pen_B, 80, 240, 80, 480);
			e1->DrawLine(pen_B, 737, 180, 737, 480);
			e1->DrawLine(pen_B, 650, 240, 650, 480);
			delete pen_B;
			if(needmap)
			{
				needmap = false;
				String^ imageName = "地圖.jpg"; //決定要顯示哪張圖片
				PictureBox^ backgroundPictureBox = gcnew PictureBox();
				const int pictureBoxWidth = 250; // PictureBox 的寬度
				const int pictureBoxHeight = 100; // PictureBox 的高度
				backgroundPictureBox->Location = System::Drawing::Point(shift_x - 5, shift_y - 65);
				backgroundPictureBox->Size = System::Drawing::Size(pictureBoxWidth, pictureBoxHeight);
				backgroundPictureBox->Image = Image::FromFile(imageName); // 設定圖片路徑
				backgroundPictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
				

				this->Controls->Add(backgroundPictureBox);
			}
			
			for (int i = 0; i < 500; i++) {
				if (obs[i].point.HP > 0) {
					Lead_obs = i;
					break;
				}
			}
			for (int i = 0; i < 500; i++)
			{
				if (obs[i].point.HP <= 0)
				{
					obs[i].enable = 0;

				}
				else if (obs[i].enable == 1 && i % 10 != 0)
				{
					Pen^ pen_B = gcnew Pen(Color::Blue, 2);
					int x11 = (obs[i].pos.X) / grid_resolution;
					int y11 = (obs[i].pos.Y + Y_shift) / grid_resolution;
					e1->DrawRectangle(pen_B, shift_x + 0 + x11, shift_y - y11, 20, 20);
					String^ xStr = obs[i].point.HP.ToString(); // 取得變數 x 的字串形式
					e1->DrawString(xStr, gcnew System::Drawing::Font("Arial", 10), Brushes::Black, shift_x + 0 + x11, shift_y - y11);
					delete pen_B;
				}
				else if (obs[i].enable == 1 && i % 10 == 0)
				{
					Pen^ pen_C = gcnew Pen(Color::Red, 2);
					int x11 = (obs[i].pos.X) / grid_resolution;
					int y11 = (obs[i].pos.Y + Y_shift + 10) / grid_resolution;
					e1->DrawRectangle(pen_C, shift_x + 0 + x11, shift_y - y11, 20, 40);
					String^ xStr = obs[i].point.HP.ToString(); // 取得變數 x 的字串形式
					e1->DrawString(xStr, gcnew System::Drawing::Font("Arial", 10), Brushes::Black, shift_x + 0 + x11, shift_y - y11);
					delete pen_C;
				}
			}
			for (int i = 0; i < 10; i++)
			{
				if (dice[i].enable == 1)
				{
					if (dice[i].dice_no_picture)
					{
						dice[i].dice_no_picture = false;
						int x1 = (dice[i].pos.X) / grid_resolution;
						int y1 = (dice[i].pos.Y + Y_shift + 10) / grid_resolution;

						// 產生亂數種子
						srand((unsigned)time(NULL));
						// 產生一個1~6之間的亂數
						int dice_num = rand() % 6 + 1;
						String^ imageName = "dice" + dice_num + ".png"; //dice 點數決定要顯示哪張圖片
						PictureBox^ pictureBox = gcnew PictureBox();
						const int pictureBoxWidth = 40; // PictureBox 的寬度
						const int pictureBoxHeight = 40; // PictureBox 的高度

						pictureBox->Location = System::Drawing::Point(shift_x + 0 + x1, shift_y - y1);
						pictureBox->Size = System::Drawing::Size(pictureBoxWidth, pictureBoxHeight);
						pictureBox->Image = Image::FromFile(imageName); // 設定圖片路徑
						pictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // 設定圖片填充模式

						this->Controls->Add(pictureBox);
						pictureBox->BringToFront();
						switch (dice_num)
						{
						case 1:
							wea[i].point.HP -= 5;
							break;
						case 2:
							wea[i].Velocity *= 0.75;
							break;
						case 3:
							break;
						case 4:
							wea[i].point.HP += 5;
							break;
						case 5:
							wea[i].Velocity *= 1.5;
							break;
						case 6:
							wea[i].point.HP += 10;
							break;
						default:
							break;
						}
						MessageBox::Show("骰子骰出點數" + Convert::ToString(dice_num) + "\n初始攻擊" + Convert::ToString(wea[i].point.HP) + "\n初始速度" + Convert::ToString(wea[i].Velocity));
					}
				}
			}
			Pen^ pen_B5 = gcnew Pen(Color::Green, 10);///子彈顏色
			for (int i = 0; i < 10; i++)
			{
				if (wea[i].enable == 1)
				{
					R_size = wea[i].diameter;////子彈大小
					int x13 = (wea[i].pos.X) / grid_resolution;
					int y13 = (wea[i].pos.Y + Y_shift) / grid_resolution;
					e1->DrawEllipse(pen_B5, shift_x + x13 - R_size / 2, shift_y - y13 - R_size / 2, R_size, R_size);
					wea[i].pos.X += wea[i].V.Vx * dt;
					wea[i].pos.Y += wea[i].V.Vy * dt;
				}
			}
			delete pen_B5;



			if (nuc.enable == 1)
			{
				if (nuc.dice_no_picture) {
					nuc.dice_no_picture = false;
					String^ imageName = "nuclear.png"; //決定要顯示哪張圖片
					PictureBox^ pictureBox = gcnew PictureBox();
					const int pictureBoxWidth = 50; // PictureBox 的寬度
					const int pictureBoxHeight = 50; // PictureBox 的高度

					pictureBox->Location = System::Drawing::Point(300, 265);
					pictureBox->Size = System::Drawing::Size(pictureBoxWidth, pictureBoxHeight);
					pictureBox->Image = Image::FromFile(imageName); // 設定圖片路徑
					pictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // 設定圖片填充模式
					this->Controls->Add(pictureBox);
				}

			}
			if (frez.enable == 1)
			{
				if (frez.dice_no_picture) {
					frez.dice_no_picture = false;
					String^ imageName = "freeze.JFIF";
					PictureBox^ pictureBox = gcnew PictureBox();
					const int pictureBoxWidth = 50; // PictureBox 的寬度
					const int pictureBoxHeight = 50; // PictureBox 的高度

					pictureBox->Location = System::Drawing::Point(220, 265);
					pictureBox->Size = System::Drawing::Size(pictureBoxWidth, pictureBoxHeight);
					pictureBox->Image = Image::FromFile(imageName); // 設定圖片路徑
					pictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // 設定圖片填充模式

					// 將 pictureBox 添加到 Form1 的控制項集合中
					this->Controls->Add(pictureBox);
				}

			}
			if (wea1.enable == 1)
			{
				Pen^ pen_B7 = gcnew Pen(Color::Blue, 15);///子彈顏色
				int x1 = (wea1.pos.X) / grid_resolution;
				int y1 = (wea1.pos.Y + Y_shift) / grid_resolution;
				e1->DrawEllipse(pen_B7, shift_x + x1, shift_y - y1 - R_size / 2, R_size, R_size);
				wea1.pos.X += wea1.V.Vx * dt;
				wea1.pos.Y += wea1.V.Vy * dt;
				delete pen_B7;

			}
			if (wea2.enable == 1)
			{
				Pen^ pen_B7 = gcnew Pen(Color::Black, 15);///子彈顏色
				int x1 = (wea2.pos.X) / grid_resolution;
				int y1 = (wea2.pos.Y + Y_shift) / grid_resolution;
				e1->DrawEllipse(pen_B7, shift_x + x1, shift_y - y1 - R_size / 2, R_size, R_size);
				wea2.pos.X += wea2.V.Vx * dt;
				wea2.pos.Y += wea2.V.Vy * dt;
				delete pen_B7;
			}
			if (AOEdice.enable == 1)
			{
				if (AOEdice.dice_no_picture)
				{
					AOEdice.dice_no_picture = false;
					String^ imageName = "sun.jfif";
					PictureBox^ pictureBox = gcnew PictureBox();
					const int pictureBoxWidth = 50; // PictureBox 的寬度
					const int pictureBoxHeight = 50; // PictureBox 的高度

					pictureBox->Location = System::Drawing::Point(380, 265);
					pictureBox->Size = System::Drawing::Size(pictureBoxWidth, pictureBoxHeight);
					pictureBox->Image = Image::FromFile(imageName); // 設定圖片路徑
					pictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // 設定圖片填充模式
					// 將 pictureBox 添加到 Form1 的控制項集合中
					this->Controls->Add(pictureBox);
				}
			}
			if (AOE_wea.enable == 1)
			{
				Pen^ pen_B8 = gcnew Pen(Color::Red, 15);///顏色(子彈
				int x1 = (AOE_wea.pos.X) / grid_resolution;
				int y1 = (AOE_wea.pos.Y + Y_shift) / grid_resolution;
				e1->DrawEllipse(pen_B8, shift_x + x1, shift_y - y1 - R_size / 2, R_size, R_size);
				AOE_wea.pos.X += AOE_wea.V.Vx * dt;
				AOE_wea.pos.Y += AOE_wea.V.Vy * dt;
				delete pen_B8;
			}
			this->CreateGraphics()->DrawImage(buffer, Point(0, 0));
			delete e1;delete buffer;
		};
		void initialize(void)
		{
			dice->counter = 1;
			//AOE初始值設定
			AOEdice.pos.X = 160;
			AOEdice.pos.Y = 120;
			AOE_wea.Velocity = 80;
			AOE_wea.point.HP = 10;
			AOE_wea.enable = 0;
			AOEdice.enable = 0;

			nuc.pos.X = 80;
			nuc.pos.Y = 120;
			frez.pos.X = 50;
			frez.pos.Y = 120;
			wea2.Velocity = 25;
			wea1.Velocity = 25;
			nuc.enable = 0;
			wea2.enable = 0;
			wea1.enable = 0;
			frez.enable = 0;
			obs[0].enable = 1;
			wea->point.HP = 10;
			for (int i = 0; i < 500; i++)/////控制敵人數量
			{

				obs[i].pos.X = -175;
				obs[i].pos.Y = 0;
				obs[i].V.Vx = 0;
				obs[i].V.Vy = 10;
				if (i % 10 != 0)
				{
					obs[i].point.HP = 30 + (i / 10) * 10;

				}
				else
				{
					obs[i].point.HP = 100 * ((i / 10 + 1));

				}


			}
			for (int i = 0; i < 10; i++)
			{
				wea[i].Velocity = 120;
				wea[i].point.HP = 10;
				dice[i].pos.X = 0 + 50 * i;
				dice[i].pos.Y = 50;
				dice[i].point.HP = 20;
				if (i >= 5 && i < 10)
				{
					dice[i].pos.X = 0 + 50 * (i - 5);
					dice[i].pos.Y = -0;
					dice[i].point.HP = 20;
				}

			}


		};
		void text_displayer(void)///顯示生命條、技能條等
		{
			String^ str = gcnew String(dice->name);
			this->progressBar1->Value = dice->point.MP;
			this->label1->Text = ("MP:" + Convert::ToString(dice->point.MP) + "/10000");
		};
		void dice_attack()
		{
			for (int i = 0; i < 10; i++)
			{
				// 確認大魔王能力已經啟用，並且子彈還沒有啟用
				if (dice[i].enable == 1 && wea[i].enable == 0)
				{
					wea[i].pos.Theta = atan2(obs[Lead_obs].pos.Y - dice[i].pos.Y, obs[Lead_obs].pos.X - dice[i].pos.X);
					wea[i].pos.X = dice[i].pos.X + wea[i].diameter * cos(wea[i].pos.Theta);
					wea[i].pos.Y = dice[i].pos.Y + wea[i].diameter * sin(wea[i].pos.Theta);
					wea[i].V.Vx = wea[i].Velocity * cos(wea[i].pos.Theta);
					wea[i].V.Vy = wea[i].Velocity * sin(wea[i].pos.Theta);
					// 啟用攻擊行為
					wea[i].enable = 1;
				}
				
			}
			for (int j = 0; j < 500; j++)//////frez dice
			{
				// 確認大魔王能力已經啟用，並且子彈還沒有啟用
				if (frez.enable == 1 && wea1.enable == 0 && obs[j].point.HP > 0 && obs[j].enable == 1)
				{
					wea1.pos.Theta = atan2(obs[j].pos.Y - frez.pos.Y, obs[j].pos.X - frez.pos.X);
					wea1.pos.X = frez.pos.X + wea1.diameter * cos(wea1.pos.Theta);
					wea1.pos.Y = frez.pos.Y + wea1.diameter * sin(wea1.pos.Theta);
					wea1.V.Vx = wea1.Velocity * cos(wea1.pos.Theta);
					wea1.V.Vy = wea1.Velocity * sin(wea1.pos.Theta);
					wea1.enable = 1;
				}
				else if (wea1.enable == 1)
				{
					if (wea1.pos.Y > 200 || wea1.pos.X < -175 || wea1.pos.X> 480)
					{
						wea1.enable == 0;
					}
				}
			}
			for (int j = 0; j < 500; j++)
			{
				// 確認大魔王能力已經啟用，並且子彈還沒有啟用
				if (nuc.enable == 1 && wea2.enable == 0 && obs[j].point.HP > 0 && obs[j].enable == 1)
				{
					wea2.pos.Theta = atan2(obs[j].pos.Y - nuc.pos.Y, obs[j].pos.X - nuc.pos.X);
					wea2.pos.X = nuc.pos.X + wea2.diameter * cos(wea2.pos.Theta);
					wea2.pos.Y = nuc.pos.Y + wea2.diameter * sin(wea2.pos.Theta);
					wea2.V.Vx = wea2.Velocity * cos(wea2.pos.Theta);
					wea2.V.Vy = wea2.Velocity * sin(wea2.pos.Theta);
					wea2.enable = 1;
				}
				else if (wea2.enable == 1)
				{
					if (wea2.pos.Y > 250 || wea2.pos.X < -205 || wea2.pos.X> 500)
					{
						wea2.enable = 0;
					}
				}				
			}
			//範圍攻擊骰子
			if (AOEdice.enable == 1 && AOE_wea.enable == 0 && obs[Lead_obs].enable == 1)
			{
				AOE_wea.pos.Theta = atan2(obs[Lead_obs].pos.Y - AOEdice.pos.Y, obs[Lead_obs].pos.X - AOEdice.pos.X);
				AOE_wea.pos.X = AOEdice.pos.X + AOE_wea.diameter * cos(AOE_wea.pos.Theta);
				AOE_wea.pos.Y = AOEdice.pos.Y + AOE_wea.diameter * sin(AOE_wea.pos.Theta);
				AOE_wea.V.Vx = AOE_wea.Velocity * cos(AOE_wea.pos.Theta);
				AOE_wea.V.Vy = AOE_wea.Velocity * sin(AOE_wea.pos.Theta);
				AOE_wea.enable = 1;
			}
			else if (AOE_wea.enable == 1)
			{
				if (AOE_wea.pos.Y > 200 || AOE_wea.pos.X < -175 || AOE_wea.pos.X> 480)
				{
					AOE_wea.enable == 0;
				}
			}
		};
		void collsion_detection(void)////跟子彈和敵人碰撞
		{
			for (int i = 0; i < 10; i++)
			{
				float dis = sqrt(pow(obs[Lead_obs].pos.X - wea[i].pos.X,2) + pow(obs[Lead_obs].pos.Y - wea[i].pos.Y,2) );
				if (dis < wea[i].diameter *2.5 && wea[i].enable == 1)////如果子彈碰到敵人就扣血並且子彈消失
				{
					wea[i].enable = 0;
					obs[Lead_obs].point.HP = obs[Lead_obs].point.HP - wea[i].point.HP;
				}
				//子彈沒打到超過某範圍就重設
				else if (dis > 400 && wea[i].enable == 1) {
					wea[i].enable = 0;
				}
			}


			bool nuclearCollide = false;

			for (int j = 0; j < 500; j++)
			{
				float dis = sqrt(pow(obs[j].pos.X - wea2.pos.X,2) + pow(obs[j].pos.Y - wea2.pos.Y,2));
				if (dis < wea2.diameter * 2.1 && wea2.enable == 1 && wea2.counter > 0)
				{
					nuclearCollide = true;
					wea2.enable = 0;
					obs[j].collide = 1;
					break; // 找到碰撞後，中斷迴圈，不再檢查其他敵人
				}
				else if (dis > 400 && wea2.enable == 1) {
					wea2.enable = 0;
				}
			}
			if (nuclearCollide)
			{
				for (int j = 0; j < 500; j++)
				{
					if (obs[j].enable == 1 && obs[j].pos.Y > 25)
					{
						obs[j].point.HP -= 200;
						nuclearCollide = false;
					}
				}
			}

			static bool collisionDetected = false;
			static std::chrono::steady_clock::time_point collisionTime;

			for (int j = 0; j < 500; j++)/////寒冰骰
			{
				// Collision between wea1 and obs[j]
				float dis = sqrt((obs[j].pos.X - wea1.pos.X) * (obs[j].pos.X - wea1.pos.X) + (obs[j].pos.Y - wea1.pos.Y) * (obs[j].pos.Y - wea1.pos.Y));
				if (dis < wea1.diameter * 2 && wea1.enable == 1 && wea1.counter > 0)
				{
					collisionDetected = true;
					wea1.enable = 0;
					wea1.counter--;
					collisionTime = std::chrono::steady_clock::now(); // Store the current time
				}

				if (collisionDetected)
				{
					std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
					std::chrono::duration<double> elapsedSeconds = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - collisionTime);

					if (elapsedSeconds.count() >= 1.0) // Change the duration here as needed (1.0 represents 1 second)
					{
						collisionDetected = false;
						if (obs[j].pos.X >= 480 && obs[j].pos.Y <= 200)
						{
							obs[j].V.Vx = 0;
							obs[j].V.Vy = -obs_y_velocity;
						}
						else if (obs[j].pos.X >= -175 && obs[j].pos.Y == 200)
						{
							obs[j].V.Vx = obs_x_velocity;
							obs[j].V.Vy = 0;
						}
						else
						{
							obs[j].V.Vx = 0;
							obs[j].V.Vy = obs_y_velocity;
						}
					}
					else
					{
						obs[j].V.Vx = 0;
						obs[j].V.Vy = 0;

					}
				}
				else
				{
					if (obs[j].pos.X >= 480)
					{
						obs[j].V.Vx = 0;
						obs[j].V.Vy = -obs_y_velocity;
					}
					else if (obs[j].pos.X >= -175 && obs[j].pos.Y >= 200)
					{
						obs[j].V.Vx = obs_x_velocity;
						obs[j].V.Vy = 0;
					}
					else if (obs[j].pos.X == -175)
					{
						obs[j].V.Vx = 0;
						obs[j].V.Vy = obs_y_velocity;
					}

				}
			}
			for (int j = 0; j < 500; j++)
			{
				float AOE_dis = sqrt(pow(obs[j].pos.X - AOE_wea.pos.X, 2) + pow(obs[j].pos.Y - AOE_wea.pos.Y, 2));
				bool need_finish_AOE = false;
				static bool AOEcollisionDetected = false;
				static std::chrono::steady_clock::time_point AOEcollisionTime;
				if (AOE_dis < AOE_wea.diameter * 2 && AOE_wea.enable == 1)
				{
					AOE_wea.enable = 0;
					AOEcollisionDetected = true;

					//MessageBox::Show("撞到了");
					AOEcollisionTime = std::chrono::steady_clock::now(); // Store the current time

					need_finish_AOE = true;
				}

				if (AOEcollisionDetected)
				{
					Brush^ brush = gcnew SolidBrush(Color::GreenYellow);
					int x1 = (obs[Lead_obs].pos.X);
					int y1 = (obs[Lead_obs].pos.Y);
					Graphics^ e1 = this->CreateGraphics();
					int shift_x = 200, shift_y = 400;
					int AOE_R_size = 110;
					e1->FillEllipse(brush, shift_x + x1 - AOE_R_size / 2, shift_y - y1 - AOE_R_size / 2, AOE_R_size, AOE_R_size);
					delete brush;
					if (need_finish_AOE)
					{
						for (int index = 0; index < AOE_R_size / obs_distance; index++) {
							//AOE 傷害
							obs[Lead_obs + index].point.HP = obs[Lead_obs + index].point.HP - AOE_wea.point.HP;
						}
						need_finish_AOE = false;
						AOEcollisionDetected = false;
					}
				}
			}
		};

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (system_counter == 0)
		{
			initialize();
		}
		dice->point.MP = dice->point.MP + 1;
		Motion_model();
		plot_HMI();
		text_displayer();
		dice_attack();
		collsion_detection();
		this->DoubleBuffered = true;
		system_counter++;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		for (int i = 0; i < 10; i++)
		{
			if (dice[i].enable == 0 && dice->point.MP >= 20)
			{
				dice[i].enable = 1;
				dice->point.MP = dice->point.MP - 20;
				break;
			}

		}

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dice->point.MP > 30)
		{

			for (int i = 0; i < 10; i++)
			{
				wea[i].point.HP = wea[i].point.HP + 3;
				label4->Text = "Power：" + wea[i].point.HP.ToString();
			}
			dice->point.MP = dice->point.MP - 30;
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dice->point.MP > 30 + 5 * dice->counter)
		{
			for (int i = 0; i < 10; i++)
			{
				wea[i].Velocity = wea[i].Velocity + 3;
				label3->Text = "Velocity：" + wea[i].Velocity.ToString();
			}
			dice->point.MP = dice->point.MP - (30 + 5 * dice->counter);
			dice->counter++;
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (frez.enable == 0 && dice->point.MP >= 100)
		{
			frez.enable = 1;
			dice->point.MP = dice->point.MP - 100;
		}

	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (nuc.enable == 0 && dice->point.MP >= 500)
		{
			nuc.enable = 1;
			dice->point.MP = dice->point.MP - 500;
		}
	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (AOEdice.enable == 0 && dice->point.MP >= 100)
		{
			AOEdice.enable = 1;
			dice->point.MP = dice->point.MP - 100;
		}

	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < 10; i++)
		{

			label3->Text = "Velasity：" + wea[i].Velocity.ToString();
		}
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < 10; i++)
		{

			label3->Text = "Power：" + wea[i].point.HP.ToString();
		}
	}
	};
}
