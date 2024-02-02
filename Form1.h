#pragma once
#include "pch.h"

namespace WinForms {

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
			//TODO: Add constructor code here.
			//
		}

	protected:
		/// <summary>
		/// Clean up used resources.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ testControl;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for designer support.
		/// The content of the method must not be changed using the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->testControl = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// testControl
			// 
			this->testControl->Location = System::Drawing::Point(238, 220);
			this->testControl->Name = L"testControl";
			this->testControl->Size = System::Drawing::Size(136, 23);
			this->testControl->TabIndex = 0;
			this->testControl->Text = L"Insert new user";
			this->testControl->UseVisualStyleBackColor = true;
			this->testControl->Click += gcnew System::EventHandler(this, &Form1::testControl_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 420);
			this->Controls->Add(this->testControl);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void testControl_Click(System::Object^ sender, System::EventArgs^ e) {
		// Run the "main" function
		main_();
	}
	};
}
