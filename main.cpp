/*** 
 * @Author: LK
 * @Date: 2024-04-04 12:01:25
 * @LastEditTime: 2024-04-04 12:12:09
 * @LastEditors: LK
 * @Description:    
 * @FilePath: /Learn/main.cpp
 * @@copyright (C) 2016-2021 XXX Ltd. All Rights Reserved.
 */
#include "mainwindow.h"
#include "newspaper.h"
#include "reader.h"

#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//    connect(sender,   signal,
//            receiver, slot);

    QCoreApplication app(argc, argv);
    Newspaper newspaper("Newspaper A");
    Reader reader;
    QObject::connect(&newspaper, &Newspaper::newPaper,
                     &reader,    &Reader::receiveNewspaper);
    newspaper.send();
    return app.exec();

}
