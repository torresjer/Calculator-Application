#pragma once
#include "wx/wx.h"

class ButtonFactory
{
private:
	wxFrame* parent = nullptr;

public:
	ButtonFactory(wxFrame* window);
	~ButtonFactory();
	wxButton* CreateButton1() { wxButton* b = new wxButton(parent, 10000, "1"); return b; }
	wxButton* CreateButton2() { wxButton* b = new wxButton(parent, 10001, "2"); return b; }
	wxButton* CreateButton3() { wxButton* b = new wxButton(parent, 10002, "3"); return b; }
	wxButton* CreateButtonPlus() { wxButton* b = new wxButton(parent, 10003, "+"); return b; }
	wxButton* CreateButton4() { wxButton* b = new wxButton(parent, 10004, "4"); return b; }
	wxButton* CreateButton5() { wxButton* b = new wxButton(parent, 10005, "5"); return b; }
	wxButton* CreateButton6() { wxButton* b = new wxButton(parent, 10006, "6"); return b; }
	wxButton* CreateButtonMinus() { wxButton* b = new wxButton(parent, 10007, "-"); return b; }
	wxButton* CreateButton7() { wxButton* b = new wxButton(parent, 10008, "7"); return b; }
	wxButton* CreateButton8() { wxButton* b = new wxButton(parent, 10009, "8"); return b; }
	wxButton* CreateButton9() { wxButton* b = new wxButton(parent, 10010, "9"); return b; }
	wxButton* CreateButtonDivide() { wxButton* b = new wxButton(parent, 10011, "/"); return b; }
	wxButton* CreateButton0() { wxButton* b = new wxButton(parent, 10012, "0"); return b; }
	wxButton* CreateButtonEquals() { wxButton* b = new wxButton(parent, 10013, "="); return b; }
	wxButton* CreateButtonClear() { wxButton* b = new wxButton(parent, 10014, "C"); return b; }
	wxButton* CreateButtonMultiply() { wxButton* b = new wxButton(parent, 10015, "X"); return b; }
	wxButton* CreateButtonModular() { wxButton* b = new wxButton(parent, 10016, "%"); return b; }
	wxButton* CreateButtonBinary() { wxButton* b = new wxButton(parent, 10017, "BIN"); return b; }
	wxButton* CreateButtonHex() { wxButton* b = new wxButton(parent, 10018, "HEX"); return b; }
	wxButton* CreateButtonDecimal() { wxButton* b = new wxButton(parent, 10019, "DEC"); return b; }
	wxButton* CreateButton(wxFrame* parent, int wxIDIntegrator, std::string labels);
};

