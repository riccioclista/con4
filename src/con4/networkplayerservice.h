/*
 * networkplayerservice.h
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

#ifndef NETWORKPLAYERSERVICE_H
#define NETWORKPLAYERSERVICE_H

#include <QHostAddress>
#include "game.h"

class NetworkPlayerService : public QObject {
    Q_OBJECT
public:
    NetworkPlayerService (QString initiatorName, QString gameName,
                          int width, int height, int depth);

    virtual quint16 port () const = 0;
    virtual bool startService () = 0;

    QString gameName () const { return _gameName; }
    QString initiatorName () const { return _initiatorName; }
    Game *const game () { return &_game; }
    QHostAddress ipAddress () const { return _ipAddress; }

protected:
    void assignIpAddress ();

private:
    NetworkPlayerService (const NetworkPlayerService &);
    NetworkPlayerService &operator= (const NetworkPlayerService &);

    QString _gameName, _initiatorName;
    Game _game;
    QHostAddress _ipAddress;
};

#endif // NETWORKPLAYERSERVICE_H
