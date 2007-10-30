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

#include "TestWebget.h"
#include <QtCore/QTextStream>
#include <QtCore/QIODevice>
#include <QtGui/QImage>
#include <QtWeb/QWebApplication>
#include <QtWeb/QWebHBoxLayout>
#include <QtWeb/QWebVBoxLayout>
#include <QtWeb/QWebGridLayout>
#include <QtWeb/QWebStackedLayout>
#include <QtWeb/QWebLabel>
#include <QtWeb/QWebStackedWebget>

TestWebget::TestWebget(QWebWebget* parent, const QString& webName) :
    QWebWebget(parent, webName),
    m_items(0),
    m_nb(0)
{
    qDebug("YYYYYYYYEEEEEEEEEHHHHHHHHHHHHHHAAAAAAAAAAAAHHHHH !!!!");

    //QWebLabel* l1 = new QWebLabel(this, "l1");
    //l1->setText("Label 1");
    QWebLabel* l2 = new QWebLabel(this, "l2");
    l2->setText("- Label 2 -");
    l2->setTextColor(QColor(0, 0, 200));
    l2->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    l2->setBorderStyle(Qt::DashedStyle);
    l2->setBorderColor(QColor(0, 200, 50));
    l2->setBorderWidth(10);
    QWebLabel* l21 = new QWebLabel(this, "l2");
    l21->setText("yoyo Label 21  yoyo");
    QWebLabel* l3 = new QWebLabel(this, "l3");
    l3->setText("Label 3");
    l3->setBackgroundColor(QColor(200, 0, 10));
    l3->setBorderStyle(Qt::DashedStyle);
    l3->setBorderColor(QColor(0, 200, 50));
    l3->setBorderWidth(10);
    l3->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QWebLabel* l31 = new QWebLabel(this, "l31");
    l31->setText("Label 31 <a href=\"mylink\">Click Me</a> toto");
    l31->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    QWebLabel* l4 = new QWebLabel(this, "l4");
    QImage img(100, 100, QImage::Format_RGB32);
    img.fill(qRgb(189, 149, 39));
    l4->setImage(img);
    QWebLabel* l5 = new QWebLabel(this, "l5");
    l5->setImageFile("bin/coin.jpg");
    QWebLabel* link = new QWebLabel(this, "link");

    link->setText("<a href=\"link\">Test</a> and <a href=\"swap\">swap it !!</a>");
    m_stack = new QWebStackedWebget(this, "stack");
    m_stack->addWebget(l2);
    m_stack->addWebget(l21);

    QWebGridLayout* l = new QWebGridLayout(this);
    QWebHBoxLayout* hbox = new QWebHBoxLayout();
    //l->insertWebget(l1, 0, 0);
    //l->insertWebget(l2, 0, 1);
    l->insertItem(hbox, 1, 0);
    l->insertWebget(l4, 1, 1);
    l->insertWebget(l5, 2, 0);
    //l->insertWebget(link, 2, 1);

    l->insertWebget(link, 0, 0, 1, 2);
    l->insertWebget(m_stack, 2, 1);

    hbox->addWebget(l3, 1);
    hbox->addWebget(l31, 9);

    connect(l31, SIGNAL(clicked(const QString&)), this, SLOT(linkClicked()));
    connect(link, SIGNAL(clicked(const QString&)), this, SLOT(link2Clicked(const QString&)));
    m_label1 = l31;
    m_label2 = l3;

#if 0
    QWebLink* link = new QWebLink(this, "link", "Test", this, Qt::AjaxInsertionReplace);
    connect(link, SIGNAL(clicked(QString&, const QWebParameters&, QIODevice*)), this, SLOT(linkClicked(QString&, const QWebParameters&, QIODevice*)));
    if (webName == "test1") {
        /*QWebHBoxLayout* hbox = new QWebHBoxLayout(this);
        hbox->addWebget(new TestWebget(this, "test2"), 1);
        QWebVBoxLayout* vbox = new QWebVBoxLayout(QWebLayout::Em);
        hbox->addLayout(vbox, 2);
        vbox->addWebget(new TestWebget(this, "test3"), 30);
        vbox->addWebget(new TestWebget(this, "test4"));*/

        l->insertWebget(new TestWebget(this, "test2"), 0, 0, 1, 2);
        //l->insertWebget(new TestWebget(this, "test3"), 0, 1);
        l->insertWebget(new TestWebget(this, "test4"), 1, 0);
        l->insertWebget(new TestWebget(this, "test5"), 1, 1);
    }
#endif //0
}

TestWebget::~TestWebget()
{
    qDebug("AAAAAAAAAAAAAAAAAAAARRRRRGGGGGGGGGGGG !!!!");
}

void TestWebget::coucou(QString& mimeType)
{
    mimeType = "text/plain";
    QString s("Hello World from %1 method !");
    s = s.arg(webPath());
    device()->write(s.toAscii(), s.length());
}

void TestWebget::empty(QString& mimeType)
{
    mimeType = "text/html";
}

void TestWebget::ajaxcall(QString& mimeType)
{
    mimeType = "text/html";
    qDebug("AJAX Call !!!");
    QString s1("<ul class=\"testajax\">");
    QString s2("<li>Item %1</li>");
    QString s3("</ul>");

    device()->write(s2.arg(++m_items).toAscii(), s2.length());
    //dev->write(s1.toAscii(), s1.length());
    /*++m_items;
    for (int i = 0; i < m_items; ++i) {
        dev->write(s2.toAscii(), s2.length());
    }*/
    //dev->write(s3.toAscii(), s3.length());
}

void TestWebget::linkClicked()
{
    m_label1->setText(QString("%1 call #%2").arg(webApp()->sessionId()).arg(m_nb));
    m_label2->setText(QString("Haha %1 call #%2").arg(webApp()->sessionId()).arg(m_nb));
    ++m_nb;
    /*
    QWebParameters parameters = webApp()->parameters();
    mimeType = "text/plain";
    QTextStream stream(device());
    stream << "coucou " << m_items << " " << webApp()->sessionId() << " " << parameters["toto"] << " " << parameters["toto2"] << "<br />";
    m_items = m_items + 1;
    */
}

void TestWebget::link2Clicked(const QString& link)
{
    qDebug(link.toAscii());
    if (link == "link") {
        m_label1->setText("Yeeeeehhhaaaahh !!!!");
    } else if (link == "swap") {
        int i = m_stack->currentIndex();
        i = (i == 1) ? 0 : 1;
        m_stack->setCurrentIndex(i);
    }
}
