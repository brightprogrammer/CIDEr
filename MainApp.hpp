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

#ifndef CIDER_MAINAPP
#define CIDER_MAINAPP

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif//WX_PRECOMP

#include <Editor/MainFrame.hpp>

/**
 * @class MainApp
 * @author Siddharth Mishra
 * @date 01/26/21
 * @file MainApp.hpp
 * @brief 
 */
class MainApp : public wxApp{
    public:
        virtual bool OnInit();
};

IMPLEMENT_APP(MainApp);
DECLARE_APP(MainApp);

#endif//CIDER_MAINAPP