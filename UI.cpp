#include "serialization.h"
#include "wx-3.1/wx/wx.h"

class myApp:public wxApp{
    public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(myApp);

class myFrame:public wxFrame{
    public:
    myFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
};


 bool myApp::OnInit(){
    startApp();

    myFrame* frame = new myFrame("Welcome", wxDefaultPosition, wxSize(800, 640));
    wxStaticText* text = new wxStaticText(frame, wxID_ANY, "Hello", wxDefaultPosition, wxDefaultSize, 0, "Do List");
    wxStaticText* textTwo = new wxStaticText(frame, wxID_ANY, "Hi", wxPoint(-1,15), wxDefaultSize, 0, "Undo List");
    frame->Show(true);
    return true;


 }

 myFrame::myFrame(const wxString& title, const wxPoint& pos, const wxSize& size):wxFrame(nullptr, wxID_ANY,title, pos, size ){

 }
 