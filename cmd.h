/**********************************************************************
 *  cmd.h
 **********************************************************************
 * Copyright (C) 2017 MX Authors
 *
 * Authors: Adrian
 *          MX Linux <http://forum.mxlinux.org>
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

#ifndef CMD_H
#define CMD_H

#include <QObject>
#include <QProcess>
#include <QTimer>

class Cmd : public QObject
{
    Q_OBJECT
public:
    explicit Cmd(QObject *parent = 0);
    ~Cmd();

    bool isRunning();
    int run(const QString &cmd_str, int = 0); // Tahmini tamamlanma süresi seçeneği ile
    QString getOutput();
    QString getOutput(const QString &cmd_str);

signals:
    void outputAvailable(const QString &output);
    void runTime(int, int); // Tahmini süreyle çalışma zamanı sayacı
    void started();
    void finished(int exitCode, QProcess::ExitStatus exitStatus);

public slots:
    void pause();
    void resume();
    bool terminate();
    bool kill();

private slots:
    void onStdoutAvailable();
    void tick(); // Bir sayaç yayınlayan zamanlayıcı tarafından çağrılan yuva

private:
    QProcess *proc;
    QString output;
    QTimer *timer;
    int counter;
    int est_duration; //tahmini tamamlanma süresi

};

#endif // CMD_H
