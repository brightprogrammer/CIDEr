#include "MainApp.hpp"

bool MainApp::OnInit(){
	Editor::MainFrame *editor = new Editor::MainFrame("CIDEr");
	editor->Show();
	return true;
}