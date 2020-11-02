#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

using namespace std;

template <class T>
class Heap {
private:
	T *data;

  unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;

	unsigned int count;
	unsigned int internalSize;
  
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);


public:
	Heap(unsigned int) throw  (OutOfMemory);
	~Heap();


	bool empty() const; 
	bool full() const; 
	
  
  void push(T) throw (Overflow);
  void pop() throw (NoSuchElement);
	void clear();

  T top() throw (NoSuchElement);  
  
  int size(); //no confundir con internalSize
	
  string toString() const;
};

//Constructor
template <class T> Heap<T>::Heap(unsigned int sze) throw (OutOfMemory) {
	internalSize = sze;
	data = new T[internalSize];
	if (data == 0) 		throw OutOfMemory();
	
	count = 0;
}

//Destructor
template <class T>Heap<T>::~Heap() {
	delete [] data; data = 0;
	internalSize = 0; count = 0;
}

// O(1) 
template <class T>  int Heap<T>:: size() {
  int tamanio = count;
  return tamanio;
}

// o(1)
template <class T> bool Heap<T>::empty() const {
	return (count == 0);
}


// O(1)
template <class T> bool Heap<T>::full() const {
	return (count == internalSize);
}


// o(1)
template <class T> unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}


// o(1)
template <class T> unsigned int Heap<T>::left(unsigned int pos) const {
	return ((pos*2) + 1);
}


//O(1)
template <class T> unsigned int Heap<T>::right(unsigned int pos) const {
	return ((pos*2) + 2);
}



//o(1)
template <class T> void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}


//o(log n)
template <class T> void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le <= count && data[le] < data[min]) 		min = le;
	
	if (ri <= count && data[ri] < data[min]) 		min = ri;
	
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}



// o(log n)
template <class T> void Heap<T>::push(T val) throw (Overflow) {
	unsigned int pos;
	if (full()) 		throw Overflow();
	
	pos = count;
	count++;
	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}


//o(1)
template <class T> T Heap<T>::top() throw (NoSuchElement) {
	if (empty()) 		throw NoSuchElement();
	
	return data[0];

}



// o(log n)
template <class T> void Heap<T>::pop() throw (NoSuchElement) {
	if (empty()) 		throw NoSuchElement();
	
	T aux = data[0];
	data[0] = data[--count];
	heapify(0);
}


// o(1)
template <class T> void Heap<T>::clear() {
	count = 0;
}

// o(1)
template <class T> string Heap<T>::toString() const {
	stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}

#endif 