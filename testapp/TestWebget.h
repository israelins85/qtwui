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

class QWebLabel;
class QWebStackedWebget;

class TestWebget : public QWebWebget
{
    Q_OBJECT
public:
    TestWebget(QWebWebget* parent, const QString& webName);
    virtual ~TestWebget();

public slots:
    void coucou(QString& mimeType);
    void empty(QString& mimeType);
    void ajaxcall(QString& mimeType);
    void linkClicked();
    void link2Clicked(const QString& link);
private:
    int m_items;
    int m_nb;
    QWebLabel* m_label1;
    QWebLabel* m_label2;
    QWebStackedWebget* m_stack;
};

#endif // TESTWEBGET_H
