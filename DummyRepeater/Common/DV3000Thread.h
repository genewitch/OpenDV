/*
 *   Copyright (C) 2014,2015 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef	DV3000Thread_H
#define	DV3000Thread_H

#include "DV3000Controller.h"
#include "DongleThread.h"

#include <wx/wx.h>

class CDV3000Thread : public CDongleThread {
public:
	CDV3000Thread(IDV3000Controller* dongle);
	virtual ~CDV3000Thread();

	virtual bool open();

	virtual void setEncode();
	virtual void setDecode();
	virtual void setIdle();

	virtual void* Entry();

private:
	enum AMBE3000MODE {
		A3_DECODE,
		A3_ENCODE,
		A3_IDLE
	};

	IDV3000Controller* m_dongle;
	AMBE3000MODE       m_wantMode;
	AMBE3000MODE       m_mode;
	unsigned int       m_packets;

	void processDecodeOut();
	void processDecodeIn();
	void processEncodeOut();
	void processEncodeIn();
};

#endif
