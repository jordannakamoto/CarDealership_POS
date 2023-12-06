#ifndef OPTIONSDATALOADER_H
#define OPTIONSDATALOADER_H

#include <mysqlx/xdevapi.h>
#include <wx/wx.h>
#include <wx/grid.h>

using namespace mysqlx;

void LoadOptionsData(wxPanel* mainPanel, mysqlx::Session* session, wxGrid*& grid);


#endif // OPTIONSDATALOADER_H
