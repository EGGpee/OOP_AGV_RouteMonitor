#pragma once

namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MessageForm 的摘要
	/// </summary>
	public ref class MessageForm : public System::Windows::Forms::Form
	{
	public:
		MessageForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
		MessageForm(char c) {
			InitializeComponent();
			if (c == 'e') {
				labelMessage->Text = "Input Wrong Data!";
			}
			else if (c == 's') {
				labelMessage->Text = "Arrived!";
			}
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MessageForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelMessage;
	private: System::Windows::Forms::Button^ buttonOK;
	protected:

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelMessage = (gcnew System::Windows::Forms::Label());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelMessage
			// 
			this->labelMessage->AutoSize = true;
			this->labelMessage->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->labelMessage->Location = System::Drawing::Point(78, 93);
			this->labelMessage->Name = L"labelMessage";
			this->labelMessage->Size = System::Drawing::Size(119, 21);
			this->labelMessage->TabIndex = 0;
			this->labelMessage->Text = L"labelMessage";
			this->labelMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonOK
			// 
			this->buttonOK->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->buttonOK->Location = System::Drawing::Point(102, 183);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(75, 48);
			this->buttonOK->TabIndex = 1;
			this->buttonOK->Text = L"OK!";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &MessageForm::buttonOK_Click);
			// 
			// MessageForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->labelMessage);
			this->Name = L"MessageForm";
			this->Text = L"MessageForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
