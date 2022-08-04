#include "Main.cpp"
#include <wx-3.2/wx/wx.h>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <stdio.h>

#include <boost/archive/impl/basic_text_oarchive.ipp>
#include <boost/archive/impl/text_oarchive_impl.ipp>
#include <boost/archive/impl/basic_text_iarchive.ipp>
#include <boost/archive/impl/text_iarchive_impl.ipp>
#include <fstream>

    class saveData
{
public:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & day;
        ar & randomDo;
        ar & randomUndo;
    }
    std::string day;
    std::string randomDo;
    std::string randomUndo;

    saveData(){};
    saveData(std::string d, std::string o, std::string u) :
        day(d), randomDo(o), randomUndo(u)
    {}
};


BOOST_CLASS_VERSION(saveData, 1)

class myApp:public wxApp{
    public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(myApp);

class myFrame:public wxFrame{
    public:
    myFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    wxButton *Exit;    
    void OnExit(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};

enum
{

BUTTON_Exit = wxID_HIGHEST + 1

};


 bool myApp::OnInit(){
    
    saveData allData;
    mainClass mainFunction;

    //load
    std::ifstream ifs("filename", std::ios::binary);
    boost::archive::text_iarchive ia(ifs);
    saveData newg;
    ia >> newg;
    ifs.close();


    mainFunction.function();

    std::string currentDay = mainFunction.function();
   
    if(newg.day !=currentDay){

    mainFunction.randomDo();
    mainFunction.randomUndo();
    
     std::string currentRandomDo = mainFunction.randomDo();
    std::string currentRandomUndo = mainFunction.randomUndo();

    std::ofstream ofs("filename");
    boost::archive::text_oarchive oa(ofs); 
    const saveData g(currentDay, currentRandomDo, currentRandomUndo);

    oa << g;
    ofs.close();

    std::ifstream ifs("filename", std::ios::binary);
    boost::archive::text_iarchive ia(ifs);
    saveData newg;
    ia >> newg;
    ifs.close();
    }

    //create ui

    myFrame* frame = new myFrame(newg.day, wxDefaultPosition, wxSize(600, 320));
    wxStaticText* text = new wxStaticText(frame, wxID_ANY, newg.randomDo, wxPoint(100,30), wxDefaultSize, 0, "Do List");
    wxStaticText* textTwo = new wxStaticText(frame, wxID_ANY, newg.randomUndo, wxPoint(100,80), wxDefaultSize, 0, "Undo List");
    frame->Show(true);
    return true;
 }

BEGIN_EVENT_TABLE ( myFrame, wxFrame)
    EVT_BUTTON ( BUTTON_Exit, myFrame::OnExit )
  END_EVENT_TABLE(); 

  myFrame::myFrame(const wxString &title, const wxPoint &pos, const wxSize
    &size): wxFrame((wxFrame*)NULL,  - 1, title, pos, size)
  {
    Exit = new wxButton(this, BUTTON_Exit, _T("Exit"),
    wxPoint(200,120), wxSize(200,160), 0); 
  }
 
  void myFrame::OnExit( wxCommandEvent& event )
  {
    Close(TRUE); 
  }

 