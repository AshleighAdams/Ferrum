#pragma once
#ifndef REF_CLASS_H
#define REF_CLASS_H

class Immutable
{
public:
	virtual ~Immutable(){}
	void Refrence()
	{
		_RefrenceCount++;
	}
	void UnRefrence()
	{
		_RefrenceCount--;
		if( this->_RefrenceCount == 0)
			delete this;
	}
protected:
	unsigned int _RefrenceCount;
};

#endif // REF_CLASS_H
