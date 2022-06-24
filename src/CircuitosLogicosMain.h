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
#include "Circuit.h"
#include "Data.h"

class CircuitosLogicosMain: public wxFrame
{
    public:
        CircuitosLogicosMain(wxFrame *frame, const wxString& title);
    private:
        Data* dataStage;

        enum
        {
            idMenuGame,
        	idMenuTetris,
            idMenuQuit,
            idMenuAbout
        };

        void OnGame(wxCommandEvent& event);
        void OnTetris(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        Circuit* MountStage(int numStage, Circuit* Stage);

        DECLARE_EVENT_TABLE()
};


#endif // CIRCUITOSLOGICOSLINUXMAIN_H
