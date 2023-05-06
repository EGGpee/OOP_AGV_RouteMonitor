#pragma once
#include"Model.h"
#include"MessageForm.h"

namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Map 的摘要
	/// </summary>
	public ref class Map : public System::Windows::Forms::Form
	{
	public:
		Graphics^ graph;
		Position* information;
		Pen^ usingPen;
		List<PointF>^ lines;
		PointF^ start;
		PointF^ end;

	private: System::Windows::Forms::Button^ buttonStop;
	private: System::Windows::Forms::Panel^ panelMap;
	private: System::Windows::Forms::PictureBox^ pictureAGV;
	private: System::Windows::Forms::Button^ buttonReset;
	private: System::Windows::Forms::Button^ buttonClear;


	public:
		Map(void)
		{
			InitializeComponent();
			information = new Position();
			usingPen = gcnew Pen(Color::Blue, 2);
			pictureAGV->Image = pictureAGV->Image->FromFile("\AGV.jpg");
			graph = panelMap->CreateGraphics();
			PointF^ start = gcnew PointF(0, 0);
			PointF^ end = gcnew PointF();
			lines = gcnew List<PointF>();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Map()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelInfo;
	private: System::Windows::Forms::Label^ labelPosXNow;
	private: System::Windows::Forms::TextBox^ textBoxDestinationX;
	private: System::Windows::Forms::Button^ buttonStartDraw;
	private: System::Windows::Forms::Button^ buttonUpdate;
	private: System::Windows::Forms::Label^ labelPosYNow;

	private: System::Windows::Forms::Label^ labelDestinationY;
	private: System::Windows::Forms::Label^ labelDestinationX;
	private: System::Windows::Forms::TextBox^ textBoxDestinationY;
	private: System::Windows::Forms::RadioButton^ radioButtonShortestPath;
	private: System::Windows::Forms::RadioButton^ radioButtonVerticalPath;
	private: System::Windows::Forms::TextBox^ textBoxSpeed;
	private: System::Windows::Forms::Label^ labelSpeed;


	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Map::typeid));
			this->panelInfo = (gcnew System::Windows::Forms::Panel());
			this->radioButtonShortestPath = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonVerticalPath = (gcnew System::Windows::Forms::RadioButton());
			this->textBoxSpeed = (gcnew System::Windows::Forms::TextBox());
			this->labelSpeed = (gcnew System::Windows::Forms::Label());
			this->textBoxDestinationY = (gcnew System::Windows::Forms::TextBox());
			this->labelDestinationY = (gcnew System::Windows::Forms::Label());
			this->labelDestinationX = (gcnew System::Windows::Forms::Label());
			this->textBoxDestinationX = (gcnew System::Windows::Forms::TextBox());
			this->buttonStartDraw = (gcnew System::Windows::Forms::Button());
			this->buttonUpdate = (gcnew System::Windows::Forms::Button());
			this->labelPosYNow = (gcnew System::Windows::Forms::Label());
			this->labelPosXNow = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->panelMap = (gcnew System::Windows::Forms::Panel());
			this->pictureAGV = (gcnew System::Windows::Forms::PictureBox());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->panelInfo->SuspendLayout();
			this->panelMap->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureAGV))->BeginInit();
			this->SuspendLayout();
			// 
			// panelInfo
			// 
			this->panelInfo->Controls->Add(this->radioButtonShortestPath);
			this->panelInfo->Controls->Add(this->radioButtonVerticalPath);
			this->panelInfo->Controls->Add(this->textBoxSpeed);
			this->panelInfo->Controls->Add(this->labelSpeed);
			this->panelInfo->Controls->Add(this->textBoxDestinationY);
			this->panelInfo->Controls->Add(this->labelDestinationY);
			this->panelInfo->Controls->Add(this->labelDestinationX);
			this->panelInfo->Controls->Add(this->textBoxDestinationX);
			this->panelInfo->Controls->Add(this->buttonStartDraw);
			this->panelInfo->Controls->Add(this->buttonUpdate);
			this->panelInfo->Controls->Add(this->labelPosYNow);
			this->panelInfo->Controls->Add(this->labelPosXNow);
			this->panelInfo->Location = System::Drawing::Point(13, 13);
			this->panelInfo->Name = L"panelInfo";
			this->panelInfo->Size = System::Drawing::Size(759, 98);
			this->panelInfo->TabIndex = 0;
			// 
			// radioButtonShortestPath
			// 
			this->radioButtonShortestPath->AutoSize = true;
			this->radioButtonShortestPath->Checked = true;
			this->radioButtonShortestPath->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->radioButtonShortestPath->Location = System::Drawing::Point(418, 49);
			this->radioButtonShortestPath->Name = L"radioButtonShortestPath";
			this->radioButtonShortestPath->Size = System::Drawing::Size(103, 20);
			this->radioButtonShortestPath->TabIndex = 11;
			this->radioButtonShortestPath->TabStop = true;
			this->radioButtonShortestPath->Text = L"ShortestPath";
			this->radioButtonShortestPath->UseVisualStyleBackColor = true;
			// 
			// radioButtonVerticalPath
			// 
			this->radioButtonVerticalPath->AutoSize = true;
			this->radioButtonVerticalPath->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->radioButtonVerticalPath->Location = System::Drawing::Point(418, 75);
			this->radioButtonVerticalPath->Name = L"radioButtonVerticalPath";
			this->radioButtonVerticalPath->Size = System::Drawing::Size(102, 20);
			this->radioButtonVerticalPath->TabIndex = 10;
			this->radioButtonVerticalPath->Text = L"VerticalPath";
			this->radioButtonVerticalPath->UseVisualStyleBackColor = true;
			// 
			// textBoxSpeed
			// 
			this->textBoxSpeed->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBoxSpeed->Location = System::Drawing::Point(482, 14);
			this->textBoxSpeed->Name = L"textBoxSpeed";
			this->textBoxSpeed->Size = System::Drawing::Size(103, 33);
			this->textBoxSpeed->TabIndex = 9;
			this->textBoxSpeed->Text = L"0";
			this->textBoxSpeed->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// labelSpeed
			// 
			this->labelSpeed->AutoSize = true;
			this->labelSpeed->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->labelSpeed->Location = System::Drawing::Point(414, 17);
			this->labelSpeed->Name = L"labelSpeed";
			this->labelSpeed->Size = System::Drawing::Size(64, 21);
			this->labelSpeed->TabIndex = 8;
			this->labelSpeed->Text = L"Speed:";
			// 
			// textBoxDestinationY
			// 
			this->textBoxDestinationY->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBoxDestinationY->Location = System::Drawing::Point(305, 56);
			this->textBoxDestinationY->Name = L"textBoxDestinationY";
			this->textBoxDestinationY->Size = System::Drawing::Size(103, 33);
			this->textBoxDestinationY->TabIndex = 7;
			this->textBoxDestinationY->Text = L"0";
			this->textBoxDestinationY->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// labelDestinationY
			// 
			this->labelDestinationY->AutoSize = true;
			this->labelDestinationY->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->labelDestinationY->Location = System::Drawing::Point(175, 59);
			this->labelDestinationY->Name = L"labelDestinationY";
			this->labelDestinationY->Size = System::Drawing::Size(124, 21);
			this->labelDestinationY->TabIndex = 6;
			this->labelDestinationY->Text = L"Destination Y:";
			// 
			// labelDestinationX
			// 
			this->labelDestinationX->AutoSize = true;
			this->labelDestinationX->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->labelDestinationX->Location = System::Drawing::Point(175, 17);
			this->labelDestinationX->Name = L"labelDestinationX";
			this->labelDestinationX->Size = System::Drawing::Size(124, 21);
			this->labelDestinationX->TabIndex = 5;
			this->labelDestinationX->Text = L"Destination X:";
			// 
			// textBoxDestinationX
			// 
			this->textBoxDestinationX->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBoxDestinationX->Location = System::Drawing::Point(305, 14);
			this->textBoxDestinationX->Name = L"textBoxDestinationX";
			this->textBoxDestinationX->Size = System::Drawing::Size(103, 33);
			this->textBoxDestinationX->TabIndex = 4;
			this->textBoxDestinationX->Text = L"0";
			this->textBoxDestinationX->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// buttonStartDraw
			// 
			this->buttonStartDraw->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->buttonStartDraw->Location = System::Drawing::Point(591, 52);
			this->buttonStartDraw->Name = L"buttonStartDraw";
			this->buttonStartDraw->Size = System::Drawing::Size(151, 34);
			this->buttonStartDraw->TabIndex = 3;
			this->buttonStartDraw->Text = L"Start Drawing";
			this->buttonStartDraw->UseVisualStyleBackColor = true;
			this->buttonStartDraw->Click += gcnew System::EventHandler(this, &Map::buttonStartDraw_Click);
			// 
			// buttonUpdate
			// 
			this->buttonUpdate->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->buttonUpdate->Location = System::Drawing::Point(591, 9);
			this->buttonUpdate->Name = L"buttonUpdate";
			this->buttonUpdate->Size = System::Drawing::Size(151, 37);
			this->buttonUpdate->TabIndex = 2;
			this->buttonUpdate->Text = L"Update";
			this->buttonUpdate->UseVisualStyleBackColor = true;
			this->buttonUpdate->Click += gcnew System::EventHandler(this, &Map::buttonUpdate_Click);
			// 
			// labelPosYNow
			// 
			this->labelPosYNow->AutoSize = true;
			this->labelPosYNow->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->labelPosYNow->Location = System::Drawing::Point(3, 59);
			this->labelPosYNow->Name = L"labelPosYNow";
			this->labelPosYNow->Size = System::Drawing::Size(108, 21);
			this->labelPosYNow->TabIndex = 1;
			this->labelPosYNow->Text = L"Position Y:0";
			// 
			// labelPosXNow
			// 
			this->labelPosXNow->AutoSize = true;
			this->labelPosXNow->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->labelPosXNow->Location = System::Drawing::Point(3, 17);
			this->labelPosXNow->Name = L"labelPosXNow";
			this->labelPosXNow->Size = System::Drawing::Size(108, 21);
			this->labelPosXNow->TabIndex = 0;
			this->labelPosXNow->Text = L"Position X:0";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Map::timer1_Tick);
			// 
			// buttonStop
			// 
			this->buttonStop->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->buttonStop->Location = System::Drawing::Point(637, 117);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(135, 30);
			this->buttonStop->TabIndex = 2;
			this->buttonStop->Text = L"Stop";
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &Map::buttonStop_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->buttonClear->Location = System::Drawing::Point(495, 117);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(135, 30);
			this->buttonClear->TabIndex = 3;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Map::buttonClear_Click);
			// 
			// panelMap
			// 
			this->panelMap->BackColor = System::Drawing::Color::White;
			this->panelMap->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelMap->Controls->Add(this->pictureAGV);
			this->panelMap->Location = System::Drawing::Point(15, 150);
			this->panelMap->Name = L"panelMap";
			this->panelMap->Size = System::Drawing::Size(750, 600);
			this->panelMap->TabIndex = 4;
			this->panelMap->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Map::panelMap_Paint);
			// 
			// pictureAGV
			// 
			this->pictureAGV->BackColor = System::Drawing::Color::White;
			this->pictureAGV->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureAGV.ErrorImage")));
			this->pictureAGV->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureAGV.InitialImage")));
			this->pictureAGV->Location = System::Drawing::Point(-20, -25);
			this->pictureAGV->Name = L"pictureAGV";
			this->pictureAGV->Size = System::Drawing::Size(40, 50);
			this->pictureAGV->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureAGV->TabIndex = 0;
			this->pictureAGV->TabStop = false;
			// 
			// buttonReset
			// 
			this->buttonReset->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->buttonReset->Location = System::Drawing::Point(356, 117);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(135, 30);
			this->buttonReset->TabIndex = 5;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &Map::buttonReset_Click);
			// 
			// Map
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 761);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->panelMap);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonStop);
			this->Controls->Add(this->panelInfo);
			this->Name = L"Map";
			this->Text = L"Map";
			this->panelInfo->ResumeLayout(false);
			this->panelInfo->PerformLayout();
			this->panelMap->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureAGV))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		start = PointF(information->getValue(0), information->getValue(1));
		if (lines->Count == 0) {
			lines->Add(*start);
		}

		if (information->updatePosition()) {
			end = PointF(information->getValue(0), information->getValue(1));
			lines->Add(*end);
			labelPosXNow->Text = "Position X:" + end->X.ToString();
			labelPosYNow->Text = "Position Y:" + end->Y.ToString();
			pictureAGV->Location = Point(end->X-20 ,end->Y-25);
			graph->DrawLine(usingPen, *start, *end);
		}
		else {
			timer1->Enabled = false;
			MessageForm^ form = gcnew MessageForm('s');
			form->Show();
		}
	}

	private: System::Void buttonUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBoxSpeed->Text == "0" || System::Convert::ToDouble(textBoxDestinationX->Text) < 0 || System::Convert::ToDouble(textBoxDestinationX->Text) > 750 ||
			System::Convert::ToDouble(textBoxDestinationY->Text) < 0 || System::Convert::ToDouble(textBoxDestinationY->Text) > 600) {
			MessageForm^ form = gcnew MessageForm('e');
			form->Show();
		}
		else {
			information->updateInformation(information->getValue(0), information->getValue(1), System::Convert::ToDouble(textBoxDestinationX->Text), System::Convert::ToDouble(textBoxDestinationY->Text), System::Convert::ToDouble(textBoxSpeed->Text), radioButtonShortestPath->Checked);
		}
	}

	private: System::Void buttonStop_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
	}

	private: System::Void buttonStartDraw_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = true;
	}
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
		graph->Clear(Color::White);
		lines->Clear();
	}
	private: System::Void panelMap_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (lines->Count > 1)
		{
			e->Graphics->DrawLines(usingPen, lines->ToArray());
		}
	}
	private: System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		graph->Clear(Color::White);
		lines->Clear();
		information->updateInformation(0, 0, 0, 0, 0, true);
		labelPosXNow->Text = "Position X:" + end->X.ToString();
		labelPosYNow->Text = "Position Y:" + end->Y.ToString();
		pictureAGV->Location = Point(-20,- 25);

	}
};
}
