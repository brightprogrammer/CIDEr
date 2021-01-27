#include "MainFrame.hpp"
#include <memory>
#include <wx/event.h>
#include <wx/filedlg.h>
#include <wx/font.h>
#include <wx/gdicmn.h>
#include <wx/generic/statusbr.h>
#include <wx/gtk/dialog.h>
#include <wx/gtk/msgdlg.h>
#include <wx/gtk/textctrl.h>
#include <wx/sizer.h>
#include <wx/stringimpl.h>
#include <wx/textctrl.h>

const int INDEX_BEGIN = 1000; //beginning id for events
//EVENTHANDLERID(s)
const int NEW_FILE = INDEX_BEGIN;
const int OPEN_FILE = INDEX_BEGIN + 1;
const int SAVE = INDEX_BEGIN + 2;
const int SAVE_AS = INDEX_BEGIN + 3;
const int TEXT_CTRL = INDEX_BEGIN + 4;

Editor::MainFrame::MainFrame(const wxString &title) :
wxFrame(nullptr, wxID_ANY, title){
    //set window name to the file current being read
    this->SetTitle(wxString(title + "-" + filename));

    this->SetMinSize(wxSize(640, 480)); //MIGHTCHANGE : might want to change this in future

    //the main menu bar of editor
	pMenuBar = new wxMenuBar;

    //create menu(s) here
    pFileMenu = new wxMenu;
        pFileMenu->Append(NEW_FILE, "&New File", "Create a new file");
        pFileMenu->Append(OPEN_FILE, "&Open File", "Open an existing file");
        pFileMenu->AppendSeparator();
        pFileMenu->Append(SAVE, "&Save", "Save current buffer");
        pFileMenu->Append(SAVE_AS, "&Save As", "Save current buffer with new name");
        pFileMenu->AppendSeparator();
        pFileMenu->Append(wxID_EXIT, "&Exit", "Exit CIDEr!");
    pEditMenu = new wxMenu;

    //add menu(s) in menu bar    
    pMenuBar->Append(pFileMenu, "&File");
    pMenuBar->Append(pEditMenu, "&Edit");

    //source code editor
    //we store the text control in a panel so that if we want to change the top ui of editor then this component
    //just needs to change its panel's parent from this to another parent
    pTextEditorPanel = new wxPanel(this, wxID_ANY); //panel that contains the text control
    pTextEditor = new wxTextCtrl(pTextEditorPanel, TEXT_CTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    pTextEditorSizer = new wxBoxSizer(wxVERTICAL); //sizer for changing size of text editor acc.ly
    pTextEditorSizer->Add(pTextEditor, 1, wxEXPAND); //we want the text editor to occupy full space of pTextEditorPanel
    pTextEditorPanel->SetSizer(pTextEditorSizer); //set the sizer for text editor panel
    pTextEditor->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL)); 

    //set menu bar for mainframe (this)
    this->SetMenuBar(pMenuBar);

    //connect event handlers
    Connect(NEW_FILE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnNewFile));
    Connect(OPEN_FILE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnOpenFile));
    Connect(SAVE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnSave));
    Connect(SAVE_AS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnSaveAs));
    Connect(TEXT_CTRL, wxEVT_TEXT, wxTextEventHandler(MainFrame::OnFileAltered));

    pStatusBar = new wxStatusBar(this);
    this->SetStatusBar(pStatusBar);
}

void Editor::MainFrame::OnNewFile(wxCommandEvent &event){
    //if the file is changed and user is creating a new file without saving previous one we want to make it sure!
    if(isFileChanged == true){
        //confirmation dialog
        wxMessageDialog *pConfirmSaveDialog = new wxMessageDialog(this, 
        "Unsaved changes detected, are you sure? Changes will not be saved!", "Confirm", wxYES_NO | wxCENTRE | wxICON_WARNING);

        //open confirmation dialog and check for selected value
        if(pConfirmSaveDialog->ShowModal() == wxID_YES){
                //if user confirms then clear the editor, and reset all states
                pTextEditor->Clear();
                filename = "Untitled";

                isFileSaved = false;
                isFileChanged = false;
        } //else do nothing : wait for user to save the altered file    
    }
}

void Editor::MainFrame::OnOpenFile(wxCommandEvent &event){
    wxFileDialog *pOpenFileDialog = new wxFileDialog(this);
    if(pOpenFileDialog->ShowModal() == wxID_OK){
        filename = pOpenFileDialog->GetPath();
        pTextEditor->LoadFile(filename);
        this->SetName(filename);

        isFileChanged = false;
        isFileSaved = false;
    }
}

void Editor::MainFrame::OnSave(wxCommandEvent &event){
    if(filename == "Untitled"){
        OnSaveAs(event);
    }else{
        pTextEditor->SaveFile(filename);

        isFileSaved = true;
        isFileChanged = false;
    }
}

void Editor::MainFrame::OnSaveAs(wxCommandEvent &event){
    wxFileDialog *pSaveAsFileDialog = new wxFileDialog(this, "Save As", "", "", "", wxFD_SAVE);
    if(pSaveAsFileDialog->ShowModal() == wxID_OK){
        filename = pSaveAsFileDialog->GetPath();
        pTextEditor->SaveFile(filename);
        this->SetName(filename);

        isFileSaved = true;
        isFileChanged = false;
    }
}

void Editor::MainFrame::OnFileAltered(wxCommandEvent &event){
    isFileChanged = true;
    isFileSaved = false;
}