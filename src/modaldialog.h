/*
This file is part of nppcrypt
(http://www.github.com/jeanpaulrichter/nppcrypt)
a plugin for notepad++ [ Copyright (C)2003 Don HO <don.h@free.fr> ]
(https://notepad-plus-plus.org)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#ifndef MODALDIALOG_H_DEF
#define MODALDIALOG_H_DEF

#include "npp/Window.h"
#include "npp/Notepad_plus_msgs.h"
#include "crypt.h"

class ModalDialog : public Window
{
public:
                        ModalDialog() : Window() {};
                        ~ModalDialog() { destroy(); };
    virtual void        init(HINSTANCE hInst, HWND parent, int dialogID, INT_PTR returnID);
    virtual bool        doDialog();
    void                destroy();

protected:
    void                        goToCenter();
    void                        getText(int id, crypt::secure_string& str, HWND hwnd = NULL);
    void                        setText(int id, const crypt::secure_string& str, HWND hwnd = NULL);
    void                        setupInputEncodingSelect(HWND hwnd, int id);
    static INT_PTR CALLBACK     dlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
    virtual INT_PTR CALLBACK    run_dlgProc(UINT message, WPARAM wParam, LPARAM lParam) = 0;

    RECT        _rc;
    int         _dlgID;
    INT_PTR     _returnID;
};

#endif