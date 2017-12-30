# **********************************************************************
# * Copyright (C) 2017 MX Authors
# *
# * Authors: Adrian
# *          Dolphin_Oracle
# *          MX Linux <http://mxlinux.org>
# *
# * This file is part of mx-package-manager.
# *
# * mx-package-manager is free software: you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation, either version 3 of the License, or
# * (at your option) any later version.
# *
# * mx-package-manager is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
# *
# * You should have received a copy of the GNU General Public License
# * along with mx-package-manager.  If not, see <http://www.gnu.org/licenses/>.
# **********************************************************************/

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = milis-paket-yoneticisi
TEMPLATE = app


SOURCES += main.cpp\
    cmd.cpp \
    mainwindow.cpp \
    lockfile.cpp \
    versionnumber.cpp

HEADERS  += \
    cmd.h \
    mainwindow.h \
    lockfile.h \
    versionnumber.h

FORMS    += \
    mainwindow.ui

TRANSLATIONS += translations/milpek_ca.ts \
                translations/milpek_de.ts \
                translations/milpek_el.ts \
                translations/milpek_es.ts \
                translations/milpek_fr.ts \
                translations/milpek_it.ts \
                translations/milpek_ja.ts \
                translations/milpek_nl.ts \
                translations/milpek_ro.ts \
                translations/milpek_sv.ts

RESOURCES += \
    images.qrc


