#include "Debug.h"

//(*InternalHeaders(Debug)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Debug)
const long Debug::ID_TEXTCTRL1 = wxNewId();
const long Debug::ID_PANEL2 = wxNewId();
const long Debug::ID_BUTTON1 = wxNewId();
const long Debug::ID_BUTTON2 = wxNewId();
const long Debug::ID_BUTTON3 = wxNewId();
const long Debug::ID_BUTTON4 = wxNewId();
const long Debug::ID_BUTTON5 = wxNewId();
const long Debug::ID_BUTTON6 = wxNewId();
const long Debug::ID_COMBOBOX1 = wxNewId();
const long Debug::ID_STATICTEXT1 = wxNewId();
const long Debug::ID_BUTTON7 = wxNewId();
const long Debug::ID_COMBOBOX2 = wxNewId();
const long Debug::ID_STATICTEXT2 = wxNewId();
const long Debug::ID_BUTTON8 = wxNewId();
const long Debug::ID_COMBOBOX3 = wxNewId();
const long Debug::ID_COMBOBOX4 = wxNewId();
const long Debug::ID_COMBOBOX5 = wxNewId();
const long Debug::ID_COMBOBOX6 = wxNewId();
const long Debug::ID_COMBOBOX7 = wxNewId();
const long Debug::ID_STATICTEXT3 = wxNewId();
const long Debug::ID_STATICTEXT4 = wxNewId();
const long Debug::ID_STATICTEXT5 = wxNewId();
const long Debug::ID_STATICTEXT6 = wxNewId();
const long Debug::ID_BUTTON9 = wxNewId();
const long Debug::ID_BUTTON10 = wxNewId();
const long Debug::ID_BUTTON11 = wxNewId();
const long Debug::ID_BUTTON12 = wxNewId();
const long Debug::ID_BUTTON13 = wxNewId();
const long Debug::ID_BUTTON14 = wxNewId();
const long Debug::ID_BUTTON15 = wxNewId();
const long Debug::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Debug,wxFrame)
	//(*EventTable(Debug)
	//*)
END_EVENT_TABLE()

Debug::Debug(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	debugCircuito = new Circuit();
	debug = new _Debug();

	//(*Initialize(Debug)
	Create(parent, wxID_ANY, _("Debug"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(800,600));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(64,64), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(8,320), wxSize(496,272), wxBORDER_DOUBLE, _T("ID_PANEL2"));
	TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,8), wxSize(479,247), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("AND"), wxPoint(16,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("OR"), wxPoint(16,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("NOT"), wxPoint(16,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button4 = new wxButton(Panel1, ID_BUTTON4, _("NAND"), wxPoint(104,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button5 = new wxButton(Panel1, ID_BUTTON5, _("NOR"), wxPoint(104,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	Button6 = new wxButton(Panel1, ID_BUTTON6, _("Lista Operadores"), wxPoint(16,160), wxSize(168,34), 0, wxDefaultValidator, _T("ID_BUTTON6"));
	ComboBox1 = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxPoint(280,16), wxSize(95,30), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	ComboBox1->SetSelection( ComboBox1->Append(_("0")) );
	ComboBox1->Append(_("1"));
	ComboBox1->Append(_("2"));
	ComboBox1->Append(_("3"));
	ComboBox1->Append(_("4"));
	ComboBox1->Append(_("5"));
	ComboBox1->Append(_("6"));
	ComboBox1->Append(_("7"));
	ComboBox1->Append(_("8"));
	ComboBox1->Append(_("9"));
	ComboBox1->Append(_("10"));
	ComboBox1->Append(_("11"));
	ComboBox1->Append(_("12"));
	ComboBox1->Append(_("13"));
	ComboBox1->Append(_("14"));
	ComboBox1->Append(_("15"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Indice"), wxPoint(216,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	Button7 = new wxButton(Panel1, ID_BUTTON7, _("Lista Sinais I/O"), wxPoint(216,56), wxSize(160,34), 0, wxDefaultValidator, _T("ID_BUTTON7"));
	ComboBox2 = new wxComboBox(Panel1, ID_COMBOBOX2, wxEmptyString, wxPoint(472,16), wxSize(136,30), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
	ComboBox2->SetSelection( ComboBox2->Append(_("INICIO")) );
	ComboBox2->Append(_("FIM"));
	ComboBox2->Append(_("LIGACAO"));
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Conector"), wxPoint(408,64), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	Button8 = new wxButton(Panel1, ID_BUTTON8, _("Adicionar"), wxPoint(624,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	ComboBox3 = new wxComboBox(Panel1, ID_COMBOBOX3, wxEmptyString, wxPoint(472,56), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
	ComboBox3->SetSelection( ComboBox3->Append(_("0")) );
	ComboBox3->Append(_("1"));
	ComboBox3->Append(_("2"));
	ComboBox3->Append(_("3"));
	ComboBox3->Append(_("4"));
	ComboBox3->Append(_("5"));
	ComboBox3->Append(_("6"));
	ComboBox3->Append(_("7"));
	ComboBox3->Append(_("8"));
	ComboBox3->Append(_("9"));
	ComboBox3->Append(_("10"));
	ComboBox3->Append(_("11"));
	ComboBox3->Append(_("12"));
	ComboBox3->Append(_("13"));
	ComboBox3->Append(_("14"));
	ComboBox3->Append(_("15"));
	ComboBox4 = new wxComboBox(Panel1, ID_COMBOBOX4, wxEmptyString, wxPoint(472,96), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX4"));
	ComboBox4->Append(_("-1"));
	ComboBox4->Append(_("0"));
	ComboBox4->Append(_("1"));
	ComboBox4->Append(_("2"));
	ComboBox4->Append(_("3"));
	ComboBox4->Append(_("4"));
	ComboBox4->Append(_("5"));
	ComboBox4->Append(_("6"));
	ComboBox4->Append(_("7"));
	ComboBox4->Append(_("8"));
	ComboBox4->Append(_("9"));
	ComboBox4->Append(_("10"));
	ComboBox4->Append(_("11"));
	ComboBox4->Append(_("12"));
	ComboBox4->Append(_("13"));
	ComboBox4->Append(_("14"));
	ComboBox4->Append(_("15"));
	ComboBox5 = new wxComboBox(Panel1, ID_COMBOBOX5, wxEmptyString, wxPoint(472,136), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX5"));
	ComboBox5->Append(_("-1"));
	ComboBox5->Append(_("0"));
	ComboBox5->Append(_("1"));
	ComboBox5->Append(_("2"));
	ComboBox5->Append(_("3"));
	ComboBox5->Append(_("4"));
	ComboBox5->Append(_("5"));
	ComboBox5->Append(_("6"));
	ComboBox5->Append(_("7"));
	ComboBox5->Append(_("8"));
	ComboBox5->Append(_("9"));
	ComboBox5->Append(_("10"));
	ComboBox5->Append(_("11"));
	ComboBox5->Append(_("12"));
	ComboBox5->Append(_("13"));
	ComboBox5->Append(_("14"));
	ComboBox5->Append(_("15"));
	ComboBox6 = new wxComboBox(Panel1, ID_COMBOBOX6, wxEmptyString, wxPoint(472,176), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX6"));
	ComboBox6->Append(_("-1"));
	ComboBox6->Append(_("0"));
	ComboBox6->Append(_("1"));
	ComboBox6->Append(_("2"));
	ComboBox6->Append(_("3"));
	ComboBox6->Append(_("4"));
	ComboBox6->Append(_("5"));
	ComboBox6->Append(_("6"));
	ComboBox6->Append(_("7"));
	ComboBox6->Append(_("8"));
	ComboBox6->Append(_("9"));
	ComboBox6->Append(_("10"));
	ComboBox6->Append(_("11"));
	ComboBox6->Append(_("12"));
	ComboBox6->Append(_("13"));
	ComboBox6->Append(_("14"));
	ComboBox6->Append(_("15"));
	ComboBox7 = new wxComboBox(Panel1, ID_COMBOBOX7, wxEmptyString, wxPoint(472,216), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX7"));
	ComboBox7->Append(_("-1"));
	ComboBox7->Append(_("0"));
	ComboBox7->Append(_("1"));
	ComboBox7->Append(_("2"));
	ComboBox7->Append(_("3"));
	ComboBox7->Append(_("4"));
	ComboBox7->Append(_("5"));
	ComboBox7->Append(_("6"));
	ComboBox7->Append(_("7"));
	ComboBox7->Append(_("8"));
	ComboBox7->Append(_("9"));
	ComboBox7->Append(_("10"));
	ComboBox7->Append(_("11"));
	ComboBox7->Append(_("12"));
	ComboBox7->Append(_("13"));
	ComboBox7->Append(_("14"));
	ComboBox7->Append(_("15"));
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("O Operador"), wxPoint(408,104), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("O Sinal"), wxPoint(408,144), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("D Operador"), wxPoint(408,184), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("D Sinal"), wxPoint(408,224), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	Button9 = new wxButton(Panel1, ID_BUTTON9, _("Atualizar Conector"), wxPoint(624,56), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
	Button10 = new wxButton(Panel1, ID_BUTTON10, _("Lista Conectores"), wxPoint(624,96), wxSize(136,34), 0, wxDefaultValidator, _T("ID_BUTTON10"));
	Button11 = new wxButton(Panel1, ID_BUTTON11, _("teste"), wxPoint(144,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
	Button12 = new wxButton(Panel1, ID_BUTTON12, _("teste"), wxPoint(144,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
	Button13 = new wxButton(Panel1, ID_BUTTON13, _("TESTE"), wxPoint(24,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
	Button14 = new wxButton(Panel1, ID_BUTTON14, _("teste"), wxPoint(144,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON14"));
	Button15 = new wxButton(Panel1, ID_BUTTON15, _("Conectar"), wxPoint(512,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON15"));
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_AND);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_OR);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_NOT);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_NAND);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_NOR);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_Lista);
	Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&Debug::OnComboBox1Selected);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_Sinais);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_AddConector);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_RefConector);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnClick_ListaConectores);
	Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnButton11Click);
	Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnButton12Click);
	Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnButton13Click);
	Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnButton14Click);
	Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Debug::OnButton15Click);
	Panel1->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Debug::OnLeftDown,0,this);
	//*)
}

Debug::~Debug()
{
	//(*Destroy(Debug)
	//*)
}

void Debug::OnClick_AND(wxCommandEvent& event)
{
	debugCircuito->AddOperator(otAND);
}

void Debug::OnClick_OR(wxCommandEvent& event)
{
	debugCircuito->AddOperator(otOR);
}

void Debug::OnClick_NOT(wxCommandEvent& event)
{
	debugCircuito->AddOperator(otNOT);
}

void Debug::OnClick_NAND(wxCommandEvent& event)
{
	debugCircuito->AddOperator(otNAND);
}

void Debug::OnClick_NOR(wxCommandEvent& event)
{
	debugCircuito->AddOperator(otNOR);
}

void Debug::OnClick_Lista(wxCommandEvent& event)
{
	vector<_Operator> op = debugCircuito->GetOperators();
	TextCtrl1->AppendText(debug->GetOperator(op));
}

void Debug::OnComboBox1Selected(wxCommandEvent& event)
{
	wxString select = ComboBox1->GetValue();
	int selected = atoi(select.c_str());
	_Operator op = debugCircuito->GetOperator(selected);
	TextCtrl1->AppendText(debug->GetOperator(op));
}

void Debug::OnClick_Sinais(wxCommandEvent& event)
{
	wxString select = ComboBox1->GetValue();
	int selected = atoi(select.c_str());
	BooleanList se = debugCircuito->GetOperator(selected).GetIns();
	BooleanList ss = debugCircuito->GetOperator(selected).GetOuts();
	TextCtrl1->AppendText(debug->GetIn(se));
	TextCtrl1->AppendText(debug->GetOut(ss));
}

void Debug::OnClick_AddConector(wxCommandEvent& event)
{
	int selected = ComboBox2->GetSelection();
	switch(selected)
	{
		case 0:
			{
				debugCircuito->AddConnector(ctINPUT);
				break;
			}
		case 1:
			{
				debugCircuito->AddConnector(ctOUTPUT);
				break;
			}
		case 2:
			{
				debugCircuito->AddConnector(ctIN_OUT);
				break;
			}
	}
	vector<_Connector> cn = debugCircuito->GetConnectors();
	TextCtrl1->AppendText(debug->GetConnectors(cn));
}

void Debug::OnClick_RefConector(wxCommandEvent& event)
{
	int selected = ComboBox3->GetSelection();
	int OO = ComboBox4->GetSelection() -1;
	int OS = ComboBox5->GetSelection() -1;
	int DO = ComboBox6->GetSelection() -1;
	int DS = ComboBox7->GetSelection() -1;
	debugCircuito->SetConnector(selected, OO, OS, DO, DS);

	vector<_Connector> cn = debugCircuito->GetConnectors();
	TextCtrl1->AppendText(debug->GetConnectors(cn));
}

void Debug::OnClick_ListaConectores(wxCommandEvent& event)
{
	vector<_Connector> cn = debugCircuito->GetConnectors();
	TextCtrl1->AppendText(debug->GetConnectors(cn));
}

void Debug::OnButton11Click(wxCommandEvent& event)
{
	debugCircuito->SetConnectorSignal(0, true);
}

void Debug::OnButton12Click(wxCommandEvent& event)
{
	debugCircuito->SetConnectorSignal(1, true);
}

void Debug::OnButton14Click(wxCommandEvent& event)
{
	debugCircuito->SetConnectorSignal(2, true);
}

void Debug::OnButton13Click(wxCommandEvent& event)
{
		debugCircuito->AddOperator(otOR);
		debugCircuito->AddOperator(otAND);
		debugCircuito->AddConnector(ctINPUT, 0, 0, -1, -1);
		debugCircuito->AddConnector(ctINPUT,  0, 1, -1, -1);
		debugCircuito->AddConnector(ctINPUT, 1, 1, -1, -1);
		debugCircuito->AddConnector(ctIN_OUT, 1, 0, 0, 0);
		debugCircuito->AddConnector(ctOUTPUT, -1, -1, 1, 0);
}



void Debug::OnLeftDown(wxMouseEvent& event)
{
	int x = event.GetPosition().x;
	int y = event.GetPosition().y;

	TextCtrl1->AppendText("coordenadas: " + to_string(x) + ":" + to_string(y) );
}

void Debug::OnButton15Click(wxCommandEvent& event)
{

}
