//When building ensure it is in x86 
#pragma once
#include "MainWindow.h"
#include "wx/wx.h"

class App : public wxApp
{
private:
	MainWindow* display = nullptr;

public:
	App();
	~App();
	virtual bool OnInit();
};

