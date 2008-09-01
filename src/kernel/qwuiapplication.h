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

#ifndef QWUIAPPLICATION_H
#define QWUIAPPLICATION_H

#include <QtCore/QObject>
#include <QtCore/QSet>
#include <QtWui/QwuiAbstractRessourceProvider>
#include <QtWui/QwuiParameters>
#include <QtWui/QwuiGlobal>

class QIODevice;
class QHttpRequestHeader;
class QwuiWebget;
class QwuiFileRessourceProvider;

class QTWUI_EXPORT QwuiApplication : public QwuiAbstractRessourceProvider
{
    Q_OBJECT

public:
    QwuiApplication(const QString& sessionId = QString::null);
    virtual ~QwuiApplication();

    QwuiAbstractRessource* provide(const QHttpRequestHeader& header, const QString& postContent);

    void setMainWebget(QwuiWebget* w);
    void setJavascriptDir(const QString& javascriptDir);
    QString javascriptDir() const;
    void setStyleSheetsDir(const QString& styleSheetsDir);
    QString styleSheetDir() const;
    QwuiParameters parameters() const;
    QIODevice* device();
    void addWebgetToUpdate(const QwuiWebget* webget);

private:
    QwuiWebget* m_mainWebget;
    QwuiFileRessourceProvider* m_fileProvider;
    QIODevice* m_device;
    QString m_javascriptDir;
    QString m_styleSheetsDir;
    QwuiParameters m_parameters;
    QSet<const QwuiWebget*> m_webgetsToUpdate;
};

#endif // QWUIAPPLICATION_H
