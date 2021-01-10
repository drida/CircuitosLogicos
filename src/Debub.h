#ifndef DEBUB_H
#define DEBUB_H

//(*Headers(Debub)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
//*)

class Debub: public wxFrame
{
	public:

		Debub(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Debub();

		//(*Declarations(Debub)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxPanel* Panel1;
		wxPanel* Panel2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(Debub)
		static const long ID_TEXTCTRL1;
		static const long ID_PANEL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(Debub)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
