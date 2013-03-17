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
		T* data_;
		int size_;
		int capacity_;
};

template <typename T> MyList<T>::MyList() {
	size_ = 0;
	capacity_ = 2;
	data_ = new T[2];
}

template <typename T> MyList<T>::~MyList() {
	delete [] data_;
}

template <typename T> int MyList<T>::size() { //Returns the size of the list.
	return size_;
}

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

template <typename T> T& MyList<T>::at(int loc) { //Returns the value at a certain location in the list.

	if(loc < 0 || loc >= size_) {
		throw invalid_argument("Trying to perform at() at invalid location");
	}

	return data_[loc];
}

template <typename T> T& MyList<T>::operator[](int loc) {
	return at(loc);
}

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

template <typename T> void MyList<T>::clear() {
	delete [] data_;
}

#endif
