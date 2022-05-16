#pragma once
#include "wx/wx.h"

class ButtonFactory
{
public:
	ButtonFactory();
	~ButtonFactory();
	wxButton* CreateButton(wxFrame* parent, int wxIDIntegrator, std::string labels);
};

