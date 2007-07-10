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

#ifndef TESTWEBGET_H
#define TESTWEBGET_H

#include <QtWeb/QWebWebget>

class TestWebget : public QWebWebget
{
    Q_OBJECT
public:
    TestWebget(QWebWebget* parent, const QString& webName);
    virtual ~TestWebget();

public slots:
    void coucou(QString& mimeType, const QWebParameters& parameters, QIODevice* dev);
    void empty(QString& mimeType, const QWebParameters& parameters, QIODevice* dev);
    void ajaxcall(QString& mimeType, const QWebParameters& parameters, QIODevice* dev);
    void linkClicked(QString& mimeType, const QWebParameters& parameters, QIODevice* dev);

protected:
    virtual void beforeRenderChildren(const QWebParameters& parameters, QTextStream& stream);
    virtual void afterRenderChildren(const QWebParameters& parameters, QTextStream& stream);

private:
	int m_items;
};

#endif // TESTWEBGET_H