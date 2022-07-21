#include "Main.cpp"
#include "wx-3.1/wx/wx.h"
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
private:
    friend class boost::serialization::access;
    // When the class Archive corresponds to an output archive, the
    // & operator is defined similar to <<.  Likewise, when the class Archive
    // is a type of input archive the & operator is defined similar to >>.
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
public:
    saveData(){};
    saveData(std::string d, std::string o, std::string u) :
        day(d), randomDo(o), randomUndo(u)
    {}

    std::string data(int number){
        std::string code[3]{day, randomDo, randomUndo};
        return code[number];
    }
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
};


 bool myApp::OnInit(){
    
    saveData allData;
    mainClass mainFunction;
    std::string currentDay = mainFunction.function();
    std::string currentRandomDo = mainFunction.randomDo();
    std::string currentRandomUndo = mainFunction.randomUndo();

    std::ofstream ofs("filename");
    boost::archive::text_oarchive oa(ofs);

    const saveData g(currentDay, currentRandomDo, currentRandomUndo);

    oa << g;
    ofs.close();

    std::ifstream ifs("filename", std::ios::binary);
    boost::archive::text_iarchive ia(ifs);
    // read class state from archive
    saveData newg;
    ia >> newg;
    // close archive
    ifs.close();


    myFrame* frame = new myFrame("hello", wxDefaultPosition, wxSize(800, 640));
    wxStaticText* text = new wxStaticText(frame, wxID_ANY, "aaa", wxDefaultPosition, wxDefaultSize, 0, "Do List");
    wxStaticText* textTwo = new wxStaticText(frame, wxID_ANY, "memes", wxPoint(-1,15), wxDefaultSize, 0, "Undo List");
    frame->Show(true);
    return true;


 }

 myFrame::myFrame(const wxString& title, const wxPoint& pos, const wxSize& size):wxFrame(nullptr, wxID_ANY,title, pos, size ){

 }
 