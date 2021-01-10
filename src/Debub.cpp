#include "Debub.h"

//(*InternalHeaders(Debub)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Debub)
const long Debub::ID_TEXTCTRL1 = wxNewId();
const long Debub::ID_PANEL2 = wxNewId();
const long Debub::ID_BUTTON1 = wxNewId();
const long Debub::ID_BUTTON2 = wxNewId();
const long Debub::ID_BUTTON3 = wxNewId();
const long Debub::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Debub,wxFrame)
	//(*EventTable(Debub)
	//*)
END_EVENT_TABLE()

Debub::Debub(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Debub)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(168,88), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel2 = new wxPanel(Panel1, ID_PANEL2, wxPoint(16,200), wxSize(368,240), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, _("Text"), wxPoint(16,16), wxSize(200,200), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("AND"), wxPoint(24,72), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(Panel1, ID_BUTTON2, _("OR"), wxPoint(24,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(Panel1, ID_BUTTON3, _("NOT"), wxPoint(24,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	//*)
}

Debub::~Debub()
{
	//(*Destroy(Debub)
	//*)
}

