//
// list.h
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

#ifndef LIST_H
#define LIST_H

#include <iterator>
#include <stdexcept>

using namespace std;

template <class T>
class list {
public:
	enum SortMode { Bubble, Quick };
	virtual ~list<T> () {}
	virtual const T getItem (int *index) const = 0;
	virtual void setItem (int *index, T value) = 0;
	
	T getItemByFlatIndex (int flatIndex) const {
		if (flatIndex < 0)
			throw new logic_error ("Index cannot be less than 0.");
		
		int count = getCount ();
		int *index = new int [numOfDims];
		for (int i = 0; i < numOfDims; i++)
			index [i] = 0;
		trIndex (flatIndex, count, 1, index);
		T item = getItem (index);
		delete index;
		return item;
	}
	
	void setItemByFlatIndex (int flatIndex, T value) {
		if (flatIndex < 0)
			throw new logic_error ("Index cannot be less than 0.");
		
		int count = getCount ();
		int *index = new int [numOfDims];
		for (int i = 0; i < numOfDims; i++)
			index [i] = 0;
		trIndex (flatIndex, count, 1, index);
		setItem (index, value);
		delete index;
	}
	
	const int *getDimensions () const { return dimensions; }
	int getNumOfDimensions () const { return numOfDims; }
	
	int getCount () const {
		int count = 1;
		for (int i = 0; i < numOfDims; i++)
			count *= dimensions [i];
		return count;
	}
	
	list<T> *sort (SortMode mode) const {
		if (numOfDims > 1)
			throw new logic_error ("sort can only be called with 1d lists.");
		
		// although not necessary, use fctn ptrs to fulfill requirements
		
	}

protected:
	list<T> (int *dimensions) : dimensions (dimensions), numOfDims (0) {
		if (dimensions [0] == 0)
			throw new logic_error ("The object must at least be 1d.");
		
		int nDims = 1;
		for (; nDims < 4; nDims++)
			if (nDims >= 3 || dimensions [nDims] == 0) break;
		numOfDims = nDims;
	}
	
	virtual list<T> *sortQuickly () = 0;
	virtual list<T> *sortBubbly () = 0;

private:
	void trIndex (int flatIndex, int curCount, int curDim, int *index) const {
		if (flatIndex <= 0)
			return;
		curCount /= dimensions [curDim - 1];
		int idx = flatIndex / curCount;
		flatIndex -= curCount * idx;
		index [curDim - 1] = idx;
		trIndex (flatIndex, curCount, curDim + 1, index);
	}
	
	const int * const dimensions;
	int numOfDims;
};

#endif
