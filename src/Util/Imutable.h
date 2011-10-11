#pragma once
#ifndef REF_CLASS_H
#define REF_CLASS_H

class Immutable
{
public:
	virtual ~Immutable(){}
	void Ref()
	{
		_RefCount++;
	}
	void Unref()
	{
		_RefCount--;
		if( this->_RefCount == 0)
			delete this;
	}
protected:
	unsigned int _RefCount;
};

#endif // REF_CLASS_H
