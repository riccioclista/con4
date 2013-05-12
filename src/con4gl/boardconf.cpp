/*
 * boardconf.cpp
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

#include "boardconf.h"

QColor BoardConf::_getColor(const float color[]) const
{
    return QColor(color[0], color[1], color[2], color[3]);
}

void BoardConf::_setColor(QColor value, float field[])
{
    if (value.redF() == field[0] && value.greenF() == field[1] &&
        value.blueF() == field[2] && value.alphaF() == field[3]) return;
    field[0] = value.redF();
    field[1] = value.greenF();
    field[2] = value.blueF();
    field[3] = value.alphaF();
    emit changed();
}

BoardConf::BoardConf(QObject *parent) : QObject(parent), _background(),
    _boardBase(), _cylinders(), _player1Color(), _player2Color() {}
