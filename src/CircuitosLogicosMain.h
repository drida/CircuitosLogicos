/***************************************************************
 * Name:      CircuitosLogicosLinuxMain.h
 * Purpose:   Defines Application Frame
 * Author:    Adriano Araujo (drida@drida.com.br)
 * Created:   2021-01-10
 * Copyright: Adriano Araujo (http://drida.com.br)
 * License:
 **************************************************************/

#ifndef CIRCUITOSLOGICOSLINUXMAIN_H
#define CIRCUITOSLOGICOSLINUXMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "CircuitosLogicosApp.h"

class CircuitosLogicosMain: public wxFrame
{
    public:
        CircuitosLogicosMain(wxFrame *frame, const wxString& title);
        ~CircuitosLogicosMain();
    private:
        enum
        {
        	idMenuTemplate = 1000,
        	idMenuTetris ,
        	idMenuGame,
            idMenuQuit,
            idMenuAbout
        };
        void OnTemplate(wxCommandEvent& event);
        void OnTetris(wxCommandEvent& event);
        void OnGame(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // CIRCUITOSLOGICOSLINUXMAIN_H
