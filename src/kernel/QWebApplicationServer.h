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
#ifndef QWEBAPPLICATIONSERVER_H
#define QWEBAPPLICATIONSERVER_H

#include "QWebRessourceProviderServer.h"
#include "QWebApplicationCreator.h"

class QWebApplicationServer : public QWebRessourceProviderServer
{
    Q_OBJECT

public:
    QWebApplicationServer(QWebApplicationCreator creatorFunction, QObject* parent = NULL);
    virtual ~QWebApplicationServer();

    void setBuiltInServerPort(quint16 port);
    void exec();

private slots:
    void initialize();
};

#endif // QWEBAPPLICATIONSERVER_H
