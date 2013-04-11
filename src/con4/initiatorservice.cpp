/*
 * initiatorservice.cpp
 *
 * Author:
 *       Antonius Riha <antoniusriha@gmail.com>
 *
 * Copyright (c) 2013 Antonius Riha
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <QTcpSocket>
#include "initiatorservice.h"

InitServerThread::InitServerThread (int socketDescriptor, QObject *parent)
    : QThread (parent), _socketDescriptor (socketDescriptor) {}

void InitServerThread::run () {
    QTcpSocket tcpSocket;
    if (!tcpSocket.setSocketDescriptor (_socketDescriptor)) return;

//    QByteArray block;
//    QDataStream out(&block, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_4_0);
//    out << (quint16)0;
//    out << text;
//    out.device()->seek(0);
//    out << (quint16)(block.size() - sizeof(quint16));

//    tcpSocket.write(block);
//    tcpSocket.disconnectFromHost();
//    tcpSocket.waitForDisconnected();
}

void InitServer::incomingConnection (int socketDescriptor) {
    InitServerThread *thread = new InitServerThread (socketDescriptor, this);
    connect (thread, SIGNAL (finished ()), thread, SLOT (deleteLater ()));
    thread->start ();
}

InitiatorService::InitiatorService (QString initiatorName, QString gameName,
                                    int width, int height, int depth)
    : NetworkPlayerService (initiatorName, gameName, width, height, depth) {}

bool InitiatorService::startService () {
    if (!_initServer.listen ()) return false;
    assignIpAddress ();
    _hasStarted = true;
    return true;
}
