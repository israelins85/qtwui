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

#ifndef QWEBABSTRACTRESSOURCEPROVIDER_H
#define QWEBABSTRACTRESSOURCEPROVIDER_H

#include <QObject>
#include <QDateTime>

class QHttpRequestHeader;
class QWebAbstractRessource;

class QWebAbstractRessourceProvider : public QObject
{
    Q_OBJECT

public:
    QWebAbstractRessourceProvider(const QString& sessionId = QString::null);
    virtual ~QWebAbstractRessourceProvider();

    virtual QWebAbstractRessource* provide(const QHttpRequestHeader& header, const QString& postContent) = 0;
    QString sessionId() const;
    bool keepSessions() const;
    void setKeepSessions(bool keep);
    QDateTime sessionTimeoutDate() const;
    void resetSessionTimeoutDate();
    bool isSessionTimedOut() const;
    int sessionLifeTime() const;
    void setSessionLifeTime(int secs);

private:
    bool m_keepSessions;
    QDateTime m_sessionTimeoutDate;
    int m_sessionLifeTime;
    QString m_sessionId;
};

#endif // QWEBABSTRACTRESSOURCEPROVIDER_H
