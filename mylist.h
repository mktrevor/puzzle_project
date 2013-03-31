/** A templated, dynamic unbounded list to hold data of any type

	@author Trevor Reed
*/

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T> class MyList{
	public:
		MyList();
		~MyList();
		int size();
		void push_back(T item);
		T& at(int loc);
		T& operator[](int loc);
		bool remove(T val);
		void clear();
	
	private:
		/**Pointer to array of data*/
		T* data_;
		/**Size of list*/
		int size_;
		/**Current capacity of list*/
		int capacity_;
};

/** Default constructor for MyList. Sets the initial capacity to 2.
	@param None
	@return None
*/
template <typename T> MyList<T>::MyList() {
	size_ = 0;
	capacity_ = 2;
	data_ = new T[2];
}

/** Destructor - deletes the array of data. */
template <typename T> MyList<T>::~MyList() {
	delete [] data_;
}

/** Returns size of data list
	@param None
	@return Size of data list
*/
template <typename T> int MyList<T>::size() { //Returns the size of the list.
	return size_;
}

/** Adds new data member to back of the list. If the list is at full capacity, new memory is allocated, and its capacity is doubled.
	@param Value of item
	@return None
*/
template <typename T> void MyList<T>::push_back(T item) { //Adds a new item to the back of the list, allocating more memory if needed.
	if(size_ == capacity_) {
		T* newData = new T[size_*2];
		
		for(int i = 0; i < size_; i++) {
			newData[i] = data_[i];
		}
		
		delete [] data_;
		
		data_ = newData;
		
		capacity_ *= 2;
		
		data_[size_] = item;
		
		size_++;
		
		return;
	}
	
	data_[size_] = item;
	size_++;
}

/** Returns the value of item at a certain location in the list
	@param Position
	@return Value of data member at position
*/
template <typename T> T& MyList<T>::at(int loc) { //Returns the value at a certain location in the list.

	if(loc < 0 || loc >= size_) {
		throw invalid_argument("Trying to perform at() at invalid location");
	}

	return data_[loc];
}

/** Overloads [] operator to perform at(int loc)
	@param Position
	@return Value of data member at position
*/
template <typename T> T& MyList<T>::operator[](int loc) {
	return at(loc);
}

/** Removes the first instance of a certain value from the list
	@param Value of item to be removed
	@return Whether or not item was found and removed
*/
template <typename T> bool MyList<T>::remove(T val) { //Removes the first instance of a value in the list.
	for(int i = 0; i < size_; i++) {
		if(data_[i] == val) {
			for(int j = i; j < size_; j++) {
				data_[j] = data_[j+1];
			}
			size_--;
			return 1;
		}
	}
	return 0;
}

/** Deallocates memory from the list
	@param None
	@return None
*/
template <typename T> void MyList<T>::clear() {
	delete [] data_;
}

#endif
