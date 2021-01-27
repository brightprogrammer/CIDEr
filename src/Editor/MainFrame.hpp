/**
	@copyright
    CIDEr is a lighweight IDE for C/C++ programming.
    Copyright (C) 2021  Siddharth Mishra

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef CIDER_EDITOR_MAINFRAME
#define CIDER_EDITOR_MAINFRAME

/**
 * @class MainFrame
 * @author Siddharth Mishra
 * @date 01/26/21
 * @file MainFrame.hpp
 * @brief MainFrame is the main UI of CIDEr Editor.
 */
 
#include <wx/event.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <memory>

namespace Editor{
    /**
    * @brief MainFrame is the main window of CIDEr editor interface.
    * 
    */
    class MainFrame : public wxFrame{
        public:
	        MainFrame(const wxString &title);
        private:
            wxString filename = "Untitled";
            bool isFileSaved = false;
            bool isFileChanged = false;

            //editor menu
            wxMenuBar *pMenuBar;
            wxMenu *pFileMenu, *pEditMenu;

            //source code editor
            wxPanel *pTextEditorPanel;
            wxBoxSizer *pTextEditorSizer;
            wxTextCtrl *pTextEditor;

            //EVENTHANDLER(s)
            void OnNewFile(wxCommandEvent &event);
            void OnOpenFile(wxCommandEvent &event);
            void OnSave(wxCommandEvent &event);
            void OnSaveAs(wxCommandEvent &event);
            void OnFileAltered(wxCommandEvent &event);

            wxStatusBar *pStatusBar;
    };
}

#endif//CIDER_EDITOR_MAINFRAME