#include "Main.cpp"
#include "wx-3.1/wx/wx.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include <boost/archive/impl/basic_text_oarchive.ipp>
#include <boost/archive/impl/text_oarchive_impl.ipp>
#include <boost/archive/impl/basic_text_iarchive.ipp>
#include <boost/archive/impl/text_iarchive_impl.ipp>
#include <fstream>

//random comment for pushing purposes
class saveFiles
{
public:
    friend class boost::serialization::access;
    std::string day;
    std::string doList;
    std::string undoList;
    saveFiles(){};
    saveFiles(std::string d, std::string o, std::string u) :
        day(d), doList(o), undoList(u)
    {}
};

namespace boost {
namespace serialization {

template<class Archive>
void serialize(Archive & ar, saveFiles & g, const unsigned int version)
{
    ar & g.day;
    ar & g.doList;
    ar & g.undoList;
}

} // namespace serialization
} // namespace boost

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

    // create and open a character archive for output
    std::ofstream ofs("filename");

    // create class instance
    const saveFiles g(currentDay, currentRandomDo, currentRandomUndo);

    // save data to archive
    { 
        boost::archive::text_oarchive oa(ofs);
        // write class instance to archive
        oa << g;
    	// archive and stream closed when destructors are called
    }

    // ... some time later restore the class instance to its orginal state
    saveFiles newg;
    
    {
        // create and open an archive for input
        std::ifstream ifs("filename");
        boost::archive::text_iarchive ia(ifs);
        // read class state from archive
        ia >> newg;
        // archive and stream closed when destructors are called
    }

    myFrame* frame = new myFrame(currentDay, wxDefaultPosition, wxSize(800, 640));
    wxStaticText* text = new wxStaticText(frame, wxID_ANY, currentRandomDo, wxDefaultPosition, wxDefaultSize, 0, "Do List");
    wxStaticText* textTwo = new wxStaticText(frame, wxID_ANY, currentRandomUndo, wxPoint(-1,15), wxDefaultSize, 0, "Undo List");
    frame->Show(true);
    return true;


 }

 myFrame::myFrame(const wxString& title, const wxPoint& pos, const wxSize& size):wxFrame(nullptr, wxID_ANY,title, pos, size ){

 }
 