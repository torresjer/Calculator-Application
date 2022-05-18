
#include "ButtonFactory.h"

ButtonFactory::ButtonFactory(wxFrame* mainWindow) { this->parent = mainWindow; };
ButtonFactory::~ButtonFactory() {};

wxButton* ButtonFactory::CreateButton(wxFrame* parent, int wxIDIntegrator, std::string lables) {

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxButton* buttonCreated = new wxButton(parent, 10000 + wxIDIntegrator, lables);
	buttonCreated->SetFont(font);

	return buttonCreated;

}
