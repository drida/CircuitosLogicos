/***************************************************************
 * Name:      CircuitosLogicosMain.h
 * Purpose:   Defines Application Frame
 * Author:    Adriano Araujo (drida@drida.com.br)
 * Created:   2020-12-26
 * Copyright: Adriano Araujo (http://drida.com.br)
 * License:
 **************************************************************/

#ifndef CIRCUITOSLOGICOSMAIN_H
#define CIRCUITOSLOGICOSMAIN_H

//(*Headers(CircuitosLogicosFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class CircuitosLogicosFrame: public wxFrame
{
	public:

		CircuitosLogicosFrame(wxWindow* parent,wxWindowID id = -1);
		virtual ~CircuitosLogicosFrame();

	private:

		//(*Handlers(CircuitosLogicosFrame)
		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		void OnNew(wxCommandEvent& event);
		void OnDebug(wxCommandEvent& event);
		void OnTemplate(wxCommandEvent& event);
		void OnEraseBackground(wxEraseEvent& event);
		void OnTetris(wxCommandEvent& event);
		//*)

		//(*Identifiers(CircuitosLogicosFrame)
		static const long idMenuNew;
		static const long idMenuQuit;
		static const long idMenuTemplate;
		static const long ID_MENUITEM1;
		static const long idMenuDebug;
		static const long idMenuAbout;
		static const long ID_STATUSBAR1;
		//*)

		//(*Declarations(CircuitosLogicosFrame)
		wxMenuItem* Menu3;
		wxMenuItem* MenuItem3;
		wxMenuItem* MenuItem4;
		wxMenuItem* MenuItem5;
		wxStatusBar* StatusBar1;
		//*)

		DECLARE_EVENT_TABLE()
};

#endif // CIRCUITOSLOGICOSMAIN_H
