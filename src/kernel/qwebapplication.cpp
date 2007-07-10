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

#include <QtWeb/QWebApplication>
#include <QtCore/QCoreApplication>
#include <QtCore/QTextStream>
#include <QtCore/QBuffer>
#include <QtCore/QByteArray>
#include <QtCore/QUrl>
#include <QtNetwork/QHttpRequestHeader>
#include <QtWeb/QWebFileRessourceProvider>
#include <QtWeb/QWebWebget>
#include <QtWeb/QWebBufferedRessource>

QWebApplication::QWebApplication(const QString& sessionId) :
    QWebAbstractRessourceProvider(sessionId),
    m_mainWebget(NULL),
    m_buffer(NULL),
    m_javascriptDir("javascript"),
    m_styleSheetsDir("stylesheets")
{
    m_fileProvider = new QWebFileRessourceProvider();
    setKeepSessions(true);
}

QWebApplication::~QWebApplication()
{
    delete m_mainWebget;
    delete m_fileProvider;
}

QWebAbstractRessource* QWebApplication::provide(const QHttpRequestHeader& header, const QString& postContent)
{
    QUrl url(header.path());

    qDebug(header.path().toAscii().data());
    qDebug(url.path().toAscii().data());

    if (m_mainWebget != NULL && (header.path().mid(1).isEmpty() || url.path().mid(1).isEmpty() || QCoreApplication::applicationFilePath().endsWith(url.path()))) {
        QByteArray data;
        QBuffer buffer(&data);
        buffer.open(QIODevice::WriteOnly);

        QWebParameters params(header, postContent);

        QString call = url.queryItemValue("call");
        if (call.isEmpty()) {
            call = m_mainWebget->webName() + ".render";
        }

        QString mimeType = m_mainWebget->invoke(call, params, &buffer);

        if (mimeType != QString::null) {
            return new QWebBufferedRessource(header.path(), mimeType, data);
        }
    }
    return m_fileProvider->provide(header, postContent);
}

void QWebApplication::setMainWebget(QWebWebget* w)
{
    delete m_mainWebget;
    m_mainWebget = w;
    m_mainWebget->setParent(this);
    m_mainWebget->setWebApp(this);
}

void QWebApplication::setJavascriptDir(const QString& javascriptDir)
{
    m_javascriptDir = javascriptDir;
}

QString QWebApplication::javascriptDir() const
{
    return m_javascriptDir;
}

void QWebApplication::setStyleSheetsDir(const QString& styleSheetsDir)
{
    m_styleSheetsDir = styleSheetsDir;
}

QString QWebApplication::styleSheetDir() const
{
    return m_styleSheetsDir;
}