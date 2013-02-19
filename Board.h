//
// Board.h
//
// Author:
//       Antonius Riha <antoniusriha@gmail.com>
//
// Copyright (c) 2013 Antonius Riha
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef BOARD_H
#define BOARD_H

#include <algorithm>
#include "List.h"

using namespace std;

enum Player {
	None,
	Player1,
	Player2
};

class Board {
public:
	Board (int rows, int cols, int nConnect);
	Board (int rows, int cols, int zDepth, int nConnect);
	~Board ();
	
	const int * const getDims () const { return iList.getDims (); }
	int getNDims () const { return iList.getNDims (); }
	Player getCurPlayer () const { return curPlayer; }
	Player getWinner () const { return winner; }
	int getNConnect () const { return nConnect; }
	
	void SetDisc (int *index);
	bool UnsetDisc (int *index);
	
private:
	bool connected (int *index, Player cur) const;
	
	bool isIndexValid (int *idx) const {
		return idx [0] >= 0 && idx [1] >= 0 &&
		       idx [0] < dims [0] && idx [1] < dims [1];
	}

	const int nConnect;
	const List<Player> &iList;
	Player curPlayer;
	Player winner;
};

#endif
