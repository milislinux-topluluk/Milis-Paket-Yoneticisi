/**********************************************************************
 *  main.cpp
 **********************************************************************
 * Copyright (C) 2017 MX Authors
 *
 * Authors: Adrian
 *          Dolphin_Oracle
 *          MX Linux <http://mxlinux.org>
 *
 * This file is part of mx-package-manager.
 *
 * mx-package-manager is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mx-package-manager is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mx-package-manager.  If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/

#include "mainwindow.h"
#include "lockfile.h"
#include <unistd.h>

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QIcon>

#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("/usr/share/pixmaps/milpek.png"));

    QTranslator qtTran;
    qtTran.load(QString("qt_") + QLocale::system().name());
    a.installTranslator(&qtTran);

    QTranslator appTran;
    appTran.load(QString("milis-paket-yoneticisi_") + QLocale::system().name(), "/usr/share/milpek/locale");
    a.installTranslator(&appTran);

    if (getuid() == 0) {
        // Başka paket yöneticisi çalışıyorsa uygulamaya başlamayın, değilse program çalışırken paket yüklemeyi kilitle
        LockFile lock_file("/var/lib/pkg/kilit");
        if (lock_file.isLocked()) {
            QApplication::beep();
            QMessageBox::critical(0, QApplication::tr("Özel kilit alınamadı"),
                                  QApplication::tr("Başka bir paket yönetim uygulaması zaten çalışıyor. "\
                                                   "Lütfen önce diğer uygulamayı kapatın"));
            return 1;
        } else {
            lock_file.lock();
        }
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        QApplication::beep();
        QMessageBox::critical(0, QString::null,
                              QApplication::tr("Bu programı çalıştırmak için root olmalısınız"));
        return 1;
    }
}
