#pragma once

namespace OndaSenoidal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btIniciar;
	protected:
	private: System::Windows::Forms::Button^ btParar;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ grafico;


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->btIniciar = (gcnew System::Windows::Forms::Button());
			this->btParar = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->grafico = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grafico))->BeginInit();
			this->SuspendLayout();
			// 
			// btIniciar
			// 
			this->btIniciar->Location = System::Drawing::Point(12, 12);
			this->btIniciar->Name = L"btIniciar";
			this->btIniciar->Size = System::Drawing::Size(75, 23);
			this->btIniciar->TabIndex = 0;
			this->btIniciar->Text = L"Iniciar";
			this->btIniciar->UseVisualStyleBackColor = true;
			this->btIniciar->Click += gcnew System::EventHandler(this, &MyForm::btIniciar_Click);
			// 
			// btParar
			// 
			this->btParar->Location = System::Drawing::Point(93, 12);
			this->btParar->Name = L"btParar";
			this->btParar->Size = System::Drawing::Size(75, 23);
			this->btParar->TabIndex = 1;
			this->btParar->Text = L"Parar";
			this->btParar->UseVisualStyleBackColor = true;
			this->btParar->Click += gcnew System::EventHandler(this, &MyForm::btParar_Click);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// grafico
			// 
			chartArea1->Name = L"ChartArea1";
			this->grafico->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->grafico->Legends->Add(legend1);
			this->grafico->Location = System::Drawing::Point(12, 41);
			this->grafico->Name = L"grafico";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"Onda";
			this->grafico->Series->Add(series1);
			this->grafico->Size = System::Drawing::Size(546, 426);
			this->grafico->TabIndex = 2;
			this->grafico->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(570, 479);
			this->Controls->Add(this->grafico);
			this->Controls->Add(this->btParar);
			this->Controls->Add(this->btIniciar);
			this->Name = L"MyForm";
			this->Text = L"Grafico";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grafico))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		int contador;
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		contador++;
		double seno = Math::Sin(contador);
		grafico->Series["Onda"]->Points->AddXY(Convert::ToString(contador), seno);
		Refresh();
		if (grafico->Series["Onda"]->Points->Count > 20)
		{
			grafico->Series["Onda"]->Points->RemoveAt(0);
		}
	}
	private: System::Void btIniciar_Click(System::Object^ sender, System::EventArgs^ e) {
		timer->Enabled = true;
	}
	private: System::Void btParar_Click(System::Object^ sender, System::EventArgs^ e) {
		timer->Enabled = false;
	}
};
}
