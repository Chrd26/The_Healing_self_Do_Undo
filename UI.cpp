#include "Main.cpp"
#include <sstream>
#include <string>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include "wx-3.1/wx/wx.h"

class saveState{

private:

friend class boost::serialization::access;

std::string day;
std::string undoList;
std::string doList;

template <class Archive>

void serialize(Archive& ar, const unsigned int version){

    ar& day;
    ar& undoList;
    ar& doList;

}

public:
 saveState(){};
 saveState(std::string d, std::string u, std::string o) :day(d), undoList(u), doList(o){};

void showData(){

std::cout << day << " , " << doList << " , " << undoList << std::endl;

};

void save(std::ostringstream& oss){
boost::archive::binary_oarchive oa(oss);
oa & *(this);

};

void load (std::ostringstream& oss){
    std::string str_data = oss.str();
    std::istringstream iss(str_data);
    boost::archive::binary_iarchive ia(iss);
    ia & *(this);
};

~saveState(){


}

};

BOOST_CLASS_VERSION(saveState, 1);

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

    mainClass mainFunction;
    std::string currentDay = mainFunction.function();
    std::string currentRandomDo = mainFunction.randomDo();
    std::string currentRandomUndo = mainFunction.randomUndo();
    saveState emp(currentDay, currentRandomDo, currentRandomUndo);
    std::ostringstream oss;
    emp.save(oss);
    saveState newEmp;
    newEmp.load(oss);
    newEmp.showData();

    myFrame* frame = new myFrame(currentDay, wxDefaultPosition, wxSize(800, 640));
    wxStaticText* text = new wxStaticText(frame, wxID_ANY, currentRandomDo, wxDefaultPosition, wxDefaultSize, 0, "Do List");
    wxStaticText* textTwo = new wxStaticText(frame, wxID_ANY, currentRandomUndo, wxPoint(-1,15), wxDefaultSize, 0, "Undo List");
    frame->Show(true);
    return true;


 }

 myFrame::myFrame(const wxString& title, const wxPoint& pos, const wxSize& size):wxFrame(nullptr, wxID_ANY,title, pos, size ){

 }
 