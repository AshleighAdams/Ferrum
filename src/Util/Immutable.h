#pragma once
#ifndef REF_CLASS_H
#define REF_CLASS_H

/// An immutable value that can be freely used by any other objects. This implements reference
/// counting to keep track of the number of places it is used in.
class Immutable
{
public:
	virtual ~Immutable()
	{
		
	}
	
	void Ref()
	{
		this->_RefCount++;
	}
	
	void Unref()
	{
		this->_RefCount--;
		if(this->_RefCount == 0)
			delete this;
	}
	
private:
	unsigned int _RefCount;
};

/// A reference to an immutable value that automatically handles reference counting.
template <class T>
class Ref
{
public:

	T& operator*()
	{
		return *(this->_Ptr);
	}
	
    T* operator->()
    {
    	return this->_Ptr;
    }

private:
	Immutable* _Ptr;
};


#endif // REF_CLASS_H
