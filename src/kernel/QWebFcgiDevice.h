/***************************************************************************
 *   Copyright (C) 2007 by Eric ALBER                                      *
 *   eric.alber@gmail.com                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef QWEBFCGIDEVICE_H
#define QWEBFCGIDEVICE_H

#include <QIODevice>

class QWebFcgiDevice : public QIODevice
{
    Q_OBJECT

public:
    QWebFcgiDevice(QObject* parent = NULL);
    virtual ~QWebFcgiDevice();

protected:
    virtual qint64 readData(char* data, qint64 maxSize);
    virtual qint64 writeData(const char * data, qint64 maxSize);
};

#endif // QWEBFCGIDEVICE_H
