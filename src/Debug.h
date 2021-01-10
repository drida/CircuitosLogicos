#ifndef DEBUG_H
#define DEBUG_H

#include "Circuit.h"

//(*Headers(Debug)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Debug: public wxFrame
{
	public:

		Debug(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Debug();

		//(*Declarations(Debug)
		wxButton* Button10;
		wxButton* Button11;
		wxButton* Button12;
		wxButton* Button13;
		wxButton* Button14;
		wxButton* Button15;
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxButton* Button6;
		wxButton* Button7;
		wxButton* Button8;
		wxButton* Button9;
		wxComboBox* ComboBox1;
		wxComboBox* ComboBox2;
		wxComboBox* ComboBox3;
		wxComboBox* ComboBox4;
		wxComboBox* ComboBox5;
		wxComboBox* ComboBox6;
		wxComboBox* ComboBox7;
		wxPanel* Panel1;
		wxPanel* Panel2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(Debug)
		static const long ID_TEXTCTRL1;
		static const long ID_PANEL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON7;
		static const long ID_COMBOBOX2;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON8;
		static const long ID_COMBOBOX3;
		static const long ID_COMBOBOX4;
		static const long ID_COMBOBOX5;
		static const long ID_COMBOBOX6;
		static const long ID_COMBOBOX7;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_BUTTON9;
		static const long ID_BUTTON10;
		static const long ID_BUTTON11;
		static const long ID_BUTTON12;
		static const long ID_BUTTON13;
		static const long ID_BUTTON14;
		static const long ID_BUTTON15;
		static const long ID_PANEL1;
		//*)

	private:

		Circuit* debugCircuito;
		_Debug* debug;

		void LogDebug();

		//(*Handlers(Debug)
		void OnClose(wxCloseEvent& event);
		void OnClick_AND(wxCommandEvent& event);
		void OnClick_OR(wxCommandEvent& event);
		void OnClick_NOT(wxCommandEvent& event);
		void OnClick_NAND(wxCommandEvent& event);
		void OnClick_NOR(wxCommandEvent& event);
		void OnClick_Lista(wxCommandEvent& event);
		void OnComboBox1Selected(wxCommandEvent& event);
		void OnClick_Sinais(wxCommandEvent& event);
		void OnClick_AddConector(wxCommandEvent& event);
		void OnClick_RefConector(wxCommandEvent& event);
		void OnClick_ListaConectores(wxCommandEvent& event);
		void OnButton11Click(wxCommandEvent& event);
		void OnButton12Click(wxCommandEvent& event);
		void OnButton13Click(wxCommandEvent& event);
		void OnButton14Click(wxCommandEvent& event);
		void OnLeftDown(wxMouseEvent& event);
		void OnButton15Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
