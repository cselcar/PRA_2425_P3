#ifndef LIST_H
#define LIST_H

using namespace std;

template <typename T> 
class List {	
public:
	virtual void insert(int pos, T e)=0;
	virtual void append(T e)=0;
	virtual void prepend(T e) =0;
	virtual T remove(int pos)=0;
	virtual T get(int pos)=0;
	virtual int search(T e)=0;
	virtual bool empty()=0;
	virtual int size()=0;
};

#endif
